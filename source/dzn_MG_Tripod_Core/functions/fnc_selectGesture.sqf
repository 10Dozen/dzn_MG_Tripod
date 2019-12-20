#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_selectGesture

Description:
	Returns hold gesture for given weapon and player stance.
	If no gestures available: returns ""

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

private _gestures = [_weapon] call GVAR(fnc_getWeaponDeployGestures);
if (_gestures isEqualTo []) exitWith { "" };

private _stance = toUpper(stance _unit);
private _stancesToCheck = [
	if (GVAR(Enabled_StandGesture)) then { "STAND" } else { "" }
	, if (GVAR(Enabled_CrouchGesture)) then { "CROUCH" } else { "" }
	, if (GVAR(Enabled_ProneGesture)) then { "PRONE" } else { "" }
];

private _index = (_stancesToCheck findIf { _x == _stance });
if (_index < 0) exitWith { "" };

(_gestures # _index)