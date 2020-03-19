#include "..\macro.hpp"

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleLoadoutEH

Description:
	Handles Loadout event:
		- Verifies that player has primary weapon is compatible with tripods and has gesture anim
		- Adds or removes Deployed EH if needed
		- Adds or removes tripod carry-to-attach actions and Inventory EH

	Assumptions:
		- All MGs compatible with tripod MUST HAVE `dzn_MGTripod_deployedGesture` property
		- MG with `dzn_MGTripod_deployedGesture` property MAY BE compatible with tripods (means some MGs with deployedGesture, are not compatible with tripods)
		- Deployed handlers added ONLY if weapon has `dzn_MGTripod_deployedGesture` property and removed otherwise

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

_newLoadout = getUnitLoadout _unit; // Fixes CBA Loadout evant's return value

private _w = _newLoadout # 0 # 0;
private _sw = if (_newLoadout # 1 isEqualTo []) then { "" } else { _newLoadout # 1 # 0 };

private _hasGesture = [_w] call GVAR(fnc_checkWeaponHasDeployGestures);
private _hasEHs = (_unit getVariable [SVAR(DeployedEH), -1] >= 0);
private _hasActionC2A = _unit getVariable [SVAR(ActionC2A), -1] >= 0;
private _hasActionA2C = _unit getVariable [SVAR(ActionA2C), -1] >= 0;

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
	};

	private _C2A_Available = ["CHECK_C2A_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange);
	private _A2C_Available = ["CHECK_A2C_AVAILABLE", [_unit, _w, _sw]] call GVAR(fnc_handleCarryItemExchange);

	// Handle Carry2Attach actions availability
	if (_C2A_Available) then {
		private _attachItem = ["GET_ATTACH_OPTION",[_unit]] call GVAR(fnc_handleCarryItemExchange);
		if (!_hasActionC2A) then {
			["ADD", [
				_unit, SVAR(ActionC2A),
				LOCALIZE_FORMAT_STR("Action_Mount"), _attachItem,
				{ ["SWITCH_C2A", _this] spawn GVAR(fnc_handleCarryItemExchange); }
			]] call GVAR(fnc_handleTripodActions);
		} else {
			["UPDATE",[
				_unit, SVAR(ActionC2A), 
				LOCALIZE_FORMAT_STR("Action_Mount"), _attachItem
			]] call GVAR(fnc_handleTripodActions);
		};
	} else {
		if (_hasActionC2A) then {
			["REMOVE",[_unit, SVAR(ActionC2A)]] call GVAR(fnc_handleTripodActions);
		};
	};

	// Handle Attach2Carry actions availability
	if (_A2C_Available) then {
		private _item = (primaryWeaponItems _unit # 3);
		if (!_hasActionA2C) then {
			["ADD",[
				_unit, SVAR(ActionA2C)
				, LOCALIZE_FORMAT_STR("Action_Dismount"),_item
				, { ["SWITCH_A2C", _this] spawn GVAR(fnc_handleCarryItemExchange); }
			]] call GVAR(fnc_handleTripodActions);
		} else {
			["UPDATE",[
				_unit, SVAR(ActionA2C), 
				LOCALIZE_FORMAT_STR("Action_Dismount"), _item
			]] call GVAR(fnc_handleTripodActions);
		};

		// --- Add inventory handler (as tripod installed and we need to ensure that it can't be dropped accidentally)
		["SET"] call GVAR(fnc_uiHandleInventory);
	} else {
		if (_hasActionA2C) then {
			["REMOVE",[_unit, SVAR(ActionA2C)]] call GVAR(fnc_handleTripodActions);
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
		_unit setVariable [SVAR(DeployedEH), -1];
	};

	// --- Remove L2A / A2L Conversion actions
	if (_hasActionC2A) then { ["REMOVE",[_unit, SVAR(ActionC2A)]] call GVAR(fnc_handleTripodActions); };
	if (_hasActionA2C) then { ["REMOVE",[_unit, SVAR(ActionA2C)]] call GVAR(fnc_handleTripodActions); };

	// --- Remove inventory EHs
	["CLEAR"] call GVAR(fnc_uiHandleInventory);
};