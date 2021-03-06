#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_selectGesture

Description:
	Returns hold gesture for given weapon and player stance or "" if not available.
	Conditions are:
	- There deploy gestures defined in weapon config
	- Weapon has hasBipod=1 defined in weapon config OR weapon has attached bipod item

Parameters:
	_unit -- unit (player) <OBJECT>
	_weapon -- weapon classname to check <STRING>

Returns:
	_gesture -- name of appropriate gesture <STRING>

Examples:
    (begin example)
		_gesture = [player, primaryWeapon player] call dzn_MG_Tripod_fnc_selectGesture;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_weapon"];

([_weapon] call GVAR(fnc_getWeaponDeployGestures)) params ["_gestures", "_hasBipod"]; // [ ["","","dzn_MG_Tripod_GestureHoldProneType1"],  false]

// --- Exit if no gestures defined at all
if (_gestures isEqualTo []) exitWith { "" };

if (!_hasBipod) then {
	// --- Check for attached bipod
	private _attachedBipodItem = ((primaryWeaponItems _unit) # 3);

	if (_attachedBipodItem != "") then {
		// --- Check that item in bipod slot is actual bipod (e.g. RHS grips)
		_hasBipod = (getNumber (configFile >> "CfgWeapons" >> ((primaryWeaponItems _unit) # 3) >> "ItemInfo" >> "hasBipod")) == 1;
	};
};

if !(_hasBipod) exitWith { "" };

// --- Select gesture by unit's stance
private _stance = toUpper(stance _unit);
private _stancesToCheck = [
	if (GVAR(Enabled_StandGesture)) then { "STAND" } else { "" }
	, if (GVAR(Enabled_CrouchGesture)) then { "CROUCH" } else { "" }
	, if (GVAR(Enabled_ProneGesture)) then { "PRONE" } else { "" }
];

private _index = (_stancesToCheck findIf { _x == _stance });
if (_index < 0) exitWith { "" };

(_gestures # _index)