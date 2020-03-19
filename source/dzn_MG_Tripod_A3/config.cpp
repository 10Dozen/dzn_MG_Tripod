class CfgPatches
{
	class dzn_MG_Tripod_A3
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"CBA_jr"
			,"dzn_MG_Tripod_Core"
		};
		author = "10Dozen";
		version = "1.3";
	};
};

class asdg_SlotInfo;
class asdg_UnderSlot: asdg_SlotInfo 
{
	class compatibleItems;
};
class dzn_MG_Tripod_Underslot: asdg_UnderSlot
{
	class compatibleItems: compatibleItems
	{
		dzn_MG_Tripod_Universal = 1;
	};
};

#define DEPLOYED_GESTURE_GPMG \
	dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType1","dzn_MG_Tripod_GestureHoldCrouchType1","dzn_MG_Tripod_GestureHoldProneType1"}

#define DEPLOYED_GESTURE_M249PARA \
	dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType3","dzn_MG_Tripod_GestureHoldCrouchType2","dzn_MG_Tripod_GestureHoldProneType2"}

#define DEPLOYED_GESTURE_IAR \
	dzn_MG_Tripod_deployedGesture[] = {"","","dzn_MG_Tripod_GestureHoldProneType1"}
	
#define RELOAD_EH \
	class EventHandlers: EventHandlers \
	{ \
		class dzn_MG_Tripod \
		{ \
			reload = "_this call dzn_MG_Tripod_fnc_handleReloadEH"; \
			reloaded = "_this call dzn_MG_Tripod_fnc_handleReloadedEH"; \
		}; \
	}

class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle 
	{
		class WeaponSlotsInfo;
		class EventHandlers;
	};
	class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot;
			class PointerSlot;
		};
	};
	
	// --- Vanilla MGs
	// --- ------------------------------
	class LMG_Mk200_F: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};
	class LMG_Zafir_F: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
	};
	
	class MMG_01_base_F: Rifle_Long_Base_F {
		class WeaponSlotsInfo;
		class EventHandlers;
	};
	class MMG_01_hex_F: MMG_01_base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};
	class MMG_02_base_F: Rifle_Long_Base_F 
	{
		class WeaponSlotsInfo;
		class EventHandlers;
	};
	class MMG_02_camo_F: MMG_02_base_F 
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};

	class LMG_03_base_F: Rifle_Long_Base_F {};
	class LMG_03_F: LMG_03_base_F
	{
		DEPLOYED_GESTURE_M249PARA;
		RELOAD_EH;
	};
};