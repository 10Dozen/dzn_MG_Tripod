#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleDeployedEH

Description:
	Handle Deployed event: apply animation switch and affect weapon if tripod used. 

Parameters:
	_unit -- unit (player) <OBJECT>
	_isDeployed -- selected weapon class <STRING>

Returns:
	nothing


Examples:
    (begin example)
		player addEventHandler [
			"WeaponDeployed"
			, { _this call dzn_MG_Tripod_fnc_handleDeployedEH }
		];
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_isDeployed"];

private _weapon = primaryWeapon _unit;
if (_weapon != currentWeapon _unit) exitWith {};

if (
	GVAR(Enabled_Gesture) 
	&& { [_weapon] call GVAR(fnc_checkWeaponHasDeployGesture) }
) then {
	if (_isDeployed) then {
		hint "Deployed: Apply Gesture animation...";
		
		private _gestures = [_weapon] call GVAR(fnc_getWeaponDeployGesture);
		private _gestureIndex = if (stance player == "PRONE") then { 1 } else { 0 };

		_unit playAction (_gestures # _gestureIndex);
	} else {
		hint "Undeployed: Cancel animation...";
		_unit playAction "gestureNod";
	};
};

// --- Tripod effects
if (
	GVAR(Enabled)
	&& { [_unit] call GVAR(fnc_checkWeaponHasTripod) }
) then {
	[_isDeployed] call GVAR(fnc_affectWeapon);
};