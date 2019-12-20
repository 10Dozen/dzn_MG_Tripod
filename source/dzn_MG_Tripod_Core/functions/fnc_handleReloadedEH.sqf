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

private _isGestureEnabled = GVAR(Enabled_StandGesture) || GVAR(Enabled_CrouchGesture) || GVAR(Enabled_ProneGesture);

if (
	_isGestureEnabled
	&& { 
		isWeaponDeployed _unit
		&& [_weapon] call GVAR(fnc_checkWeaponHasDeployGestures) 
	}
) then {	
	private _guesture = [_unit, _weapon] call GVAR(fnc_selectGesture);
	_unit playAction _guesture;
};
