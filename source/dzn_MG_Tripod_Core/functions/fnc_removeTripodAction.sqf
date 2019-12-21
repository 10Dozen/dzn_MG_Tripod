#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_removeTripodAction

Description:
	Removes tripod action stored in given variable and clears assosiated variable

Parameters:
	_unit -- unit to apply (player) <OBJECT>
	_actionVarName -- action varname (variable where actionId is stored) <STRING>

Returns:
	nothing

Examples:
    (begin example)
		_actionID = [player, "dzn_MG_Tripod_ActionC2A"] call dzn_MG_Tripod_fnc_removeTripodAction;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_actionVarName"];

private _actionId = _unit getVariable [_actionVarName, -1];
if (_actionId < 0) exitWith {};

_unit removeAction _actionId;
_unit setVariable [_actionVarName, -1];