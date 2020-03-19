# dzn_MG_Tripod (A3)
Tripod attachement for machine guns & gesture switch system.

Workshop: https://steamcommunity.com/sharedfiles/filedetails/?id=1713801249

Adds universal tripod attachement for machine guns (Mk200, Navid, SPMG).
Adds gesture switch script for MGs and sniper rifles

**Version:** 1.3

**Requirements:** CBA_A3

**Features:**
- Universal tripod attachement 
- Deployed tripod affects weapon recoil and sway, making machine gun more accurate at long ranges
- Hand gesture switch for deployed state

[code]
Weapon				Tripod		Gesture stance
-----------------------------------------------
Mk200 6.5 mm		Yes			All
Navid 9.3 mm		Yes			All
SPMG .338			Yes			All
Zafir 7.62 mm		No			All
LIM-85 5.56 mm		No			All
MX SW 6.5 mm		No			Prone only
MXM 6.5 mm			No			Prone only
RPK-12 7.62 mm		No			Prone only
Mk18 ABR 7.62 mm	No			Prone only 
GM6 Lynx 12.7 mm	No			Prone only 
M320 LRR .408		No			Prone only 
ASP-1 Kir 12.7 mm	No			Prone only 
Cyrus 9.3 mm		No			Prone only 
MAR-10 .338			No			Prone only 
Mk-I EMR 7.62 mm	No			Prone only 
Mk14 7.62 mm		No			Prone only 
CMR-76 6.5 mm		No			Prone only 
Promet MR 6.5 mm	No			Prone only 
[/code]

#### License: APL-SA

**Credits:** 10Dozen

**Notes:**

- Weapon sway and recoil effect may be set up at
- Hand gesture may be disabled for specific stance


# dzn_MG_Tripod (CUP)

Adds weapon specific tripods compatible to CUP machine guns.
Adds gesture switch script for MGs and sniper rifles.

**Requirements:** CBA_A3, dzn_MG_Tripod, CUP Weapons

[code]
Weapon				Tripod		Gesture stance
-----------------------------------------------
M240/MAG/L7			Yes			All
M249/Minimi/L110	Yes			All
Mk.48				Yes			All
M60/M60E4			Yes			All
MG3					Yes			All
PKM/PKP				Yes			All

AS50				No			Prone only
MG36				No			Prone only
XM8 SAW				No			Prone only
L129A1				No			Prone only
M14/M14 DMR			No			Prone only
M107				No			Prone only
M110				No			Crouch/Prone
VSS Vintorez/AS Val	No			Prone only
RPK/RPK-74/PKM-74M	No			Prone only
[/code]


# dzn_MG_Tripod (RHSUSAF)

Adds weapon specific tripods compatible to RHS machine guns.

**Requirements:** CBA_A3, dzn_MG_Tripod, CUP Weapons

[code]
Weapon				Tripod		Gesture stance
-----------------------------------------------
M240B/G				Yes			No
M249/Minimi			Yes			No
[/code]

Changelog:
v1.3
- Reworked Carry item to Attach item conversion; now single tripod carry item may be compatible with vanilla, CUP and RHS (actual attach item selected dynamically)
- Fixed binocular unavailability when used while gesture applied
- Temporary fix for loadout EH

v1.2
- Added Gesture switch system
- Added Tripod mount/dismount mechanics
- Added tripod compatibility with A3 machine guns
- Added tripod compatibility with RHS machine guns
- Added gesture compatibility with A3 sniper rifles and IARs
- Added gesture compatibility with CUP sniper rifles and IARs

v1.1
- First public release: tripod compatible with CUP machineguns
