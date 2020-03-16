class CfgPatches
{
	class dzn_MG_Tripod_CUP_RifleGestures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"CUP_Weapons_AK"
			,"CUP_Weapons_AS50"
			,"CUP_Weapons_G36"
			,"CUP_Weapons_L129"
			,"CUP_Weapons_M14"
			,"CUP_Weapons_M14_DMR"
			,"CUP_Weapons_M110"
			,"CUP_Weapons_M107"
			,"CUP_Weapons_VSS"
			,"CUP_Weapons_L85"
			,"dzn_MG_Tripod_Core"
		};
		author = "10Dozen";
		version = "1.3";
	};
};

#define DEPLOYED_GESTURE_PRONE_TYPE1 \
	dzn_MG_Tripod_deployedGesture[] = {"","","dzn_MG_Tripod_GestureHoldProneType1"}
	
#define DEPLOYED_GESTURE_PRONE_TYPE2 \
	dzn_MG_Tripod_deployedGesture[] = {"","","dzn_MG_Tripod_GestureHoldProneType2"}
	
#define DEPLOYED_GESTURE_CROUCH_PRONE_TYPE1 \
	dzn_MG_Tripod_deployedGesture[] = {"","dzn_MG_Tripod_GestureHoldCrouchType1","dzn_MG_Tripod_GestureHoldProneType1"}
	
#define DEPLOYED_GESTURE_CROUCH_PRONE_TYPE2 \
	dzn_MG_Tripod_deployedGesture[] = {"","dzn_MG_Tripod_GestureHoldCrouchType2","dzn_MG_Tripod_GestureHoldProneType2"}
	
#define DEPLOYED_GESTURE_CROUCH_PRONE_TYPE21 \
	dzn_MG_Tripod_deployedGesture[] = {"","dzn_MG_Tripod_GestureHoldCrouchType2","dzn_MG_Tripod_GestureHoldProneType1"}
	
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
		class EventHandlers;
	};
	class Rifle_Long_Base_F: Rifle_Base_F {};
	
	// --- CUP Rifles
	// --- ------------------------------
	
	// --- RPK
	class CUP_arifle_AK_Base: Rifle_Base_F {};
	class CUP_arifle_RPK74: CUP_arifle_AK_Base
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- AS50
	class CUP_srifle_AS50: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- MG36
	class CUP_arifle_G36_Base: Rifle_Base_f {};
	class CUP_arifle_G36C: CUP_arifle_G36_Base {};
	class CUP_arifle_MG36: CUP_arifle_G36C
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- L86
	class CUP_l85a2_base: Rifle_Base_F {};
	class CUP_l85a2: CUP_l85a2_base {};
	class CUP_arifle_L86A2: CUP_l85a2
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- L129
	class CUP_srifle_L129A1: Rifle_Base_F
	{
		DEPLOYED_GESTURE_CROUCH_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- M14 & M14 DMR
	class CUP_srifle_M14: Rifle_Base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	class CUP_srifle_M14_DMR: Rifle_Base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- M110 (PRS and KAC stock)	
	class CUP_srifle_M110: Rifle_Base_F
	{
		DEPLOYED_GESTURE_CROUCH_PRONE_TYPE21;
		RELOAD_EH;
	};
	class CUP_srifle_m110_kac: CUP_srifle_M110
	{
		DEPLOYED_GESTURE_CROUCH_PRONE_TYPE2;
		RELOAD_EH;
	};
	
	// --- M107
	class CUP_srifle_M107_Base: Rifle_Long_Base_F
	{
		DEPLOYED_GESTURE_CROUCH_PRONE_TYPE2;
		RELOAD_EH;
	};
	
	// --- VSS Vintorez & AS Val
	class CUP_srifle_VSSVintorez: Rifle_Base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	// --- XM8 SAW
	class CUP_arifle_XM8_Base;
	class CUP_arifle_xm8_sharpshooter: CUP_arifle_XM8_Base
	{
		class EventHandlers;
	};
	class CUP_arifle_xm8_SAW: CUP_arifle_xm8_sharpshooter
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
};