class CfgPatches
{
	class dzn_MG_Tripod_RHSUSAF
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"rhsusf_c_weapons"
			,"dzn_MG_Tripod_Core"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

class UnderBarrelSlot;
class asdg_SlotInfo; 
class rhs_UnderSlot_m249: asdg_SlotInfo
{
	class compatibleItems
	{
		dzn_MG_Tripod_M122A1_M249Mount_RHS = 1;
	};
};
class rhs_Underslot_m249_ris: rhs_UnderSlot_m249
{
	class compatibleItems
	{
		dzn_MG_Tripod_M122A1_M249Mount_RHS = 1;
	};
};
class rhs_UnderSlot_m240: asdg_SlotInfo
{
	class compatibleItems
	{
		dzn_MG_Tripod_M122A1_M240Mount_RHS = 1;
	};
};

#define DEPLOYED_GESTURE_EMPTY \
	dzn_MG_Tripod_deployedGesture[] = {"","",""}

class CfgWeapons
{
	// --- Tripod Attach
	class dzn_MG_Tripod_Universal;
	class dzn_MG_Tripod_M122A1_M240Mount_RHS: dzn_MG_Tripod_Universal
	{
		scope=2;
	};
	class dzn_MG_Tripod_M122A1_M249Mount_RHS: dzn_MG_Tripod_Universal
	{
		scope=2;
	};
	// --- Tripod Carry Item
	class dzn_MG_Tripod_Universal_Carry;
	class dzn_MG_Tripod_M122A1_M240Mount_RHS_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=2;
	};
	class dzn_MG_Tripod_M122A1_M249Mount_RHS_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=2;
	};
	
	// --- Weapon compatibility
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
	
	// --- RHS M249
	// --- ------------------------------
	class rhs_weap_M249_base;
	class rhs_weap_lmg_minimi_railed;
	class rhs_weap_m249: rhs_weap_lmg_minimi_railed
	{
		DEPLOYED_GESTURE_EMPTY;
	};
	class rhs_weap_m249_pip_S: rhs_weap_lmg_minimi_railed
	{
		DEPLOYED_GESTURE_EMPTY;
	};
	class rhs_weap_m249_pip: rhs_weap_lmg_minimi_railed
	{
		DEPLOYED_GESTURE_EMPTY;
	};
	class rhs_weap_m249_pip_L: rhs_weap_lmg_minimi_railed
	{
		DEPLOYED_GESTURE_EMPTY;
	};
	class rhs_weap_m240_base: rhs_weap_M249_base
	{
		DEPLOYED_GESTURE_EMPTY;
	};
};