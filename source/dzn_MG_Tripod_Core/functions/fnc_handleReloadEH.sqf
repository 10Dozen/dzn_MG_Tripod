#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleReloadEH

Description:
	Handle Reload event (weapon reload started): 
	marks reload process for Deployed EH to prevent unwanted anim switch.

Parameters:
	_unit -- unit (player) <OBJECT>
	_reloadedWeapon -- reloaded weapon class <STRING>
	and other Reloaded EH data...

Returns:
	nothing

Examples:
    (begin example)
		// Called from Config Event handler
		...
		class EventHandlers: EventHandlers 
		{
			relaod = "_this call dzn_MG_Tripod_fnc_handleReloadEH";
		}
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

params ["_unit", "_reloadedWeapon"];

if (_reloadedWeapon != primaryWeapon _unit) exitWith {};

if (_unit getVariable [SVAR(HoldGestureApplied), false]) then {
	
	_unit setVariable [SVAR(ReloadInProgress), true];
	// --- Reloading animation automatically drops hold gesture
	_unit setVariable [SVAR(HoldGestureApplied), false];
};