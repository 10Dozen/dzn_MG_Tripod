class CfgPatches
{
	class dzn_MG_Tripod_CUP
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"CBA_jr"
			,"CUP_Weapons_M240"
			,"CUP_Weapons_M249"
			,"CUP_Weapons_M60E4"
			,"CUP_Weapons_MG3"
			,"CUP_Weapons_PK"
			,"CUP_Weapons_UK59"
			,"dzn_MG_Tripod_Core"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

class UnderBarrelSlot;
class CUP_PicatinnyTopMount;
class CUP_PicatinnySideMount;


#define DEPLOYED_GESTURE_GPMG \
	dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType1","dzn_MG_Tripod_GestureHoldCrouchType1","dzn_MG_Tripod_GestureHoldProneType1"}

#define DEPLOYED_GESTURE_M249 \
	dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType2","dzn_MG_Tripod_GestureHoldCrouchType2","dzn_MG_Tripod_GestureHoldProneType2"}

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
	// --- Tripod Attach
	class dzn_MG_Tripod_Universal;
	class dzn_MG_Tripod_M122A1_M240Mount: dzn_MG_Tripod_Universal
	{
		scope=2;
	};
	class dzn_MG_Tripod_M122A1_M60Mount: dzn_MG_Tripod_Universal
	{
		scope=2;
	};
	
	// --- Tripod Carry Item
	class dzn_MG_Tripod_Universal_Carry;
	class dzn_MG_Tripod_M122A1_M240Mount_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=2;
	};
	class dzn_MG_Tripod_M122A1_M60Mount_Carry: dzn_MG_Tripod_Universal_Carry
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
	
	// --- CUP M240 and FN MAG
	// --- ------------------------------
	class CUP_lmg_M240: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MG_Tripod_Universal","dzn_MG_Tripod_M122A1_M240mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	
	// --- CUP M249 family
	// --- ------------------------------
	class CUP_saw_base: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_M249;
		RELOAD_EH;
		
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MG_Tripod_Universal","dzn_MG_Tripod_M122A1_M240mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.457,0.807};
				iconScale  = 0.67;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	
	// -- 		Not compatible variants --
	class CUP_lmg_minimipara: CUP_saw_base
	{
		DEPLOYED_GESTURE_M249PARA;
		RELOAD_EH;
		class WeaponSlotsInfo;
	};
	class CUP_lmg_minimi_railed: CUP_lmg_minimipara 
	{
		DEPLOYED_GESTURE_M249;
		RELOAD_EH;
		class WeaponSlotsInfo;
	};
	class CUP_lmg_m249_pip4: CUP_lmg_minimi_railed
	{
		DEPLOYED_GESTURE_M249;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot {};
		};
	};
	class CUP_lmg_m249_para_gl :CUP_lmg_minimipara
	{
		dzn_MG_Tripod_deployedGesture[] = {};
		class EventHandlers: EventHandlers 
		{
			reload = "";
			reloaded = "";
		};
		
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot {};
		};		
	};	
	class CUP_lmg_L110A1 :CUP_lmg_m249_pip4
	{
		DEPLOYED_GESTURE_M249PARA;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MG_Tripod_Universal","dzn_MG_Tripod_M122A1_M240mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.457,0.807};
				iconScale  = 0.67;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};

	// --- CUP M60 and M60E4
	// --- ------------------------------
	class CUP_M60E4_base: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MG_Tripod_Universal","dzn_MG_Tripod_M122A1_M60mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.602,0.73};
				iconScale  = 0.90;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_m60_ca.paa";
			};
		};
	};
	// class CUP_lmg_M60E4: CUP_M60E4_base
	// class CUP_lmg_M60E4_norail: CUP_M60E4_base {};
	class CUP_lmg_M60: CUP_M60E4_base
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				iconPosition[] = {0.717,0.695};
				iconScale  = 0.74;
			};
		};
	};
	
	// --- CUP Mk48
	// --- ------------------------------
	class CUP_lmg_Mk48_Base: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_M249;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MG_Tripod_Universal","dzn_MG_Tripod_M122A1_M240mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};

	// --- CUP MG3
	// --- ------------------------------
	class CUP_lmg_MG3: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot;
			class PointerSlot;
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MG_Tripod_Universal"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	class CUP_lmg_MG3_rail: CUP_lmg_MG3 
	{
		DEPLOYED_GESTURE_GPMG;
		RELOAD_EH;
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CUP_PicatinnyTopMount {};
			class PointerSlot: CUP_PicatinnySideMount {};
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MG_Tripod_Universal"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	
	// --- CUP PKM & PKP
	// --- ------------------------------	
	class CUP_lmg_PKM: Rifle_Long_Base_F
	{
		dzn_MG_Tripod_deployedGesture[] = {"dzn_MG_Tripod_GestureHoldType3","dzn_MG_Tripod_GestureHoldCrouchType2","dzn_MG_Tripod_GestureHoldProneType1"};
		RELOAD_EH;
		
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MG_Tripod_Universal"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	// class CUP_lmg_Pecheneg: CUP_lmg_PKM {};
	
	// --- CUP UK59
	// --- ------------------------------	
	class CUP_lmg_UK59: Rifle_Long_Base_F
	{
		dzn_MG_Tripod_deployedGesture[] = 
		{
			"dzn_MG_Tripod_GestureHoldType1"
			,"dzn_MG_Tripod_GestureHoldCrouchType2"
			,"dzn_MG_Tripod_GestureHoldProneType2"
		};
		RELOAD_EH;
	};
};