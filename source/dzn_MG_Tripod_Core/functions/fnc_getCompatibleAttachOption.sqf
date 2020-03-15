#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_getCompatibleAttachOption

Description:
	Returns attach item compatible to given weapon from Carry item options.

Parameters:
	_weapon -- weapon classname to check <STRING>
	_carryItem -- carry item (folded tripod) classname <STRING>

Returns:
	_attachItem -- classname of attach item (deployed tripod), "" if none <STRING>

Examples:
    (begin example)
		_attachItem = [primaryWeapon player, secondaryWeapon player] call dzn_MG_Tripod_fnc_getCompatibleAttachOption;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_weapon", "_carryItem"];

private _cachedName = format ["%1__%2",_weapon,_carryItem];
private _compatibleItems = GVAR(CompatibleItemsCache) getVariable [_cachedName, nil];
if (isNil "_compatibleItems") then {
	private _attachOptions = getArray(configFile >> "CfgWeapons" >> _carryItem >> "dzn_MG_Tripod_AttachItems");
	private _weaponCompatibleItems = [_weapon, "bipod"] call CBA_fnc_compatibleItems;
	_compatibleItems = [];
	{
		private _attach = _x;
		private _compatibleItemIdx = _weaponCompatibleItems findIf { _x == _attach };
		if (_compatibleItemIdx > -1) then {
			_compatibleItems pushBack (_weaponCompatibleItems # _compatibleItemIdx);
		};
	} forEach _attachOptions;

	GVAR(CompatibleItemsCache) setVariable [_cachedName, _compatibleItems];
};

if (_compatibleItems isEqualTo []) exitWith { "" };

(_compatibleItems # 0)
