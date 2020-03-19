#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleTripodActions

Description:
	Handles Tripod attach/detach actions addition/removing.

Parameters:
	_mode -- function call mode: ADD, REMOVE, UPDATE <STRING>
	_payload -- function payload <ARRAY>

Returns:
	nothing

Examples:
    (begin example)
	["ADD",[
		player
		, "dzn_MG_Tripod_ActionC2A"
		, localize "STR_Mounttripod"
		, secondaryWeapon player
		, _actionMountCode
	]] call dzn_MG_Tripod_fnc_handleTripodActions;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_mode", ["_payload", []]];

#define FORMAT_NAME(T,X) format [T, getText (configFile >> "CfgWeapons" >> X >> "displayName")]

switch (toUpper _mode) do {
	case "ADD": {
		_payload params ["_unit","_actionVarName","_title","_item","_statement"];

		private _actionId = _unit getVariable [_actionVarName, -1];
		if (_actionId > -1) exitWith {
			["There is Tripod Action exists in (%1) variable", _actionVarName] call BIS_fnc_error;
		};

		_actionId = _unit addAction [
			FORMAT_NAME(_title,_item)
			, _statement
			, []
			, 1.5
			, false
			, true
			, ""
			, "currentWeapon _this == primaryWeapon _this && vehicle _this == _this"
		];

		_unit setVariable [_actionVarName, _actionId];
	};
	case "REMOVE": {
		_payload params ["_unit","_actionVarName"];

		private _actionId = _unit getVariable [_actionVarName, -1];
		if (_actionId < 0) exitWith {};

		_unit removeAction _actionId;
		_unit setVariable [_actionVarName, -1];
	};
	case "UPDATE": {
		_payload params ["_unit","_actionVarName","_title","_item"];
		private _actionId = _unit getVariable [_actionVarName, -1];
		if (_actionId < 0) exitWith {};

		_unit setUserActionText [_actionId, FORMAT_NAME(_title,_item)];
	};
};
