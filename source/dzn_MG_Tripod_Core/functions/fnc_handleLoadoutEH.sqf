#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleLoadoutEH

Description:
	Handles Loadout event: 
		- Verifies that player has primary weapon is compatible with tripods and has gesture anim
		- Add or remove Deployed & Reloaded EHs if needed
	
	Assumptions:
		- All MGs compatible with tripod MUST HAVE `dzn_MGTripod_deployedGesture` property
		- MG with `dzn_MGTripod_deployedGesture` property MAY BE compatible with tripods (means some MGs with deployedGesture, are not compatible with tripods)
		- Deployed handlers added ONLY if weapon has `dzn_MGTripod_deployedGesture` property and removed if not

Parameters:
	_unit -- unit (player) <OBJECT>
	_newLoadout -- actual unit loadout <ARRAY>

Returns:
	nothing

Examples:
    (begin example)
		[
			"loadout"
			, { _this call dzn_MG_Tripod_fnc_handleLoadoutEH }
			, true
		] call CBA_fnc_addPlayerEventHandler;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

/**
	TODO:
		- [bug] actions added each time loadout changed!

 */

params ["_unit", "_newLoadout"];

private _fnc_removeAction = {
	params ["_unit", "_actionName"];
	_unit removeAction (_unit getVariable _actionName);
	_unit setVariable [_actionName, -1];
};

private _w = _newLoadout # 0 # 0;
private _sw = if (_newLoadout # 1 isEqualTo []) then { "" } else { _newLoadout # 1 # 0 };

private _hasGesture 		= [_w] call GVAR(fnc_checkWeaponHasDeployGestures);
private _hasEHs 			= (_unit getVariable [SVAR(DeployedEH), -1] >= 0 && _unit getVariable [SVAR(ReloadedEH), -1] >= 0);
private _hasActionC2A 		= _unit getVariable [SVAR(ActionC2A), -1] >= 0;
private _hasActionA2C 		= _unit getVariable [SVAR(ActionA2C), -1] >= 0;

dzn_LOG_LoadoutEH = ["Wpn:",_w, "SecWpn:", _sw, "Has gestyre:", _hasGesture, "Has DeployEH:", _hasEHs, "Has C2A & A2C actions:", _hasActionC2A, _hasActionA2C];

if (_hasGesture) then {
	
	// --- Gesture and Tripod effects
	if (_hasEHs) then {
		
		// Do nothing
	} else {
		// --- Add Deployed & Reloaded EHs to handle gesture and tripod effects
		_unit setVariable [
			SVAR(DeployedEH)
			, _unit addEventHandler ["WeaponDeployed", { _this call GVAR(fnc_handleDeployedEH) }]
		];
		
		_unit setVariable [
			SVAR(ReloadedEH)
			, _unit addEventHandler ["Reloaded", { _this call GVAR(fnc_handleReloadedEH) }]
		];

		dzn_LOG_LoadoutEH pushBack "Adding Deployed & Reloaded EHs";
	};

	// Handle Carry2Attach actions availability
	if (["CHECK_C2A_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange)) then {
		if (!_hasActionC2A) then {
			(GVAR(Cache) getVariable _sw) params ["_hasAttach","_attachItem"];

			private _actionID = _unit addAction [
				format [
					LOCALIZE_FORMAT_STR("Action_Mount")
					, getText (configFile >> "CfgWeapons" >> _attachItem >> "displayName")
				]
				, { ["SWITCH_C2A", _this] call GVAR(fnc_handleCarryItemExchange); }
			];
			_unit setVariable [SVAR(ActionC2A), _actionID];

			dzn_LOG_LoadoutEH pushBack "Adding C2A action";
		};
	} else {
		if (_hasActionC2A) then { 
			[_unit, SVAR(ActionC2A)] call _fnc_removeAction; 
			dzn_LOG_LoadoutEH pushBack "Removing C2A action";
		};
	};

	// Handle Attach2Carry actions availability
	if (["CHECK_A2C_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange)) then {
		if (!_hasActionA2C) then {
			(GVAR(Cache) getVariable ((primaryWeaponItems _unit) # 3)) params ["_hasCarryOption", "_carryItem"];
			private _actionID = _unit addAction [
				format [
					LOCALIZE_FORMAT_STR("Action_Dismount")
					, getText (configFile >> "CfgWeapons" >> _carryItem >> "displayName")
				]
				, { ["SWITCH_A2C", _this] call GVAR(fnc_handleCarryItemExchange); }
			];
			_unit setVariable [SVAR(ActionA2C), _actionID];
		};

		dzn_LOG_LoadoutEH pushBack "Adding A2C action";
	} else {
		if (_hasActionA2C) then {
			[_unit, SVAR(ActionA2C)] call _fnc_removeAction;
			dzn_LOG_LoadoutEH pushBack "Removing A2C action";
		};
	};

} else {
	
	// --- Remove Deployed & Reloaded EHs
	if (_hasEHs) then {
		_unit removeEventHandler ["WeaponDeployed", _unit getVariable SVAR(DeployedEH)];
		_unit removeEventHandler ["Reloaded", _unit getVariable SVAR(ReloadedEH)];
		
		_unit setVariable [SVAR(DeployedEH), -1];
		_unit setVariable [SVAR(ReloadedEH), -1];

		dzn_LOG_LoadoutEH pushBack "Removing Deployed & Reloaded EHs";
	};
	
	// --- Remove L2A / A2L Conversion actions
	if (_hasActionC2A) then { [_unit, SVAR(ActionC2A)] call _fnc_removeAction; dzn_LOG_LoadoutEH pushBack "Removing C2A action"; };
	if (_hasActionA2C) then { [_unit, SVAR(ActionA2C)] call _fnc_removeAction; dzn_LOG_LoadoutEH pushBack "Removing A2C action"; };
};


/*
	// --- Launcher-to-Attach (L2A) & Attach-to-Launcher (A2L) Conversion
	// [_w, "bipod"] call CBA_fnc_compatibleItems;
	// --- L2A
	// if has launcher-carry item
	//	if launcher-carry item conversion is comaptible to weapon
	//		if no actions : add actions
	//		if actions exists : do nothing
	//	if launcher-carry item conversion is NOT comaptible to weapon: remove actions
	// if has no launcher-carry && actions exists: remove actions
	
	// --- A2L
	// if has attach item conversion
	//	if NO backpack
	//		if action exists: do nothing
	//		if NO action: add A2L action
	//	if HAS backpack:
	//		if action exists: remove A2L action
	//		if NO action: do nothing
*/
