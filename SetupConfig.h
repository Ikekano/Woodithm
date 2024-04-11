// Header File for Setup Config Functions
#ifndef _SETUPCONFIG_h
#define _SETUPCONFIG_h

#include "Settings.h"

// Touch Array Definition
// The array below holds v and i values for the slider keys in the touch array.
// If you are wiring the function keys to different touchpads then you MUST change the values in this array!!
//
// Array is ordered from Cells 1-32 going LEFT TO RIGHT!!
//
// Board 1 = 0   Board 2 = 1   Board 3 = 2
//
// Each Board's silkscreen text should be upside down with Pad 0 on the left and Pad 11 on the right
// 
// Format = {{Board for Cells 1-32},
//           {Pad  for  Cells 1-32}};
//
// Original Cell Order
//int Slidertouchpads[2][32] = {{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2},
//                              {9,8,7,6,5,4,3,2,1,0,11,10,9,8,7,6,5,4,3,2,1,0,11,10,9,8,7,6,5,4,3,2}};
//
// Top Row Right to Left, Bottom Row Right to Left
int Slidertouchpads[2][32] = {{0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2},
                              {9,4,8,3,7,2,6,1,5,0,11,5,10,4,9,3,8,2,7,1,6,0,11,6,10,5,9,4,8,3,7,2}};


// IR Pin Config
int IRarraypins[6] = {D1,D2,D3,D8,D9,D10};

// Touch Array Definition
// The array below holds v and i values for the function keys in the touch array. 
// If you are wiring the function keys to different touchpads then you MUST change the values in this array!!
//
// Default Array Coordinates:
// Left - {2,0}
// Back Left - {2,1}
// Back Right - {0,10}
// Right - {0,11}
//
// Array is ordered F1 - F4 {{F1x,F2x,F3x,F4x},{F1y,F2y,F3y,F4y}}
//
// You MUST uncomment one of the configurations below or make your own
//
// int Functouchpads[2][4] = {{2,2,0,0},
//                            {0,1,10,11}}; //   <     F1     - ^F2 - F3^ - (Lock / F4)>
//
// int Functouchpads[2][4] = {{2,0,0,2},
//                            {1,10,11,0}}; //   <     F3     - ^F1 - F2^ - (Lock / F4)>
//
int Functouchpads[2][4] = {{2,0,0,2},
                           {1,10,11,0}}; //   <(Lock / F4) - ^F1 - F2^ -     F3     >
                  
// Key Array Definition
char keys[40];
String fkeys[5];

// Unit Conversion Variables
static int rr = 1000/refresh; // Sets loop delay converted from Hz

static int discd = disablecd*1000; // Sets cooldown time converted from seconds

#endif
