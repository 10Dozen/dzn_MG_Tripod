#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_checkWeaponHasDeployGestures

Description:
	Checks is weapon needs animation switch once deployed. Also caches data.

Parameters:
	_weapon -- weapon class to check <STRING>

Returns:
	_isDeployable -- weapon requires animation switch <BOOL>


Examples:
    (begin example)
		_isDeployable = [_weapon] call dzn_MG_Tripod_fnc_checkWeaponHasDeployGestures;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_weapon"];

private _gestureCached = GVAR(Cache) getVariable [_weapon, nil];
private _hasGesture = false;

if (isNil "_gestureCached") then {
	private _gesture = getArray (configFile >> "CfgWeapons" >> _weapon >> "dzn_MG_Tripod_deployedGesture");
	_hasGesture = !(_gesture isEqualTo []);
	
	GVAR(Cache) setVariable [_weapon, [_hasGesture, _gesture]];
} else {
	_hasGesture = _gestureCached # 0;
};

_hasGesture