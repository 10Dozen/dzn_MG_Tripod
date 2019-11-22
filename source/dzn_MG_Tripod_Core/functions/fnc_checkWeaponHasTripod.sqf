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

private _items = primaryWeaponItems _unit;
private _tripods = GVAR(Cache) getVariable SVAR(TripodClasses);

(_items findIf { _x in _tripods } > 0)