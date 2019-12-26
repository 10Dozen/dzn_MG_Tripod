#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_getWeaponDeployGestures

Description:
	Return gesture data (list of gestures name, has in-built bipod) for given weapon (from cache or from config)

Parameters:
	_weapon -- weapon class to check <STRING>
	_useCacheOnly -- (optional) flag to use only cached value (default: true) <BOOL>

Returns:
	_gestureData -- array of gesture data assosiated with weapon [animation gesture name, has in-built bipod] <ARRAY>

Examples:
    (begin example)
		_gestureData = [_weapon, true] call dzn_MG_Tripod_fnc_getWeaponDeployGestures;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params [["_weapon",""], ["_useCacheOnly", true]];

if (_weapon == "") exitWith { "" };

if (!_useCacheOnly) then {
	// --- Triggers cache creation
	[_weapon] call GVAR(fnc_checkWeaponHasDeployGestures);
};
	
private _gestureData = (GVAR(Cache) getVariable [_weapon, [false, "", false]]);

[_gestureData # 1, _gestureData # 2]