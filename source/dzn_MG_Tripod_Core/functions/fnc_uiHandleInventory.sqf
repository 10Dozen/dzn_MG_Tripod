#include "..\macro.hpp"
#define SELF GVAR(fnc_uiHandleInventory)

/* ----------------------------------------------------------------------------
Function: dzn_MG_Tripod_fnc_uiHandleInventory

Description:
	Handles inventory menu while tripod is attached: disables bipod slot

Parameters:
	_mode -- function call mode <STRING>
	_payload -- function payload <ARRAY>

Returns:
	_result -- function result <BOOL>

Examples:
    (begin example)
		["SET"] call dzn_MG_Tripod_fnc_uiHandleInventory; 
    (end)

Author:
	10Dozen
---------------------------------------------------------------------------- */

#define INV_DISPLAY (findDisplay 602)
#define INV_CTRL(X)	(INV_DISPLAY displayCtrl X)
#define INV_PW_BIPOD INV_CTRL(641)

params ["_mode", ["_payload", []]];

private _result = false;

switch (toUpper _mode) do {
	case "SET": {
		if (!isNil SVAR(handleInventory)) exitWith {};

		GVAR(handleInventory) = true;
		GVAR(inventoryEH) = player addEventHandler [
			"InventoryOpened"
			, { ["HANDLE_OPENED"] spawn SELF; }
		];
		GVAR(inventoryClosedEH) = player addEventHandler [
			"InventoryClosed"
			, { ["HANDLE_CLOSED"] spawn SELF; }
		];

		// --- Handles inventroy is already opened during execution
		if (!isNull INV_DISPLAY) then {
			["HANDLE_OPENED"] spawn SELF;
		};
	};
	case "CLEAR": {
		if (isNil SVAR(handleInventory)) exitWith {};

		["HANDLE_CLOSED"] call SELF;
		player removeEventHandler ["InventoryOpened", GVAR(inventoryEH)];
		player removeEventHandler ["InventoryClosed", GVAR(inventoryClosedEH)];

		GVAR(handleInventory) = nil;
		GVAR(inventoryEH) = nil;
		GVAR(inventoryClosedEH) = nil;
	};
	case "HANDLE_OPENED": {
		waitUntil { !isNull INV_DISPLAY };

		// --- Hide and disable bipod slot; keep slot hidden by PFH
		private _bipodCtrl = INV_PW_BIPOD;
		GVAR(_inventoryPFH) = [{
			(_this # 0) ctrlShow false;
			(_this # 0) ctrlEnable false;
			(_this # 0) ctrlCommit 0;
		}, 0, _bipodCtrl] call CBA_fnc_addPerFrameHandler;
	};
	case "HANDLE_CLOSED": {
		if (isNil SVAR(_inventoryPFH)) exitWith {};

		[GVAR(_inventoryPFH)] call CBA_fnc_removePerFrameHandler;
		GVAR(_inventoryPFH) = nil;

		if (!isNull INV_DISPLAY) then {
			// --- Show slot if handle_closed was triggered by RESET
			private _bipodCtrl = INV_PW_BIPOD;
			_bipodCtrl ctrlShow true;
			_bipodCtrl ctrlEnable true;
			_bipodCtrl ctrlCommit 0;
		}
	};
};

_result