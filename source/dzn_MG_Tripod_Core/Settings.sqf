#include "macro.hpp"

// Addon Settings

private _add = {
	params ["_var","_type","_val",["_exp", "No Expression"],["_subcat", ""],["_isGlobal",1],["_needRestart", false]];	
	 
	private _arr = [
		format["dzn_%1_%2",ADDON,_var]
		, _type
		, [localize format["STR_%1_%2",ADDON,_var], localize format ["STR_%1_%2_desc",ADDON,_var]]
		, if (_subcat == "") then { TITLE } else { [TITLE, _subcat] }
		, _val
		, _isGlobal
		, nil
		, _needRestart
	];
	
	if !(typename _exp == "STRING" && { _exp == "No Expression" }) then { _arr pushBack _exp; };
	_arr call CBA_fnc_addSetting;
};


// Settings 
// --- Tripod
[
	"Enabled"
	, "CHECKBOX"
	, true
	, nil
	, "Tripod"
] call _add;

[
	"DeployedAimCoef"
	, "SLIDER"
	, [0,1,0.1,2]
	, nil
	, "Tripod"
] call _add;

[
	"DeployedRecoilCoef"
	, "SLIDER"
	, [0,1,0.1,2]
	, nil
	, "Tripod"
] call _add;

[
	"FallbackToUniversal"
	, "CHECKBOX"
	, false
	, nil
	, "Tripod"
] call _add;

// --- Gesture
[
	"Enabled_StandGesture"
	, "CHECKBOX"
	, true
	, nil
	, "Gesture"
	, 0
] call _add;

[
	"Enabled_CrouchGesture"
	, "CHECKBOX"
	, true
	, nil
	, "Gesture"
	, 0
] call _add;

[
	"Enabled_ProneGesture"
	, "CHECKBOX"
	, true
	, nil
	, "Gesture"
	, 0
] call _add;
