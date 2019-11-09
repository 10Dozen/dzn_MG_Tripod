#include "macro.hpp"

// Exit at dedicated or headless client
if (!hasInterface) exitWith {};

GVAR(TripodClasses) = getArray (configFile >> "CfgPatches" >> "dzn_MG_Tripod" >> "weapons");
// ["dzn_tripod_mg_nato","dzn_tripod_mg_nato_m240mount","dzn_tripod_mg_nato_m60mount"];

// Functions
GVAR(fnc_isTripodInstalled) = {
    private _items = primaryWeaponItems player;

    (_items findIf { _x in GVAR(TripodClasses) } > 0)
};

GVAR(fnc_affectSway) = {
	params ["_decrease"];
	
	private _aimCoef = GVAR(DeployedAimCoef);
	private _recoilCoef = GVAR(DeployedRecoilCoef);
	
	if (_decrease) then { 
		// Deployed case - save current sway/recoil values
		player setVariable [SVAR(aimCoef), getCustomAimCoef player];
		player setVariable [SVAR(recoilCoef), unitRecoilCoefficient player];
		player setVariable [SVAR(deployTime), round(time)];
	} else {
		// Undeployed: 
		if ( (player getVariable [SVAR(deployTime),0]) - round(time) > 60 ) then {
			// if more than 60 seconds passed - restore coefficient as defaults (player got a rest)
			_aimCoef = 1;
			_recoilCoef = 1;
		} else {
			// or restore saved sway/recoil coefficients
			_aimCoef = player getVariable SVAR(aimCoef);
			_recoilCoef = player getVariable SVAR(recoilCoef);
		};		
	};
	
	player setCustomAimCoef _aimCoef;
	player setUnitRecoilCoefficient _recoilCoef;
};

GVAR(fnc_addDeployEH) = {
	if !(isNil { player getVariable SVAR(EH) }) then {
		player removeEventHandler ["WeaponDeployed", player getVariable SVAR(EH)];
	};

	player setVariable [
		SVAR(EH), 
		player addEventHandler [
			"WeaponDeployed"
			,{
				params ["_unit", "_isDeployed"];
				
				if !(GVAR(Enabled)) exitWith {};			
				if !(call GVAR(fnc_isTripodInstalled)) exitWith {};			
				[_isDeployed] call GVAR(fnc_affectSway);			
			}
		]
	];
};


// Init
[] call GVAR(fnc_addDeployEH);
