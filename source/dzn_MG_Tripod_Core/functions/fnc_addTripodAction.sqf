#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_addTripodAction

Description:
	Adds action with given data and default condition: 
		- not in vehicle
 		- current weapon is primary weapon
	And stores action id in unit's namespace under given name.
	If given actionVarName exists and stored value > -1 -- throws error.

Parameters:
	_unit -- unit to apply (player) <OBJECT>
	_actionVarName -- variable name to store action ID <STRING>
	_title -- localized title for action (string with placeholder for item name) <STRING>
	_item -- item classname <STRING>
	_code -- action code <CODE>

Returns:
	nothing

Examples:
    (begin example)
		[
			player
			, "dzn_MG_Tripod_ActionC2A"
			, localize "STR_Mounttripod"
			, secondaryWeapon player
			, _actionMountCode
		] call dzn_MG_Tripod_fnc_addTripodAction;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_actionVarName", "_title", "_item", "_code"];

private _actionId = _unit getVariable [_actionVarName, -1];
if (_actionId > -1) exitWith {
	["There is Tripod Action exists in (%1) variable", _actionVarName] call BIS_fnc_error;
};

_actionId = _unit addAction [
	format [_title, getText (configFile >> "CfgWeapons" >> _item >> "displayName")]
	, _code
	, []
	, 1.5
	, false
	, true
	, ""
	, "currentWeapon _this == primaryWeapon _this && vehicle _this == _this"
];

_unit setVariable [_actionVarName, _actionId];