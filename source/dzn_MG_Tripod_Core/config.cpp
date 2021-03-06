class CfgPatches
{
	class dzn_MG_Tripod_Core
	{
		units[] = {};
		weapons[] = {
			"dzn_MG_Tripod_Universal"
			,"dzn_MG_Tripod_M122A1_M240mount"
			,"dzn_MG_Tripod_M122A1_M60mount"
			,"dzn_MG_Tripod_M122A1_M240Mount_RHS"
			,"dzn_MG_Tripod_M122A1_M249Mount_RHS"

			,"dzn_MG_Tripod_Universal_Carry"
			,"dzn_MG_Tripod_M122A1_M240mount_Carry"
			,"dzn_MG_Tripod_M122A1_M60mount_Carry"
			/*
			,"dzn_MG_Tripod_M122A1_M240Mount_RHS_Carry"
			,"dzn_MG_Tripod_M122A1_M249Mount_RHS_Carry"
			*/
		};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"A3_Weapons_F"
			,"A3_Data_F"
			,"A3_Anims_F"
			,"CBA_MAIN"
			,"CBA_jr"
			,"dzn_MG_Tripod"
		};
		author = "10Dozen";
		version = "1.3";
	};
};

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
			allowedSlots[] = {};
			deployedPivot    = "bipod";       /// what point should be used to be on surface while unfolded
			hasBipod         = true;          /// bipod obviously has a bipod
			mass             = 165;            /// what is the mass of the object
			soundBipodDeploy[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_deploy", 0.70794576, 1, 20 };
			soundBipodFold[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_fold", 0.70794576, 1, 20 };
			soundBipodDown[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_down", 0.70794576, 1, 20 };
			soundBipodUp[] = { "A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_generic_up", 0.70794576, 1, 20 };
		};
		inertia = 2; // 1.25;

		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_Universal_Carry";
		dzn_MG_Tripod_CarryItemUniversal = "dzn_MG_Tripod_Universal_Carry";
	};
	class dzn_tripod_mg_nato: dzn_MG_Tripod_Universal
	{
		scope = 1; // Backward compatibility for previously used classname
		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_Universal_Carry";
	};
	class dzn_MG_Tripod_M122A1_M240Mount: dzn_MG_Tripod_Universal
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240";
		model="\dzn_MG_Tripod\nato_tripod_m122_m240.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";

		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_M122A1_M240Mount_Carry";
		dzn_MG_Tripod_CarryItemUniversal = "dzn_MG_Tripod_Universal_Carry";
	};
	class dzn_MG_Tripod_M122A1_M60Mount: dzn_MG_Tripod_Universal
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M60";
		model="\dzn_MG_Tripod\nato_tripod_m122_m60.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_m60_icon_ca.paa";

		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_M122A1_M60Mount_Carry";
		dzn_MG_Tripod_CarryItemUniversal = "dzn_MG_Tripod_Universal_Carry";
	};
	class dzn_MG_Tripod_M122A1_M240Mount_RHS: dzn_MG_Tripod_Universal
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240";
		model="\dzn_MG_Tripod\nato_tripod_m122_m240_rhs.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";

		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_M122A1_M240Mount_Carry";
		dzn_MG_Tripod_CarryItemUniversal = "dzn_MG_Tripod_Universal_Carry";
	};
	class dzn_MG_Tripod_M122A1_M249Mount_RHS: dzn_MG_Tripod_Universal
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240";
		model="\dzn_MG_Tripod\nato_tripod_m122_m249_rhs.p3d";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";

		dzn_MG_Tripod_CarryItem = "dzn_MG_Tripod_M122A1_M240Mount_Carry";
		dzn_MG_Tripod_CarryItemUniversal = "dzn_MG_Tripod_Universal_Carry";
	};

	// --- Carry item (Launcher slot)
	class dzn_MG_Tripod_Universal_Carry: Launcher_Base_F
	{
		scope=2;
		author="10Dozen";
		displayName="$STR_MG_Tripod_MGUniversalTripod";
		picture = "\dzn_MG_Tripod\data\ui\tripod_m122_icon_ca.paa";
		model="\dzn_MG_Tripod\nato_tripod_m122_carry.p3d";
		muzzles[] = {};
		magazines[] = {};
		modes[] = {};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			allowedSlots[] = {};
			mass = 165;
		};
		dzn_MG_Tripod_AttachItems[] = {
			"dzn_MG_Tripod_Universal",
			"dzn_MG_Tripod_M122A1_M240Mount",
			"dzn_MG_Tripod_M122A1_M60Mount",
			"dzn_MG_Tripod_M122A1_M240Mount_RHS",
			"dzn_MG_Tripod_M122A1_M249Mount_RHS"
		};
	};
	class dzn_MG_Tripod_M122A1_M240Mount_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M240_Carry";
		dzn_MG_Tripod_AttachItems[] = {
			"dzn_MG_Tripod_M122A1_M240Mount",
			"dzn_MG_Tripod_M122A1_M240Mount_RHS",
			"dzn_MG_Tripod_M122A1_M249Mount_RHS"
		};
	};
	class dzn_MG_Tripod_M122A1_M60Mount_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=1;
		author="10Dozen";
		displayName="$STR_MG_Tripod_M122Tripod_M60_Carry";
		dzn_MG_Tripod_AttachItems[] = {
			"dzn_MG_Tripod_M122A1_M60Mount"
		};
	};
	class dzn_MG_Tripod_M122A1_M240Mount_RHS_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=1;
		displayName="[SCOPED OUT]";
	};
	class dzn_MG_Tripod_M122A1_M249Mount_RHS_Carry: dzn_MG_Tripod_Universal_Carry
	{
		scope=1;
		displayName="[SCOPED OUT]";
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
		dzn_MG_Tripod_GestureHoldProneType3 	= "dzn_MG_Tripod_GestureHoldProneType3";
		dzn_MG_Tripod_GestureHoldCrouchType1	= "dzn_MG_Tripod_GestureHoldCrouchType1";
		dzn_MG_Tripod_GestureHoldCrouchType2	= "dzn_MG_Tripod_GestureHoldCrouchType2";
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
			dzn_MG_Tripod_GestureHoldProneType3[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType1[]		= {"dzn_MG_Tripod_GestureHoldCrouchType1","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType2[]		= {"dzn_MG_Tripod_GestureHoldCrouchType2","Gesture"};
		};
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions // _Prone
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"dzn_MG_Tripod_GestureHoldProneType1","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"dzn_MG_Tripod_GestureHoldProneType2","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType3[]		= {"dzn_MG_Tripod_GestureHoldProneType3","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType1[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType2[]		= {"","Gesture"};
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
			dzn_MG_Tripod_GestureHoldProneType3[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType1[]		= {"dzn_MG_Tripod_GestureHoldCrouchType1_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType2[]		= {"dzn_MG_Tripod_GestureHoldCrouchType2_Context","Gesture"};
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions // _Context
		{
			dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldProneType3[]		= {"","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType1[]		= {"dzn_MG_Tripod_GestureHoldCrouchType1_Context","Gesture"};
			dzn_MG_Tripod_GestureHoldCrouchType2[]		= {"dzn_MG_Tripod_GestureHoldCrouchType2_Context","Gesture"};

			class RifleAdjustFProneActions: RifleAdjustProneBaseActions
			{
				dzn_MG_Tripod_GestureHoldType1[]			= {"dzn_MG_Tripod_GestureHoldType1_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType2[]			= {"dzn_MG_Tripod_GestureHoldType2_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType3[]			= {"dzn_MG_Tripod_GestureHoldType3_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldType4[]			= {"dzn_MG_Tripod_GestureHoldType4_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldProneType1[]		= {"","Gesture"};
				dzn_MG_Tripod_GestureHoldProneType2[]		= {"","Gesture"};
				dzn_MG_Tripod_GestureHoldProneType3[]		= {"","Gesture"};
				dzn_MG_Tripod_GestureHoldCrouchType1[]		= {"dzn_MG_Tripod_GestureHoldCrouchType1_Context","Gesture"};
				dzn_MG_Tripod_GestureHoldCrouchType2[]		= {"dzn_MG_Tripod_GestureHoldCrouchType2_Context","Gesture"};
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
		 *	HoldType1 	-- default for CUP GMPG (M60, M240, etc) and A3 MGs
		 *	HoldType2	-- CUP M249 solid stock (a bit lower and rotated clockwise)
		 *	HoldType3	-- CUP M249 Para / PKM/PKP (a bit lower and not rotated)
		 *	HoldType4	-- somewhere between Type1 and Type 3 (suitable for IAR type mgs and assault rifles - RPK, MG36, etc).
		 */
		class dzn_MG_Tripod_GestureHoldType1: Default
		{
			file = "dzn_MG_Tripod_Core\anim\Hold\HoldType1.rtm";
			looped = 1;
			speed = 1;
			mask = "leftHand";
			leftHandIKBeg = 1;
			leftHandIKEnd = 1;
			leftHandIKCurve[] = {0};
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
		 *	HoldCrouchType1 	-- default for CUP GMPG (M60, M240, etc) and A3 MGs
		 *	HoldCrouchType2		-- CUP M249 (a bit lower and closer to shoulder)
		 */
		GESTURE_MACRO(HoldCrouchType1);
		GESTURE_MACRO(HoldCrouchType2);

		/*
		 *	HoldProneType1 	-- default prone (for all mgs, both CUP and A3)
		 *	HoldProneType2 	-- CUP M249 (or other MGs with stock close to shoulder)
		 *	HoldProneType3 	-- L86A2 specifc
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
		class dzn_MG_Tripod_GestureHoldProneType3: dzn_MG_Tripod_GestureHoldProneType1
		{
			file = "dzn_MG_Tripod_Core\anim\Hold\HoldProneType3.rtm";
		};
	};
};


/*****
	CUP

	Weapon					| Anim(Good)					| Prone						| Crouch
	-----------------------------------------------------------------------------------------------------------------------------------
	L110/M249Para			| HoldType3						| ProneType2				| CrouchType2
	M240					| HoldType1 					| ProneType1				| CrouchType1
	L86						| -- need special anim --
	M249					| HoldType2						| ProneType2				| CrouchType2
	M249 PIP Stock			| HoldType2						| ProneType2				| CrouchType2
	M60						| HoldType1						| ProneType1				| CrouchType2
	M60E4					| HoldType1						| ProneType1				| CrouchType2
	MG3						| HoldType1						| ProneType1				| CrouchType1
	MG36					| HoldType4						| ProneType1				|
	Mk48					| HoldType2						| ProneType2				| CrouchType2
	PKP						| HoldType3  					| ProneType2 ProneType1		| CrouchType2
	RPK74					| HoldType4						| ProneType1				|
	XM8 SAW					| HoldType4						| 							|

	### Vanilla
	RPK12					| HoldType1						| ProneType1				| CrouchType1 (but ok w/o)
	Zafir					| HoldType1						| ProneType1				| CrouchType1
	Mk200					| HoldType1						| ProneType1				| CrouchType1

	arifle_MX_SW_F			| -								|  ProneType2				| -
	LMG_03_F (LIM85)		| HoldType3						|  ProneType1				| CrouchType2
	arifle_RPK12_F			| -								|  ProneType1				| -
	arifle_MXM_F			| -								|  ProneType1				| -
*/