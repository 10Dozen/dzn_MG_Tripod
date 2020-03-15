#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_getPreferredCarryOption

Description:
	Returns carry item option depending on previously used carry item, addon setting and attach item properties.

Parameters:
	_attachItem -- attach item classname <STRING>
	_usedCarryItem -- carry item classname that was used to install attach (may be "" if source is unknown) <STRING>

Returns:
	_carryItem -- classname of carry item (packed tripod), "" if none <STRING>

Examples:
    (begin example)
		_carryItem = [_attachItem, _usedCarryItem] call dzn_MG_Tripod_fnc_getPreferredCarryOption;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_attachItem","_usedCarryItem"];

private _carryOptions = GVAR(CompatibleItemsCache) getVariable [_attachItem, []];
if (_carryOptions isEqualTo []) then {
	_carryOptions = [
		getText (configFile >> "CfgWeapons" >> _attachItem >> "dzn_MG_Tripod_CarryItem"),
		getText (configFile >> "CfgWeapons" >> _attachItem >> "dzn_MG_Tripod_CarryItemUniversal")
	];
	GVAR(CompatibleItemsCache) setVariable [_attachItem, _carryOptions];
};

private _carryItem = _carryOptions select GVAR(FallbackToUniversal);
if (_usedCarryItem != "" && { _carryOptions findIf {_x == _usedCarryItem} > -1 }) then {
	_carryItem = _usedCarryItem;
};

_carryItem
