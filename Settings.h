// Header File for Setting Functions
#ifndef _SETTINGS_h
#define _SETTINGS_h

// Enter Desired Refresh Rate in Hz
// Double the refresh rate of your monitor is ideal but anything over 480 Hz will not be noticable nor beneficial because the IR and Touch sensors can only respond as fast as about 2 ms anyway.
// Running at very high refresh rates may also occasionally introduce false inputs so I would recommend sticking with the convention above.
// Minimum is 1 Hz and Maximum is 1 kHz (1000 Hz) anything beyond these ranges will be ignored and restored to default
// Default is 240 Hz
int refresh = 360;

// Enter Desired Keyboard Layout
// 1. Tasoller (Default)
// 2. UMIGURI
// 3. Yuancon
// 4. Custom (You will need to configure this first! Go to layoutset() in layout.h)
int layout = 1;

// Enter Desired Slider Output Mode
// By Default the output behavior follows Raw Mode which outputs the assigned key individually with no additional logic used.
// 32 Key Logic Mode means when either key is pressed the primary key is activated and when both are pressed a secondary key is also activated.
// 16-Key mode locks output to only the primary 16 keys disabling 2 finger detection entirely, but may be used if either 32-key mode causes input issues.
// 1. 32-Key Raw Mode (Default)
// 2. 32-Key Logic Mode
// 3. 16-Key Mode (NOT FUNCTIONING RN)
int touchmode = 2;

// Enter Desired Function Key Layout (Disable Key will override Function Key 4 by default)
// 1. F1-F4 (Default)
// 2. F1-F3 + Disable
// 3. F1, F3, Numpad_Enter + Disable
// 4. Custom (You will need to configure this first! Go to layoutset() in layout.h)
int flayout = 3;

// Enter Desired Disable Key Behavior (If you don't use Function Key Layout 2 then it will be OFF by default)
// Pressing the Disable Key will only disable the keyboard OUTPUT the sensors will continue to refresh in the background
// 1. Disable Slider only
// 2. Disable IR only
// 3. Disable Slider and IR only (Recommended)
// 4. Disable Slider, IR, and Function Keys
// 5. OFF (Default)
int disablekey = 5;

// Enter Desired Touch Disable Cooldown in seconds
// Minimum is 1 second
// Default is 2
int disablecd = 2;

// Select Debug Mode 
// Debug mode outputs debug data to Arduino Serial Monitor
// By default it will also disable all keyboard output, set debugoutput to 1 to enable keyboard output while in debug mode
// Mode 1 is NOT recommended for most applications (Especially if the refresh rate is over 20 Hz) but is an option just in case you need it (I still don't know why you would. You like pretty numbers go brrrr maybe)
// 0. OFF (Default)
// 1. Mode 1 (Run Sensor Debugger at chosen refresh rate)
// 2. Mode 2 (Run Sensor Debugger at recommended refresh rate) 
// 3. Mode 3 (Run Full Debugger at a much slower speed)
// 4. Mode 4 (Slider only debug at recommended refresh rate)
// 5. Mode 5 (IR only debug at recommended refresh rate)
int debugmode = 0;
bool debugoutput = 0;

// Disable Slider output variable (Can be used as an Global Override, if set to 1)
bool touchdisable = 0;

// Disable IR output variable (Can be used as an Global Override, if set to 1)
bool irdisable = 0;

// Disable Function button output variable (Can be used as an Global Override, if set to 1)
bool funcdisable = 1;

// Calibration Lock (Enable if you do not want the default auto-calibration behavior of the MPR121)
// Locking calibration is useful for ensuring that when hands are just hovering over the slider, the MPR121 doesn't readjust sensitivity and prevent the keys from working properly until it slowly normalizes calibration values.
// This may also help when using the controller with gloves. Default offset is 4 counts (0x01) (This can be changed manually in MPR121Touch.h)
// You will need to go to Adafruit_MPR121.cpp in your library folder and change "byte ECR_SETTING = B10000000 + 12" (line 108) 
//                                                                           to "byte ECR_SETTING = B01000000 + 12"
//                                                                                        OR
// Use the block of code I provided in MPR121Touch.h to add custom definitions and uncomment the desired mode.
//
// It is STRONGLY RECOMMEDED that you note the original value in a comment beside the line in case default behavior needs to be restored if you are not using the custom definitions.
// Then set the variable below to 1. This will be 0 by default.
bool mprcl = 1;

#endif
