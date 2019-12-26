#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_checkWeaponHasTripod

Description:
	Checks current primary weapon has MG tripod attached (tripod is item lsited in dzn_MG_Tripod_TripodClasses array)

Parameters:
	_unit -- unit (player) <OBJECT>

Returns:
	_hasTripod -- current primary weapon has tripod <BOOL>


Examples:
    (begin example)
		_hasTripod = [player] call dzn_MG_Tripod_fnc_checkWeaponHasTripod;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit"];

private _bipodItem = primaryWeaponItems _unit # 3;
if (_bipodItem == "") exitWith { false };

private _tripods = GVAR(Cache) getVariable SVAR(TripodClasses);

(_tripods findIf { _x == _bipodItem } > -1)