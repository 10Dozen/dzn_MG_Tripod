#include "macro.hpp"

call compile preprocessFileLineNumbers format ["%1\Settings.sqf", PATH];

// Exit at dedicated or headless client
if (!hasInterface) exitWith {};

GVAR(TripodClasses) = [
	"dzn_tripod_mg_nato"
];

// Functions
GVAR(fnc_isTripodInstalled) = {
	private _items = primaryWeaponItems player;
	private _isAttached = (true) in (_items apply { _x in GVAR(TripodClasses) });
	//{ _x } count (_items apply { _x in GVAR(TripodClasses) }) > 0;
	
	if !(_isAttached) exitWith { false };
	
	true
};

GVAR(fnc_affectSway) = {
	params ["_decrease"];
	
	private _aimCoef = GVAR(DeployedAimCoef);
	private _recoilCoef = GVAR(DeployedRecoilCoef);
	
	if (_decrease) then { 
		// Deployed case - save current sway/recoil values
		player setVariable ["dzn_MG_Tripod_aimCoef", getCustomAimCoef player];
		player setVariable ["dzn_MG_Tripod_recoilCoef", unitRecoilCoefficient player];
		player setVariable ["dzn_MG_Tripod_deployTime", round(time)];
	} else {
		// Undeployed: 
		if ( (player getVariable ["dzn_MG_Tripod_deployTime",0]) - round(time) > 60 ) then {
			// if more than 60 seconds passed - restore coefficient as defaults (player got a rest)
			_aimCoef = 1;
			_recoilCoef = 1;
		} else {
			// or restore saved sway/recoil coefficients
			_aimCoef = player getVariable "dzn_MG_Tripod_recoilCoef";
			_recoilCoef = player getVariable "dzn_MG_Tripod_recoilCoef";
		};		
	};
	
	player setCustomAimCoef _aimCoef;
	player setUnitRecoilCoefficient _recoilCoef;
};

GVAR(fnc_addDeployEH) = {
	if !(isNil { player getVariable "dzn_MG_Tripod_EH" }) then {
		player removeEventHandler ["WeaponDeployed", player getVariable "dzn_MG_Tripod_EH"];
	};

	player setVariable ["dzn_MG_Tripod_EH", 
		player addEventHandler ["WeaponDeployed", {
			params ["_unit", "_isDeployed"];
			
			if !(GVAR(Enabled)) exitWith {};			
			if !(call GVAR(fnc_isTripodInstalled)) exitWith {};			
			[_isDeployed] call GVAR(fnc_affectSway);			
		}]
	];
};


// Init
[] spawn {
	waitUntil { time > 5 && local player && GVAR(Enabled) };
	[] call GVAR(fnc_addDeployEH);
};
