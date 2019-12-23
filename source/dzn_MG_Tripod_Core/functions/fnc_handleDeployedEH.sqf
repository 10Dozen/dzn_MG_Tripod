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

// --- Skip anim changes if player is in reload sequence
if (_unit getVariable [SVAR(ReloadInProgress), false]) exitWith {};

private _weapon = primaryWeapon _unit;
if (_weapon != currentWeapon _unit) exitWith {};

private _isGesturesEnabled = GVAR(Enabled_ProneGesture) || { GVAR(Enabled_CrouchGesture) || GVAR(Enabled_StandGesture) };

if (
	_isGesturesEnabled
	&& { [_weapon] call GVAR(fnc_checkWeaponHasDeployGestures) }
) then {
	if (_isDeployed) then {
		private _gesture = [_unit, _weapon] call GVAR(fnc_selectGesture);
		if (_gesture != "") then {
			_unit playAction _gesture;
			_unit setVariable [SVAR(HoldGestureApplied), true];
		};
	} else {
		// --- Play reverting action only if hold gesture were applied
		if (_unit getVariable [SVAR(HoldGestureApplied), false]) then {
			_unit playAction "gestureNod";
			_unit setVariable [SVAR(HoldGestureApplied), false];
		};
	};
};

// --- Tripod effects
if (
	GVAR(Enabled)
	&& { [_unit] call GVAR(fnc_checkWeaponHasTripod) }
) then {
	[_isDeployed] call GVAR(fnc_affectWeapon);
};