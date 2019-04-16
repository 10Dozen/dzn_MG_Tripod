class CfgPatches
{
	class dzn_MG_Tripod
	{
		units[] = {"dzn_tripod_gpmg_nato"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"CBA_MAIN","CUP_Weapons_M240","CUP_Weapons_M249"};
		author = "10Dozen";
		version = "1";
	};
};

class Extended_PostInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod\Init.sqf";
	};
};

class CowsSlot;

class CfgWeapons
{
	class ItemCore;
	class InventoryUnderItem_Base_F;
	class dzn_tripod_mg_nato: ItemCore
	{
		scope=2;
		author="10Dozen";
		displayName="GPMG Tripod (NATO)";
		picture = "\dzn_MG_Tripod\data\ui\tripod_nato_ca.paa";
		model="\dzn_MG_Tripod\nato_tripod.p3d";
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
	};
	
	
	#define MG_TRIPOD_SLOT_CUP_M240 \
	class WeaponSlotsInfo: WeaponSlotsInfo \
	{ \
		class CowsSlot: CowsSlot \
		{ \
			compatibleItems[]= {"dzn_tripod_mg_nato"}; \
			linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL"; \
			iconPinpoint="center"; \
			iconPosition[] = {0.566,0.771}; \
			iconScale  = 0.64; \
			iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_ca.paa"; \
		}; \
	};
	
	#define MG_TRIPOD_SLOT_CUP_M249 \
	class WeaponSlotsInfo: WeaponSlotsInfo \
	{ \
		class CowsSlot: CowsSlot \
		{ \
			compatibleItems[]= {"dzn_tripod_mg_nato"}; \
			linkProxy = "\A3\Data_f_Mark\proxies\weapon_slots\UNDERBARREL"; \
			iconPinpoint="center"; \
			iconPosition[] = {0.457,0.807}; \
			iconScale  = 0.67; \
			iconPicture = "\dzn_MG_Tripod\data\ui\tripod_proxy_ca.paa"; \
		}; \
	};
	
	class Rifle_Base_F;
    class Rifle_Long_Base_F: Rifle_Base_F
	{
		class WeaponSlotsInfo;
        class GunParticles;
	};
	
	
	class CUP_lmg_M240: Rifle_Long_Base_F
	{
		MG_TRIPOD_SLOT_CUP_M240
	};
	
	class CUP_lmg_L7A2: CUP_lmg_M240 {};
	class CUP_lmg_L7A2_Flat: CUP_lmg_L7A2
	{
		MG_TRIPOD_SLOT_CUP_M240
	}
	class CUP_saw_base: Rifle_Long_Base_F
	{
		MG_TRIPOD_SLOT_CUP_M249
	};
	
	class LMG_Mk200_F: Rifle_Long_Base_F {};
	class rhs_weap_M249_base: LMG_Mk200_F {};
	class rhs_weap_m240_base: rhs_weap_M249_base
	{
		MG_TRIPOD_SLOT_CUP_M240
	};
};