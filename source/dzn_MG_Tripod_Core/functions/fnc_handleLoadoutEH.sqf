#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleLoadoutEH

Description:
	Handles Loadout event: 
		- Verifies that player has primary weapon is compatible with tripods and has gesture anim
		- Adds or removes Deployed & Reloaded EHs if needed
		- Adds or removes tripod carry-to-attach actions and Inventory EH
	
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

params ["_unit", "_newLoadout"];

private _w = _newLoadout # 0 # 0;
private _sw = if (_newLoadout # 1 isEqualTo []) then { "" } else { _newLoadout # 1 # 0 };

private _hasGesture 		= [_w] call GVAR(fnc_checkWeaponHasDeployGestures);
private _hasEHs 			= (_unit getVariable [SVAR(DeployedEH), -1] >= 0 && _unit getVariable [SVAR(ReloadedEH), -1] >= 0);
private _hasActionC2A 		= _unit getVariable [SVAR(ActionC2A), -1] >= 0;
private _hasActionA2C 		= _unit getVariable [SVAR(ActionA2C), -1] >= 0;

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
	};

	private _C2A_Available = ["CHECK_C2A_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange);
	private _A2C_Available = ["CHECK_A2C_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange);

	// Handle Carry2Attach actions availability
	if (_C2A_Available) then {
		if (!_hasActionC2A) then {
			(GVAR(Cache) getVariable _sw) params ["_hasAttach","_attachItem"];

			[
				_unit
				, SVAR(ActionC2A)
				, LOCALIZE_FORMAT_STR("Action_Mount")
				, _attachItem
				, { ["SWITCH_C2A", _this] spawn GVAR(fnc_handleCarryItemExchange); }
			] call GVAR(fnc_addTripodAction);
		};
	} else {
		if (_hasActionC2A) then { 
			[_unit, SVAR(ActionC2A)] call GVAR(fnc_removeTripodAction);
		};
	};

	// Handle Attach2Carry actions availability
	if (_A2C_Available) then {
		if (!_hasActionA2C) then {
			(GVAR(Cache) getVariable ((primaryWeaponItems _unit) # 3)) params ["_hasCarryOption", "_carryItem"];

			[
				_unit
				, SVAR(ActionA2C)
				, LOCALIZE_FORMAT_STR("Action_Dismount")
				, _carryItem
				, { ["SWITCH_A2C", _this] spawn GVAR(fnc_handleCarryItemExchange); }
			] call GVAR(fnc_addTripodAction);
		};
		
		// --- Add inventory handler (as tripod installed and we need to ensure that it can't be dropped accidentally)
		["SET"] call GVAR(fnc_uiHandleInventory);
	} else {
		if (_hasActionA2C) then {
			[_unit, SVAR(ActionA2C)] call GVAR(fnc_removeTripodAction);
		};

		// --- Check that tripod installed
		if ([_unit] call GVAR(fnc_checkWeaponHasTripod)) then {
			// --- Set inventory EH anew (as tripod installed, but A2C is blocked because of Launcher slot is occupied); "SET" won't override EHs
			["SET"] call GVAR(fnc_uiHandleInventory);
		} else {
			// --- Remove inventory handler (as tripod was removed and slot should be available for other bipod items)
			["CLEAR"] call GVAR(fnc_uiHandleInventory);
		};
	};
} else {
	// --- Weapon has no Gesture (and tripod compatibility) -- remove all handlers and actions:

	// --- Remove Deployed & Reloaded EHs
	if (_hasEHs) then {
		_unit removeEventHandler ["WeaponDeployed", _unit getVariable SVAR(DeployedEH)];
		_unit removeEventHandler ["Reloaded", _unit getVariable SVAR(ReloadedEH)];
		
		_unit setVariable [SVAR(DeployedEH), -1];
		_unit setVariable [SVAR(ReloadedEH), -1];
	};
	
	// --- Remove L2A / A2L Conversion actions
	if (_hasActionC2A) then { [_unit, SVAR(ActionC2A)] call GVAR(fnc_removeTripodAction); };
	if (_hasActionA2C) then { [_unit, SVAR(ActionA2C)] call GVAR(fnc_removeTripodAction); };

	// --- Remove inventory EHs
	["CLEAR"] call GVAR(fnc_uiHandleInventory);
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
