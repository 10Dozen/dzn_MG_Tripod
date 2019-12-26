class CfgPatches
{
	class dzn_MG_Tripod_A3_RifleGestures
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {
			"CBA_MAIN"
			,"dzn_MG_Tripod_Core"
		};
		author = "10Dozen";
		version = "1.2";
	};
};

#define DEPLOYED_GESTURE_PRONE_TYPE1 \
	dzn_MG_Tripod_deployedGesture[] = {"","","dzn_MG_Tripod_GestureHoldProneType1"}
	
#define DEPLOYED_GESTURE_PRONE_TYPE2 \
	dzn_MG_Tripod_deployedGesture[] = {"","","dzn_MG_Tripod_GestureHoldProneType2"}
	
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
	
	// --- Vanilla Rifles
	// --- ------------------------------
	class arifle_MX_Base_F: Rifle_Base_F {};
	class arifle_MX_SW_F: arifle_MX_Base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE2;
		RELOAD_EH;
	};
	class arifle_MXM_F: arifle_MX_Base_F {
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class arifle_AK12_base_F: Rifle_Base_F {};
	class arifle_RPK12_base_F: arifle_AK12_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class EBR_base_F: Rifle_Long_Base_F {};
	class srifle_EBR_F: EBR_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class GM6_base_F: Rifle_Long_Base_F {};
	class srifle_GM6_F: GM6_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class LRR_base_F: Rifle_Long_Base_F {};
	class srifle_LRR_F: LRR_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_04_base_F: Rifle_Long_Base_F {};
	class srifle_DMR_04_F: DMR_04_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_05_base_F: Rifle_Long_Base_F {};
	class srifle_DMR_05_blk_F: DMR_05_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_02_base_F: Rifle_Long_Base_F {};
	class srifle_DMR_02_F: DMR_02_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_03_base_F: Rifle_Long_Base_F {};
	class srifle_DMR_03_F: DMR_03_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_06_base_F: Rifle_Long_Base_F {};
	class srifle_DMR_06_camo_F: DMR_06_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_07_base_F: Rifle_Long_Base_F {};	
	class srifle_DMR_07_blk_F: DMR_07_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
	
	class DMR_06_hunter_base_F: DMR_06_base_F {};
	class srifle_DMR_06_hunter_F: DMR_06_hunter_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	}; 
	
	class arifle_MSBS65_base_F: Rifle_Base_F {};
	class arifle_MSBS65_Mark_base_F: arifle_MSBS65_base_F
	{
		DEPLOYED_GESTURE_PRONE_TYPE1;
		RELOAD_EH;
	};
};