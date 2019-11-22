/*
	0) Add `dzn_MGTripod_deployedGesture` property to weapon class 

	1) Add "loadout" or "weapon" CBA EH
	https://github.com/CBATeam/CBA_A3/wiki/Player-Events

	1.1) If primaryWeapon has `dzn_MGTripod_deployedGesture` prop -> add `Deployed EH` and `Reload EH`
	1.2) If primaryWeapon has no `dzn_MGTripod_deployedGesture` prop -> remove `Deployed EH` and `Reload EH`
	
	2) On `Deployed EH`:
		If (curWeap != priWeap) exit {}
		If deployed: 
			set unit variable `deployedGesture` to (getText (configFile >> "CfgWeapons" >> _w >> "dzn_MGTripod_deployedGesture"))
			playAction deployedGesture
			
		If not deploayed
			playAction "gestureNod"
			
	3) On `Reload EH`:
		If (curWeap != priWeap) exit {}
		If (getVariable `deployedGestureSwitched` == false) exit {}
		If isWeaponDeployed:
			playAction deployedGesture
		
		
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
COMPILE_FUNCTION(fnc_getWeaponDeployGesture);
COMPILE_FUNCTION(fnc_checkWeaponHasTripod);
COMPILE_FUNCTION(fnc_checkWeaponHasDeployGesture);
COMPILE_FUNCTION(fnc_affectWeapon);

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

