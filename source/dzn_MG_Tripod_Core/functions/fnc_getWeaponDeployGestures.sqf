#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_getWeaponDeployGestures

Description:
	Return gesture name for given weapon (from cache or from config)

Parameters:
	_weapon -- weapon class to check <STRING>
	_useCacheOnly -- (optional) flag to use only cached value (default: true) <BOOL>

Returns:
	_gestureName -- animation gesture name assosiated with weapon <STRING>

Examples:
    (begin example)
		_gesture = [_weapon, true] call dzn_MG_Tripod_fnc_getWeaponDeployGestures;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_weapon", ["_useCacheOnly", true]];

if (!_useCacheOnly) then {
	// --- Trigger cache creation
	[_weapon] call GVAR(fnc_checkWeaponHasDeployGestures);
};
	
private _gesture = (GVAR(Cache) getVariable [_weapon, [false, ""]]) # 1;

_gesture