#include "macro.hpp"

// Addon Settings

private _add = {
	params ["_var","_type","_val",["_exp", "No Expression"],["_subcat", ""],["_needRestart", false]];	
	 
	private _arr = [
		format["dzn_%1_%2",ADDON,_var]
		, _type
		, [localize format["STR_%1_%2",ADDON,_var], localize format ["STR_%1_%2_desc",ADDON,_var]]
		, if (_subcat == "") then { TITLE } else { [TITLE, _subcat] }
		, _val
		, true
		, nil
		, _needRestart
	];
	
	if !(typename _exp == "STRING" && { _exp == "No Expression" }) then { _arr pushBack _exp; };
	_arr call CBA_fnc_addSetting;
};


// Settings 
[
	"Enabled"
	, "CHECKBOX"
	, true
	, true
] call _add;

[
	"DeployedAimCoef"
	, "SLIDER"
	, [0,1,0.1,2]
] call _add;

[
	"DeployedRecoilCoef"
	, "SLIDER"
	, [0,1,0.1,2]
] call _add;