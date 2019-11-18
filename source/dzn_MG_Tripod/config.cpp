class CfgPatches
{
	class dzn_MG_Tripod
	{
		units[] = {};
		weapons[] = {
			"dzn_MGTripod_Universal"
			,"dzn_MGTripod_m240mount"
			,"dzn_MGTripod_m60mount"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"CBA_jr"
			,"CUP_Weapons_M240"
			,"CUP_Weapons_M249"
			,"CUP_Weapons_M60E4"
			,"CUP_Weapons_MG3"
			,"CUP_Weapons_PK"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

class Extended_PostInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod\Init.sqf";
	};
};
class Extended_PreInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod\Settings.sqf";
	};
};

class UnderBarrelSlot;
class CUP_PicatinnyTopMount;
class CUP_PicatinnySideMount;
class asdg_SlotInfo;
class asdg_UnderSlot: asdg_SlotInfo 
{
	class compatibleItems;
};
class dzn_MGTripod_Underslot: asdg_UnderSlot
{
	class compatibleItems: compatibleItems
	{
		dzn_MGTripod_Universal = 1;
	};
};


class CfgWeapons
{
	class ItemCore;
	class InventoryUnderItem_Base_F;
	class Launcher;
	class Launcher_Base_F: Launcher
	{
		class WeaponSlotsInfo;
	};
	
	// --- Attachements
	class dzn_MGTripod_Universal: ItemCore
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_MGUniversalTripod";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";
		model="\dzn_MG_Tripod\nato_tripod_m122_universal.p3d";
		class ItemInfo: InventoryUnderItem_Base_F
		{
			deployedPivot    = "bipod";       /// what point should be used to be on surface while unfolded
			hasBipod         = true;          /// bipod obviously has a bipod
			mass             = 165;            /// what is the mass of the object
			soundBipodDeploy[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy", 0.70794576, 1, 20 };
			soundBipodFold[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold", 0.70794576, 1, 20 };
			soundBipodDown[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down", 0.70794576, 1, 20 };
			soundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up", 0.70794576, 1, 20 };
		};
		inertia = 1.25; 
		
		class dzn_MGTripodInfo 
		{
			item = "";
			carry = "dzn_MGTripod_Universal_Carry";
			isCarry = 0;
			isAttach = 1;
		};
	};
	class dzn_tripod_mg_nato: dzn_MGTripod_Universal {
		scope = 1;
	};
	class dzn_MGTripod_m240mount: dzn_MGTripod_Universal
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240";
		model="\dzn_MG_Tripod\nato_tripod_m122_m240.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";
	};
	class dzn_MGTripod_m60mount: dzn_MGTripod_Universal
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M60";
		model="\dzn_MG_Tripod\nato_tripod_m122_m60.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_m60_icon_ca.paa";
	};
	
	class dzn_MGTripod_Universal_Carry: Launcher_Base_F
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_MGUniversalTripod";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";
		model="\dzn_MG_Tripod\nato_tripod_m122_universal.p3d";
		muzzles[] = {};
		magazines[] = {};
		modes[] = {};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			allowedSlots[] = {};
			mass = 165;
		};
		
		class dzn_MGTripodInfo 
		{
			item = "dzn_MGTripod_Universal";
			carry = "";
			isCarry = 1;
			isAttach = 0;
		};
	};
	
	// --- Weapon Compatibility
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MGTripod_Underslot {};
		};
	};
	class MMG_01_base_F: Rifle_Long_Base_F {
		class WeaponSlotsInfo;
	};
	class MMG_01_hex_F: MMG_01_base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MGTripod_Underslot {};
		};
	};
	class MMG_02_base_F: Rifle_Long_Base_F 
	{
		class WeaponSlotsInfo;
	};
	class MMG_02_camo_F: MMG_02_base_F 
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: dzn_MGTripod_Underslot {};
		};
	};

	// --- CUP M240 and FN MAG
	// --- ------------------------------
	class CUP_lmg_M240: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MGTripod_Universal","dzn_MGTripod_m240mount"};
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MGTripod_Universal","dzn_MGTripod_m240mount"};
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
		class WeaponSlotsInfo;
	};
	class CUP_lmg_minimi_railed: CUP_lmg_minimipara 
	{
		class WeaponSlotsInfo;
	};
	class CUP_lmg_m249_pip4: CUP_lmg_minimi_railed
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot {};
		};
	};
	class CUP_lmg_m249_para_gl :CUP_lmg_minimipara
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot {};
		};		
	};
	// --		End of not compatible variants ---
	
	class CUP_lmg_L110A1 :CUP_lmg_m249_pip4
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MGTripod_Universal","dzn_MGTripod_m240mount"};
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]= {"dzn_MGTripod_Universal","dzn_MGTripod_m60mount"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.602,0.73};
				iconScale  = 0.45;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_m60_ca.paa";
			};
		};
	};
	// class CUP_lmg_M60E4: CUP_M60E4_base
	// class CUP_lmg_M60E4_norail: CUP_M60E4_base {};
	class CUP_lmg_M60: CUP_M60E4_base
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{
				iconPosition[] = {0.717,0.695};
				iconScale  = 0.37;
			};
		};
	};
	
	// --- CUP Mk48
	// --- ------------------------------
	class CUP_lmg_Mk48_Base: Rifle_Long_Base_F
	{
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MGTripod_Universal","dzn_MGTripod_m240mount"};
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot;
			class PointerSlot;
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MGTripod_Universal"};
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CUP_PicatinnyTopMount {};
			class PointerSlot: CUP_PicatinnySideMount {};
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MGTripod_Universal"};
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
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class UnderBarrelSlot: UnderBarrelSlot
			{ 
				compatibleItems[]= {"dzn_MGTripod_Universal"};
				linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL";
				
				iconPinpoint="center";
				iconPosition[] = {0.566,0.771};
				iconScale  = 0.64;
				iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_m122_ca.paa";
			};
		};
	};
	// class CUP_lmg_Pecheneg: CUP_lmg_PKM {};
	
};