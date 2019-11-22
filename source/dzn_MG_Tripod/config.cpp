class CfgPatches
{
	class dzn_MG_Tripod
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"A3_Weapons_F",
			"A3_Data_F",
			"A3_Anims_F"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		dzn_MG_Tripod_GestureHoldGMPG = "dzn_MG_Tripod_GestureHoldGMPG";
	};
	class Actions
	{
		class NoActions: ManActions
		{
			dzn_MG_Tripod_GestureHoldGMPG[] = {"dzn_MG_Tripod_GestureHoldGMPG","Gesture"};
		};
		class RifleBaseStandActions;
		class RifleProneActions: RifleBaseStandActions
		{
			dzn_MG_Tripod_GestureHoldGMPG[] = {"dzn_MG_Tripod_GestureHoldGMPG_Prone","Gesture"};
		};
		class RifleAdjustProneBaseActions;
		class RifleAdjustRProneActions: RifleAdjustProneBaseActions
		{
			dzn_MG_Tripod_GestureHoldGMPG[] = {"dzn_MG_Tripod_GestureHoldGMPG_Context","Gesture"};
		};
		class RifleAdjustLProneActions: RifleAdjustProneBaseActions
		{
			dzn_MG_Tripod_GestureHoldGMPG[] = {"dzn_MG_Tripod_GestureHoldGMPG_Context","Gesture"};
			class RifleAdjustFProneActions: RifleAdjustProneBaseActions
			{
				dzn_MG_Tripod_GestureHoldGMPG[] = {"dzn_MG_Tripod_GestureHoldGMPG_Context","Gesture"};
			};
		};
	};
};

class CfgGesturesMale
{
	class Default;
	class States
	{
		class dzn_MG_Tripod_GestureHoldGMPG: Default
		{
			file = "dzn_MG_Tripod\anim\HoldGPMG\HoldGPMG.rtm";
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
		class dzn_MG_Tripod_GestureHoldGMPG_Prone: Default
		{
			file = "dzn_MG_Tripod\anim\HoldGPMG\HoldGPMG_prone.rtm";
		};
		class dzn_MG_Tripod_GestureHoldGMPG_Context: dzn_MG_Tripod_GestureHoldGMPG
		{
			mask = "handsWeapon_context";
		};
	};
};