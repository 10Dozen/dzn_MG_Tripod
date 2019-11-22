#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleReloadedEH

Description:
	Handle Reload event: re-add animation switch if applied

Parameters:
	_unit -- unit (player) <OBJECT>
	_reloadedWeapon -- reloaded weapon class <STRING>
	and other Reloaded EH data...

Returns:
	nothing

Examples:
    (begin example)
		player addEventHandler [
			"Reloaded"
			, { _this call dzn_MG_Tripod_fnc_handleReloadedEH }
		];
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_reloadedWeapon"];

private _weapon = primaryWeapon _unit;
if (_weapon != _reloadedWeapon) exitWith {};

if (
	GVAR(Enabled_Gesture) 
	&& { 
		[_weapon] call GVAR(fnc_checkWeaponHasDeployGesture) 
		&& isWeaponDeployed _unit
	}
) then {
hint "Re-apply animation...";
	_unit playAction "CUP_GestureHoldPK"; // ([_weapon] call GVAR(fnc_getWeaponDeployGesture));
};
