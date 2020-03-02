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

private _weapon = currentWeapon _unit;
private _isGestureEnabled = GVAR(Enabled_StandGesture) || GVAR(Enabled_CrouchGesture) || GVAR(Enabled_ProneGesture);

if (
	_isGestureEnabled
	&& _isDeployed
	&& { [_weapon] call GVAR(fnc_checkWeaponHasDeployGestures) }
) then {
	private _guesture = [_unit, _weapon] call GVAR(fnc_selectGesture);
	_unit playAction _guesture;
	_unit setVariable [SVAR(GestureApplied),true];
} else {
	if (_unit getVariable [SVAR(GestureApplied),false]) then {
		_unit playAction "gestureNod";
		_unit setVariable [SVAR(GestureApplied),false];
	};
};

// --- Tripod effects
if (
	GVAR(Enabled)
	&& { [_unit] call GVAR(fnc_checkWeaponHasTripod) }
) then {
	[_isDeployed] call GVAR(fnc_affectWeapon);
};
