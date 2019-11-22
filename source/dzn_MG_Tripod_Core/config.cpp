class CfgPatches
{
	class dzn_MG_Tripod_Core
	{
		units[] = {};
		weapons[] = {
			"dzn_MG_Tripod_Universal"
			,"dzn_MG_Tripod_m240mount"
			,"dzn_MG_Tripod_m60mount"
			,"dzn_MG_Tripod_Universal_Carry"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"CBA_jr"
			,"dzn_MG_Tripod"
			,"dzn_MG_Tripod_A3"
			,"dzn_MG_Tripod_CUP"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

/*
class Extended_PostInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod_Core\Init.sqf";
	};
};
class Extended_PreInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod_Core\Settings.sqf";
	};
};
*/

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
	class dzn_MG_Tripod_Universal: ItemCore
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
		inertia = 2; // 1.25; 
		
		class dzn_MGTripodInfo 
		{
			item = "";
			carry = "dzn_MG_Tripod_Universal_Carry";
			isCarry = 0;
			isAttach = 1;
		};
	};
	class dzn_tripod_mg_nato: dzn_MG_Tripod_Universal 
	{
		scope = 1; // Backward compatibility for previous used classname
	};
	class dzn_MG_Tripod_m240mount: dzn_MG_Tripod_Universal
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240";
		model="\dzn_MG_Tripod\nato_tripod_m122_m240.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";
	};
	class dzn_MG_Tripod_m60mount: dzn_MG_Tripod_Universal
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M60";
		model="\dzn_MG_Tripod\nato_tripod_m122_m60.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_m60_icon_ca.paa";
	};
	
	// --- Carry item (Launcher slot)
	class dzn_MG_Tripod_Universal_Carry: Launcher_Base_F
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
			item = "dzn_MG_Tripod_Universal";
			carry = "";
			isCarry = 1;
			isAttach = 0;
		};
	};
};