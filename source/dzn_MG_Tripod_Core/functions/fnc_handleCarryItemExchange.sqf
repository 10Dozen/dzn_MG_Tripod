#include "..\macro.hpp"
#define SELF GVAR(fnc_handleCarryItemExchange)

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_handleCarryItemExchange

Description:
	Handles Carry Item to Attach and backward exchange.

Parameters:
	_mode -- function call mode <STRING>
	_payload -- function payload <ARRAY>

Returns:
	_result -- function result <BOOL>

Examples:
    (begin example)
	["CHECK_C2A", [_unit, _primaryWeapon, _secondaryWeapon]] call dzn_MG_Tripod_fnc_handleCarryItemExchange;
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */
#define ANIM_CROUCH "amovpknlmstpsraswrfldnon"
#define ANIM_PRONE "amovppnemstpsraswrfldnon"

params ["_mode", ["_payload", []]];

private _result = false;

switch (toUpper _mode) do {
	case "CHECK_C2A_AVAILABLE": {
		/**
			Return TRUE if all met:
				- weapon's bipod slot is free
				- secondary weapon has excahnge option
				- this option is compatible with primary weapon "bipod" slot
		 */
		_payload params ["_unit", "_primaryWeapon", "_secondaryWeapon"];

		if (_secondaryWeapon == "") exitWith {};

		// --- Skip checks if bipod slot is occupied
		if (((primaryWeaponItems _unit) # 3) != "") exitWith {};

		// --- Check that secondary weapon has Carry 2 Attach option compatible to main weapon
		private _attachItem = [_primaryWeapon, _secondaryWeapon] call GVAR(fnc_getCompatibleAttachOption);
		
		_result = _attachItem != "";
	};
	case "CHECK_A2C_AVAILABLE": {
		/**
			Return TRUE if:
				- player has no secondary weapon
				- primary weapon has bipod item
				- this item has Attach 2 Carry exchange option
		 */
		_payload params ["_unit", "_primaryWeapon", "_secondaryWeapon"];

		// --- Skip checks if unit has secondary weapon
		if (secondaryWeapon _unit != "") exitWith {};

		// --- Skip if primary weapon has no bipod item
		private _attachItem = (primaryWeaponItems _unit) # 3;
		if (_attachItem == "") exitWith {};

		// --- Check that attach has A2C exchange option
		private _carryItem = [_attachItem, _unit getVariable [SVAR(UsedCarryItem), ""]] call GVAR(fnc_getPreferredCarryOption);

		_result = _carryItem != "";
	};
	case "PREPARE_STANCE": {
		_payload params ["_unit"];

		if (vehicle _unit != _unit) exitWith { /* In vehicle */ };

		// Undeploy if currently deployed
		if (isWeaponDeployed _unit) then {
			if (stance _unit == "PRONE") then {
				_unit playMoveNow ANIM_PRONE;
			} else {
				_unit playMoveNow ANIM_CROUCH;
			};
		};

		uiSleep 0.25;

		// Switch to crouch position that allows tranfer of animation
		if (stance _unit == "PRONE") then {
			_unit playMoveNow ANIM_CROUCH;
			waitUntil { animationState _unit == ANIM_CROUCH };
		};
	};
	case "SWITCH_C2A": {
		_payload params ["_unit", "_caller", "_actionId"];
		["PREPARE_STANCE", [_unit]] call SELF;

		private _preAnimStance = animationState _unit;
		_unit playAction "MountSide";
		_unit setAnimSpeedCoef 3;

		[
			LOCALIZE_FORMAT_STR("ProgressBar_Mount")
			, 5
			, {true}
			, {
				(_this # 0) params ["_unit","_actionId"];
				_unit removeAction _actionId;

				private _sw = secondaryWeapon _unit;
				private _attachItem = ["GET_ATTACH_OPTION", [_unit]] call SELF;

				_unit setVariable [SVAR(UsedCarryItem), _sw]; // Save used carry item
				_unit removeWeapon _sw;
				_unit addPrimaryWeaponItem _attachItem;
				_unit setAnimSpeedCoef 1;

				hint LOCALIZE_FORMAT_STR("Hint_Mounted");
			}
			, {
				(_this # 0) params ["_unit","_actionId","_preAnimStance"];

				_unit setAnimSpeedCoef 1;
				_unit switchMove _preAnimStance;
				hint LOCALIZE_FORMAT_STR("Hint_Aborted");
			}
			, [_unit, _actionId, _preAnimStance]
		] call CBA_fnc_progressBar;
	};
	case "SWITCH_A2C": {
		_payload params ["_unit", "_caller", "_actionId", "_arguments"];

		["PREPARE_STANCE", [_unit]] call SELF;

		private _preAnimStance = animationState _unit;
		_unit playAction "MountSide";
		_unit setAnimSpeedCoef 3;

		[
			LOCALIZE_FORMAT_STR("ProgressBar_Dismount")
			, 5
			, {true}
			, {
				(_this # 0) params ["_unit","_actionId"];
				_unit removeAction _actionId;

				private _carryItem = ["GET_CARRY_OPTION", [_unit]] call SELF;

				_unit removePrimaryWeaponItem ((primaryWeaponItems _unit) # 3);
				_unit addWeapon _carryItem;
				_unit setAnimSpeedCoef 1;

				hint LOCALIZE_FORMAT_STR("Hint_Dimounted");
			}
			, {
				(_this # 0) params ["_unit","_actionId","_preAnimStance"];

				_unit setAnimSpeedCoef 1;
				_unit switchMove _preAnimStance;
				hint LOCALIZE_FORMAT_STR("Hint_Aborted");
			}
			, [_unit, _actionId, _preAnimStance]
		] call CBA_fnc_progressBar;
	};
	case "GET_CARRY_OPTION": {
		_payload params ["_unit"];
		_result = [
			(primaryWeaponItems _unit) # 3
			, _unit getVariable [SVAR(UsedCarryItem), ""]
		] call GVAR(fnc_getPreferredCarryOption);
	};
	case "GET_ATTACH_OPTION": {
		_payload params ["_unit"];
		_result = [
			primaryWeapon _unit
			, secondaryWeapon _unit
		] call GVAR(fnc_getCompatibleAttachOption);
	};
};

_result
