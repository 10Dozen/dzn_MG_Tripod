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

		// --- Check that secondary weapon has Carry 2 Attach option
		private _attachOption = "";
		private _hasAttachOption = false;

		private _cachedAttachOptionInfo = GVAR(Cache) getVariable _secondaryWeapon;
		if (isNil "_cachedAttachOptionInfo") then {
			// Read from config and cache
			_attachOption = toLower (getText (configFile >> "CfgWeapons" >> _secondaryWeapon >> "dzn_MG_Tripod_AttachItem"));
			_hasAttachOption = _attachOption != "";

			GVAR(Cache) setVariable [_secondaryWeapon, [_hasAttachOption, _attachOption]];
		} else {
			// Read from cache
			_hasAttachOption = _cachedAttachOptionInfo # 0;
			_attachOption = _cachedAttachOptionInfo # 1;
		};

		// --- Check that attach option is compatible with primary weapon
		if (!_hasAttachOption) exitWith {};

		private _isCompatible = GVAR(Cache) getVariable format ["%1__%2", _primaryWeapon, _attachOption];
		if (isNil "_isCompatible") then {
			private _compatibleAttaches = ([_primaryWeapon, "bipod"] call CBA_fnc_compatibleItems) apply { toLower _x };
			_isCompatible = _compatibleAttaches findIf { _x == _attachOption } > -1;

			GVAR(Cache) setVariable [
				format ["%1__%2", _primaryWeapon, _attachOption]
				, _isCompatible
			];
		};

		_result = _isCompatible;
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
		private _attach = (primaryWeaponItems _unit) # 3;
		if (_attach == "") exitWith {}; 

		// --- Check that attach has A2C exchange option 
		private _carryItem = "";
		private _hasCarryOption = false;

		private _carryItemInfo = GVAR(Cache) getVariable _attach;
		if (isNil "_carryItemInfo") then {
			_carryItem = getText (configFile >> "CfgWeapons" >> _attach >> "dzn_MG_Tripod_CarryItem");
			_hasCarryOption = _carryItem != "";

			GVAR(Cache) setVariable [_attach, [_hasCarryOption, _carryItem]];
		} else {
			_hasCarryOption = _carryItemInfo # 0;
		};

		_result = _hasCarryOption;
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
		_payload params ["_unit", "_caller", "_actionId", "_arguments"];
		
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
				(GVAR(Cache) getVariable _sw) params ["_hasAttach","_attachItem"];
				_unit removeWeapon _sw;
				_unit addPrimaryWeaponItem _attachItem;
				_unit setAnimSpeedCoef 1;ce;

				hint "Done";
			}
			, {
				(_this # 0) params ["_unit","_actionId","_preAnimStance"];

				_unit setAnimSpeedCoef 1;
				_unit switchMove _preAnimStance;
				hint "Aborted";
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

				private _attach = (primaryWeaponItems _unit) # 3;
				(GVAR(Cache) getVariable _attach) params ["_hasCarryOption", "_carryItem"];
				_unit removePrimaryWeaponItem _attach;
				_unit addWeapon _carryItem;
				_unit setAnimSpeedCoef 1;

				hint "Done";
			}
			, {
				(_this # 0) params ["_unit","_actionId","_preAnimStance"];

				_unit setAnimSpeedCoef 1;
				_unit switchMove _preAnimStance;
				hint "Aborted";
			}
			, [_unit, _actionId, _preAnimStance]
		] call CBA_fnc_progressBar;
	};
};

_result
