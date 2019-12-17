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
			,"dzn_MG_Tripod"
		};
		author = "10Dozen";
		version = "1.2";
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

#define DEPLOYED_GESTURE dzn_MG_Tripod_deployedGesture = "dzn_MG_Tripod_GestureHoldTop1"

class CfgWeapons
{
	class Rifle;
	class Rifle_Base_F: Rifle 
	{
		class WeaponSlotsInfo;
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
		DEPLOYED_GESTURE;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};
	class MMG_01_base_F: Rifle_Long_Base_F {
		class WeaponSlotsInfo;
	};
	class MMG_01_hex_F: MMG_01_base_F
	{
		DEPLOYED_GESTURE;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};
	class MMG_02_base_F: Rifle_Long_Base_F 
	{
		class WeaponSlotsInfo;
	};
	class MMG_02_camo_F: MMG_02_base_F 
	{
		DEPLOYED_GESTURE;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MG_Tripod_Underslot {};
		};
	};

};