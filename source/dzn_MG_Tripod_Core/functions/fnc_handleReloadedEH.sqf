#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleReloadedEH

Description:
	Handle Reloaded event (weapon reloaded): 
	re-adds animation switch if weapon still deployed

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

// --- Re-set reload in progress flag
_unit setVariable [SVAR(ReloadInProgress), nil];

private _isGesturesEnabled = GVAR(Enabled_ProneGesture) || { GVAR(Enabled_CrouchGesture) || GVAR(Enabled_StandGesture) };

if (
	_isGesturesEnabled
	&& isWeaponDeployed _unit
	&& { [_weapon] call GVAR(fnc_checkWeaponHasDeployGestures) }
) then {
	private _gesture = [_unit, _weapon] call GVAR(fnc_selectGesture);
	if (_gesture != "") then {
		_unit playAction _gesture;
		_unit setVariable [SVAR(HoldGestureApplied), true];
	};
};
