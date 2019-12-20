/*
	TODO:
		- Play animation on Mounting / Dismounting
		- Handle removing attach from weapon and convert to launcher
		
		- Remove Logging
		
*/

/*
	Assumptions:
		- All MGs compatible with tripod MUST HAVE `dzn_MGTripod_deployedGesture` property
		- MG with `dzn_MGTripod_deployedGesture` property MAY BE compatible with tripods (means some MGs with deployedGesture, are not compatible with tripods)

*/
#include "macro.hpp"

// Exit at dedicated or headless client
if (!hasInterface) exitWith {};

GVAR(Cache) = call CBA_fnc_createNamespace;
GVAR(Cache) setVariable [
	SVAR(TripodClasses)
	, getArray (configFile >> "CfgPatches" >> "dzn_MG_Tripod_Core" >> "weapons")
];

// Functions
COMPILE_FUNCTION(fnc_handleLoadoutEH);
COMPILE_FUNCTION(fnc_handleReloadedEH);
COMPILE_FUNCTION(fnc_handleDeployedEH);
COMPILE_FUNCTION(fnc_handleCarryItemExchange);
COMPILE_FUNCTION(fnc_checkWeaponHasTripod);
COMPILE_FUNCTION(fnc_affectWeapon);
COMPILE_FUNCTION(fnc_uiHandleInventory);

COMPILE_FUNCTION(fnc_getWeaponDeployGestures);
COMPILE_FUNCTION(fnc_checkWeaponHasDeployGestures);
COMPILE_FUNCTION(fnc_selectGesture);

GVAR(fnc_addEHs) = {
	private _ehId = player getVariable [SVAR(LoadoutEH), -1];
	if (_ehId >= 0) then {
		["loadout", _ehId] call CBA_fnc_removePlayerEventHandler;
	};
	
	_ehId = ["loadout", GVAR(fnc_handleLoadoutEH), true] call CBA_fnc_addPlayerEventHandler;
	player setVariable [SVAR(LoadoutEH), _ehId];
};

// Init
[] call GVAR(fnc_addEHs);

