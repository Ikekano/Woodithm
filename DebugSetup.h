// Header File for setting up Debug Functions
#ifndef _DEBUGSETUP_h
#define _DEBUGSETUP_h

// Debug Variables
String layoutname; // Holds selected layout name
String flayoutname; // Holds selected flayout name
String diskeyname; // Holds selected disable key name

String layoutoverride; // Holds if layout was defaulted
String touchmodeoverride; // Holds if touchmode was defaulted
String flayoutoverride; // Holds if flayout was defaulted
String diskeyoverride; // Holds if disable key was defaulted

String slideroverride; // Holds Slider override if selected
String iroverride; // Holds IR override if selected
String funcoverride; // Holds Function override if selected

String refreshoverride; // Holds refresh rate override
String cdoverride; // Holds disable cd override

// Debug Overrides
bool touchdisableor = 0;
bool irdisableor = 0;
bool funcdisableor = 0;

// Debug flags for each MPR121 Board if there is an error initializing
bool touch404B1 = 0;
bool touch404B2 = 0;
bool touch404B3 = 0;

// Debug flags for if config is defaulted (Usually when an invalid number is entered)
bool refreshdefault = 0;
bool layoutdefault = 0;
bool tmdefault = 0;
bool flayoutdefault = 0;
bool diskeydefault = 0;
bool disablecddefault = 0;

// Invalid function key checks
bool funckeyerror = 0;

// Fill Character for Debug Output
char charspacer = '-';

#endif
