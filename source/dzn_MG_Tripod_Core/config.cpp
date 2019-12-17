class CfgPatches
{
	class dzn_MG_Tripod_Core
	{
		units[] = {};
		weapons[] = {
			"dzn_MG_Tripod_Universal"
			,"dzn_MG_Tripod_M122A1_M240mount"
			,"dzn_MG_Tripod_M122A1_M60mount"
			
			,"dzn_MG_Tripod_Universal_Carry"
			,"dzn_MG_Tripod_M122A1_M240mount_Carry"
			,"dzn_MG_Tripod_M122A1_M60mount_Carry"
		};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"A3_Weapons_F"
			,"A3_Data_F"
			,"A3_Anims_F"
			,"CBA_MAIN"
			,"CBA_jr"
			,"dzn_MG_Tripod"
			,"dzn_MG_Tripod_A3"
			,"dzn_MG_Tripod_CUP"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

class Extended_PostInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		// init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod_Core\Init.sqf";
	};
};
class Extended_PreInit_EventHandlers
{
	class dzn_MG_Tripod
	{
		// init = call compile preprocessFileLineNumbers "\dzn_MG_Tripod_Core\Settings.sqf";
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

class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		dzn_MG_Tripod_GestureHoldType1			= "dzn_MG_Tripod_GestureHoldType1";
		dzn_MG_Tripod_GestureHoldType2			= "dzn_MG_Tripod_GestureHoldType2";
		dzn_MG_Tripod_GestureHoldType3			= "dzn_MG_Tripod_GestureHoldType3";
		dzn_MG_Tripod_GestureHoldType4			= "dzn_MG_Tripod_GestureHoldType4";
		dzn_MG_Tripod_GestureHoldProneType1		= "dzn_MG_Tripod_GestureHoldProneType1";
		dzn_MG_Tripod_GestureHoldProneType2		= "dzn_MG_Tripod_GestureHoldProneType2";
	};
	class Actions
	{
		class NoActions: ManActions
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};
		};
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions // _Prone
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldProneType1","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldProneType2","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldProneType2","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldProneType1","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"dzn_MG_Tripod_GestureHoldProneType1","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"dzn_MG_Tripod_GestureHoldProneType2","Gesture"};
		};
		class RifleAdjustProneBaseActions;
		class RifleAdjustRProneActions: RifleAdjustProneBaseActions // _Context
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions // _Context
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};

			class RifleAdjustFProneActions: RifleAdjustProneBaseActions
			{
				dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
				dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};
			};
		};
	};
};

#define GESTURE_MACRO(X)	\
	class dzn_MG_Tripod_Gesture##X: dzn_MG_Tripod_GestureHoldType1 { file = dzn_MG_Tripod_Core\anim\Hold\##X##.rtm; }; \
	class dzn_MG_Tripod_Gesture##X##_Context: dzn_MG_Tripod_Gesture##X { mask = "handsWeapon_context"; }

class CfgGesturesMale
{
	class Default;
	class States
	{
		/*
		 *	HoldType1 	-- default for CUP GMPG (M60, M249, etc) and A3 MGs
		 *	HoldType2	-- CUP M249 solid stock (a bit lower and rotated clockwise)
		 *	HoldType3	-- CUP M249 Para / PKM/PKP (a bit lower and not rotated)
		 *	HoldType4	-- a bit higher than default (suitable for IAR type mgs and assault rifles - RPK, MG36, etc).
		 */
		class dzn_MG_Tripod_GestureHoldType1: Default
		{
			file = "dzn_MG_Tripod_Core\anim\Hold\HoldType1.rtm";
			looped = 1;
			speed = 1;
			mask = "leftHand";
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
			leftHandIKCurve[] = {0.0};
			enableOptics = 1;
			canPullTrigger = 1;
			disableWeapons = 0;
		};
		class dzn_MG_Tripod_GestureHoldType1_Context: dzn_MG_Tripod_GestureHoldType1
		{
			mask = "handsWeapon_context";
		};
		
		GESTURE_MACRO(HoldType2);
		GESTURE_MACRO(HoldType3);
		GESTURE_MACRO(HoldType4);		
		
		/*
		 *	HoldProneType1 	-- default prone (for all mgs, both CUP and A3)
		 *	HoldProneType2 	-- CUP M249 (or other MGs with stock close to shoulder)
		 */
		class dzn_MG_Tripod_GestureHoldProneType1: Default
		{
			file = "dzn_MG_Tripod_Core\anim\Hold\HoldProneType1.rtm";
			looped = 1;
			speed = 1;
			mask = "leftHand"; 
			leftHandIKBeg = 1;
			leftHandIKCurve[] = {0};
			leftHandIKEnd = 1;
			enableOptics = 1;
			canPullTrigger = 1;
			disableWeapons = 0;
		};
		class dzn_MG_Tripod_GestureHoldProneType2: dzn_MG_Tripod_GestureHoldProneType1
		{
			file = "dzn_MG_Tripod_Core\anim\Hold\HoldProneType2.rtm";
		};
	};
};

/*****
	Weapon					| Anim(Good)									| Prone
	----------------------------------------------------------------------------------------------------
	L110/M249Para			| HoldTop3										| _v16
	M240					| HoldTop1 										| 
	L86						| -- need special anim --						| 
	M249					| HoldTop2										| _v16
	M249 PIP Stock			| HoldTop2										| _v16
	M60						| HoldTop1										| _v17
	M60E4					| HoldTop1										| _v17
	MG3						| HoldTop1										| _v17
	MG36					| HoldTop4										| 
	Mk48					| HoldTop2										| _v16
	PKP						| HoldTop3  									| _v16 _v17
	RPK74					| HoldTop4										| _v17
	XM8 SAW					| HoldTop4										| 
	
	### Vanilla 
	RPK12					| HoldTop1										| _v17
	Zafir					| HoldTop1										| 
	Mk200					| HoldTop1										| 

	Top1 - Type1
	Top2 - Type2
	Top3 - Type3
	Top4 - Type4
	
	_v17 -- ProneType1
	_v16 -- ProneType2
	
	Mk12 | HoldTop4
	SR25 | HoldTop1
	
	ProneAnim:
		_v12 	- is +-OK
		_v15	- is +-OK (better)
		
		
		_v16 	- Per
	
	dzn_classes = [
		"CUP_lmg_L110A1"
		, "CUP_lmg_L7A2"
		, "CUP_arifle_L86A2"
		, "CUP_lmg_m249_pip1"
		, "CUP_lmg_m249_pip3"		
		, "CUP_lmg_M60"
		, "CUP_lmg_M60E4_norail"		
		, "CUP_lmg_MG3_rail"		
		, "CUP_arifle_MG36_camo"		
		, "CUP_lmg_Mk48_nohg_od"		
		, "CUP_lmg_Pecheneg"
		, "CUP_arifle_RPK74M"
		, "CUP_arifle_xm8_SAW"
		
		
		, "arifle_RPK12_lush_F"
		, "LMG_Zafir_F"
		, "LMG_Mk200_F"
	];
	
	{
		player addAction [" ## " + _x, { params ["", "", "", "_w"]; [player, _w, 3] call BIS_fnc_addWeapon; }, _x];
	} forEach dzn_classes;
	
	player playAction "dzn_MG_Tripod_GestureHoldM240";

*/