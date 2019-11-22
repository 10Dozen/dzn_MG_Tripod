#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_affectWeapon

Description:
	Checks current primary weapon has MG tripod attached (tripod is item lsited in dzn_MGTripod_TripodClasses array)

Parameters:
	_affect -- affect weapon sway and recoil <BOOL>

Returns:
	nothing

Examples:
    (begin example)
		_hasTripod = [true] call dzn_MG_Tripod_fnc_affectWeapon;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_affect"];
	
private _aimCoef = GVAR(DeployedAimCoef);
private _recoilCoef = GVAR(DeployedRecoilCoef);
	
if (_affect) then { 
	// Deployed case - save current sway/recoil values
	player setVariable [SVAR(aimCoef), getCustomAimCoef player];
	player setVariable [SVAR(recoilCoef), unitRecoilCoefficient player];
	player setVariable [SVAR(deployTime), round(time)];
	
} else {
	// Undeployed: 
	if ( (player getVariable [SVAR(deployTime),0]) - round(time) > 60 ) then {
		// if more than 60 seconds passed - restore coefficient as defaults (player got a rest)
		_aimCoef = 1;
		_recoilCoef = 1;
	} else {
		// or restore saved sway/recoil coefficients
		_aimCoef = player getVariable SVAR(aimCoef);
		_recoilCoef = player getVariable SVAR(recoilCoef);
	};		
	
};
	
player setCustomAimCoef _aimCoef;
player setUnitRecoilCoefficient _recoilCoef;