// Header File for Touch Slider Functions
#ifndef _TOUCHSLIDER_h
#define _TOUCHSLIDER_h

#include "HID-Project.h"
#include "SetupConfig.h"
#include "DebugSetup.h"
#include "Layout.h"

      // NOTE: Touch keys will follow numbering FROM RIGHT TO LEFT!!! and are divided into groups of 2 touchpads PER KEY
      //       There are 6 KEYS PER MPR121 BOARD totalling 16 KEYS and 36 TOTAL touchpads
      //       There will be 4 extra touchpads for extra function keys
      //
      //       Each cell is comment labeled in the format of: 
      //       <touch key number><touch key output A or B> Cell<cell number>
      //    Ex:         1                 A                Cell01            ->  1A Cell01
      //
      //       Default layout follows the 32-cell tasoller keyboard layout or can be found on the slidershim github found here: https://github.com/4yn/slidershim/blob/main/res/layouts/layout.png
      //       Note there is a slight error in the tasoller layout for IR 5 and 6. IR 5 should be ] and IR 6 should be [

      // NOTE: Since there are 36 total inputs and only 32 are for the slider there will be 4 extras which I will be using for extra function buttons
      //       Keys are numbered from Right to Left!! to stay consistent with the entire file
      //       The function buttons are complete optional, but are nice to have
      //       With the capacitive pads of each board facing towards the keys (Pad 0 is on the left, Pad 11 is on the right) the layout will be as such:
      //
      //          Board3     ============     Board 2     ============     Board 1     ============     Seeduino Xiao
      //    Pad 0 - Lock Key            Pad 0-11 - Keys 11-6         Pad 0-9 - Keys 5-1
      //    Pad 1 - Func. 1                                          Pad 10 - Func. 2
      //    Pad 2-11 - Keys 16-12                                    Pad 11 - Func. 3

// Bit value definition (From MPR121 Example)
#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

// Variable Definitions for each MPR121 Board on the i2c bus
Adafruit_MPR121 touch[3] = {Adafruit_MPR121(),Adafruit_MPR121(),Adafruit_MPR121()};

// Array Definition for all 3 Boards
int toucharray[3][12];

// Variable Definitions for past and present touch states
uint16_t last1 = 0;
uint16_t current1 = 0;

uint16_t last2 = 0;
uint16_t current2 = 0;

uint16_t last3 = 0;
uint16_t current3 = 0;

// Array Definition for slider
int sliderfarray[32];
int sliderarray[2][16];
char slideroutarray[2][16];

void SliderRead()
{
  for (int i = 0; i < 32; i++)
    {
        sliderfarray[i] = toucharray[Slidertouchpads[0][i]][Slidertouchpads[1][i]];
    }

    for (int i = 15, e = 1, o = 0; i >= 0 ; i--, e += 2, o += 2)
    {
        sliderarray[0][i] = sliderfarray[o];
        sliderarray[1][i] = sliderfarray[e];
    }
}

void SliderOut()
{
  if (touchdisable == 0 && touchdisableor == 0)
    {
          ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 1 (0x5A) //////////////////////////////////////////////////////////////////////////////////////////////////

          ////////////////////////////////////////////////////////// Touch Key 1

          ////////////////////////////////// 1A Cell01
          if (touchmode == 1)
          {
                if (sliderfarray[0] == 1 && sliderfarray[1] == 1)
                {
                      slideroutarray[0][15] = keys[1];
                      NKROKeyboard.press(keys[1]);
                }
                else
                {
                      slideroutarray[0][15] = charspacer;
                      NKROKeyboard.release(keys[1]);
                }
          }
          ////////////////////////////////// 1B Cell02
          if (sliderfarray[0] == 1 || sliderfarray[1] == 1)
          {
                slideroutarray[1][15] = keys[2];
                NKROKeyboard.press(keys[2]);
          }
          else
          {
                slideroutarray[1][15] = charspacer;
                NKROKeyboard.release(keys[2]);
          }
          ////////////////////////////////////////////////////////// Touch Key 1 End
          
          ////////////////////////////////////////////////////////// Touch Key 2
  
          ////////////////////////////////// 2A Cell03
          if (touchmode == 1)
          {
                if (sliderfarray[2] == 1 && sliderfarray[3] == 1)
                {
                      slideroutarray[0][14] = keys[3];
                      NKROKeyboard.press(keys[3]);
                }
                else
                {
                      slideroutarray[0][14] = charspacer;
                      NKROKeyboard.release(keys[3]);
                }
          }
          ////////////////////////////////// 2B Cell04
          if (sliderfarray[2] == 1 || sliderfarray[3] == 1)
          {
                slideroutarray[1][14] = keys[4];
                NKROKeyboard.press(keys[4]);
          }
          else
          {
                slideroutarray[1][14] = charspacer;
                NKROKeyboard.release(keys[4]);
          }

          ////////////////////////////////////////////////////////// Touch Key 2 End

          ////////////////////////////////////////////////////////// Touch Key 3

          ////////////////////////////////// 3A Cell05
          if (touchmode == 1)
          {
                if (sliderfarray[4] == 1 && sliderfarray[5] == 1)
                {
                      slideroutarray[0][13] = keys[5];
                      NKROKeyboard.press(keys[5]);
                }
                else
                {
                      slideroutarray[0][13] = charspacer;
                      NKROKeyboard.release(keys[5]);
                }
          }
          ////////////////////////////////// 3B Cell06
          if (sliderfarray[4] == 1 || sliderfarray[5] == 1)
          {
                slideroutarray[1][13] = keys[6];
                NKROKeyboard.press(keys[6]);
          }
          else
          {
                slideroutarray[1][13] = charspacer;
                NKROKeyboard.release(keys[6]);
          }

          ////////////////////////////////////////////////////////// Touch Key 3 End

          ////////////////////////////////////////////////////////// Touch Key 4

          ////////////////////////////////// 4A Cell07
          if (touchmode == 1)
          {
                if (sliderfarray[6] == 1 && sliderfarray[7] == 1)
                {
                      slideroutarray[0][12] = keys[7];
                      NKROKeyboard.press(keys[7]);
                }
                else
                {
                      slideroutarray[0][12] = charspacer;
                      NKROKeyboard.release(keys[7]);
                }
          }
          ////////////////////////////////// 4B Cell08
          if (sliderfarray[6] == 1 || sliderfarray[7] == 1)
          {
                slideroutarray[1][12] = keys[8];
                NKROKeyboard.press(keys[8]);
          }
          else
          {
                slideroutarray[1][12] = charspacer;
                NKROKeyboard.release(keys[8]);
          }

          ////////////////////////////////////////////////////////// Touch Key 4 End

          ////////////////////////////////////////////////////////// Touch Key 5

          ////////////////////////////////// 5A Cell09
          if (touchmode == 1)
          {
                if (sliderfarray[8] == 1 && sliderfarray[9] == 1)
                {
                      slideroutarray[0][11] = keys[9];
                      NKROKeyboard.press(keys[9]);
                }
                else
                {
                      slideroutarray[0][11] = charspacer;
                      NKROKeyboard.release(keys[9]);
                }
          }
          ////////////////////////////////// 5B Cell10
          if (sliderfarray[8] == 1 || sliderfarray[9] == 1)
          {
                slideroutarray[1][11] = keys[10];
                NKROKeyboard.press(keys[10]);
          }
          else
          {
                slideroutarray[1][11] = charspacer;
                NKROKeyboard.release(keys[10]);
          }

          ////////////////////////////////////////////////////////// Touch Key 5 End

          ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 2 (0x5B) //////////////////////////////////////////////////////////////////////////////////////////////////

          ////////////////////////////////////////////////////////// Touch Key 6

          ////////////////////////////////// 6A Cell11
          if (touchmode == 1)
          {
                if (sliderfarray[10] == 1 && sliderfarray[11] == 1) 
                {
                      slideroutarray[0][10] = keys[11];
                      NKROKeyboard.press(keys[11]);
                }
                else
                {
                      slideroutarray[0][10] = charspacer;
                      NKROKeyboard.release(keys[11]);
                }
          }
          ////////////////////////////////// 6B Cell12
          if (sliderfarray[10] == 1 || sliderfarray[11] == 1) 
          {
                slideroutarray[1][10] = keys[12];
                NKROKeyboard.press(keys[12]);
          }
          else
          {
                slideroutarray[1][10] = charspacer;
                NKROKeyboard.release(keys[12]);
          }

          ////////////////////////////////////////////////////////// Touch Key 6 End

          ////////////////////////////////////////////////////////// Touch Key 7

          ////////////////////////////////// 7A Cell13
          if (touchmode == 1)
          {
                if (sliderfarray[12] == 1 && sliderfarray[13] == 1) 
                {
                      slideroutarray[0][9] = keys[13];
                      NKROKeyboard.press(keys[13]);
                }
                else
                {
                      slideroutarray[0][9] = charspacer;
                      NKROKeyboard.release(keys[13]);
                }
          }
          ////////////////////////////////// 7B Cell14
          if (sliderfarray[12] == 1 || sliderfarray[13] == 1) 
          {
                slideroutarray[1][9] = keys[14];
                NKROKeyboard.press(keys[14]);
          }
          else
          {
                slideroutarray[1][9] = charspacer;
                NKROKeyboard.release(keys[14]);
          }

          ////////////////////////////////////////////////////////// Touch Key 7 End

          ////////////////////////////////////////////////////////// Touch Key 8

          ////////////////////////////////// 8A Cell15
          if (touchmode == 1)
          {
                if (sliderfarray[14] == 1 && sliderfarray[15] == 1) 
                {
                      slideroutarray[0][8] = keys[15];
                      NKROKeyboard.press(keys[15]);
                }
                else
                {
                      slideroutarray[0][8] = charspacer;
                      NKROKeyboard.release(keys[15]);
                }
          }
          ////////////////////////////////// 8B Cell16
          if (sliderfarray[14] == 1 || sliderfarray[15] == 1)
          {
                slideroutarray[1][8] = keys[16];
                NKROKeyboard.press(keys[16]);
          }
          else
          {
                slideroutarray[1][8] = charspacer;
                NKROKeyboard.release(keys[16]);
          }

          ////////////////////////////////////////////////////////// Touch Key 8 End

          ////////////////////////////////////////////////////////// Touch Key 9

          ////////////////////////////////// 9A Cell17
          if (touchmode == 1)
          {
                if (sliderfarray[16] == 1 && sliderfarray[17] == 1)
                {
                      slideroutarray[0][7] = keys[17];
                      NKROKeyboard.press(keys[17]);
                }
                else
                {
                      slideroutarray[0][7] = charspacer;
                      NKROKeyboard.release(keys[17]);
                }
          }
          ////////////////////////////////// 9B Cell18
          if (sliderfarray[16] == 1 || sliderfarray[17] == 1)
          {
                slideroutarray[1][7] = keys[18];
                NKROKeyboard.press(keys[18]);
          }
          else
          {
                slideroutarray[1][7] = charspacer;
                NKROKeyboard.release(keys[18]);
          }

          ////////////////////////////////////////////////////////// Touch Key 9 End

          ////////////////////////////////////////////////////////// Touch Key 10

          ////////////////////////////////// 10A Cell19
          if (touchmode == 1)
          {
                if (sliderfarray[18] == 1 && sliderfarray[19] == 1) 
                {
                      slideroutarray[0][6] = keys[19];
                      NKROKeyboard.press(keys[19]);
                }
                else
                {
                      slideroutarray[0][6] = charspacer;
                      NKROKeyboard.release(keys[19]);
                }
          }
          ////////////////////////////////// 10B Cell20
          if (sliderfarray[18] == 1 || sliderfarray[19] == 1)
          {
                slideroutarray[1][6] = keys[20];
                NKROKeyboard.press(keys[20]);
          }
          else
          {
                slideroutarray[1][6] = charspacer;
                NKROKeyboard.release(keys[20]);
          }

          ////////////////////////////////////////////////////////// Touch Key 10 End

          ////////////////////////////////////////////////////////// Touch Key 11

          ////////////////////////////////// 11A Cell21
          if (touchmode == 1)
          {
                if (sliderfarray[20] == 1 && sliderfarray[21] == 1)
                {
                      slideroutarray[0][5] = keys[21];
                      NKROKeyboard.press(keys[21]);
                }
                else
                {
                      slideroutarray[0][5] = charspacer;
                      NKROKeyboard.release(keys[21]);
                }
          }
          ////////////////////////////////// 11B Cell22
          if (sliderfarray[20] == 1 || sliderfarray[21] == 1)
          {
                slideroutarray[1][5] = keys[22];
                NKROKeyboard.press(keys[22]);
          }
          else
          {
                slideroutarray[1][5] = charspacer;
                NKROKeyboard.release(keys[22]);
          }

          ////////////////////////////////////////////////////////// Touch Key 11 End

          ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 3 (0x5C) //////////////////////////////////////////////////////////////////////////////////////////////////

          ////////////////////////////////////////////////////////// Touch Key 12

          ////////////////////////////////// 12A Cell23
          if (touchmode == 1)
          {
                if (sliderfarray[22] == 1 && sliderfarray[23] == 1) 
                {
                      slideroutarray[0][4] = keys[23];
                      NKROKeyboard.press(keys[23]);
                }
                else
                {
                      slideroutarray[0][4] = charspacer;
                      NKROKeyboard.release(keys[23]);
                }
          }
          ////////////////////////////////// 12B Cell24
          if (sliderfarray[22] == 1 || sliderfarray[23] == 1) 
          {
                slideroutarray[1][4] = keys[24];
                NKROKeyboard.press(keys[24]);
          }
          else
          {
                slideroutarray[1][4] = charspacer;
                NKROKeyboard.release(keys[24]);
          }

          ////////////////////////////////////////////////////////// Touch Key 12 End

          ////////////////////////////////////////////////////////// Touch Key 13

          ////////////////////////////////// 13A Cell25
          if (touchmode == 1)
          {
                if (sliderfarray[24] == 1 && sliderfarray[25] == 1) 
                {
                      slideroutarray[0][3] = keys[25];
                      NKROKeyboard.press(keys[25]);
                }
                else
                {
                      slideroutarray[0][3] = charspacer;
                      NKROKeyboard.release(keys[25]);
                }
          }
          ////////////////////////////////// 13B Cell26
          if (sliderfarray[24] == 1 || sliderfarray[25] == 1) 
          {
                slideroutarray[1][3] = keys[26];
                NKROKeyboard.press(keys[26]);
          }
          else
          {
                slideroutarray[1][3] = charspacer;
                NKROKeyboard.release(keys[26]);
          }

          ////////////////////////////////////////////////////////// Touch Key 13 End

          ////////////////////////////////////////////////////////// Touch Key 14

          ////////////////////////////////// 14A Cell27
          if (touchmode == 1)
          {
                if (sliderfarray[26] == 1 && sliderfarray[27] == 1) 
                {
                      slideroutarray[0][2] = keys[27];
                      NKROKeyboard.press(keys[27]);
                }
                else
                {
                      slideroutarray[0][2] = charspacer;
                      NKROKeyboard.release(keys[27]);
                }
          }
          ////////////////////////////////// 14B Cell28
          if (sliderfarray[26] == 1 || sliderfarray[27] == 1)
          {
                slideroutarray[1][2] = keys[28];
                NKROKeyboard.press(keys[28]);
          }
          else
          {
                slideroutarray[1][2] = charspacer;
                NKROKeyboard.release(keys[28]);
          }

          ////////////////////////////////////////////////////////// Touch Key 14 End

          ////////////////////////////////////////////////////////// Touch Key 15

          ////////////////////////////////// 15A Cell29
          if (touchmode == 1)
          {
                if (sliderfarray[28] == 1 && sliderfarray[29] == 1)
                {
                      slideroutarray[0][1] = keys[29];
                      NKROKeyboard.press(keys[29]);
                }
                else
                {
                      slideroutarray[0][1] = charspacer;
                      NKROKeyboard.release(keys[29]);
                }
          }
          ////////////////////////////////// 15B Cell30
          if (sliderfarray[28] == 1 || sliderfarray[29] == 1) 
          {
                slideroutarray[1][1] = keys[30];
                NKROKeyboard.press(keys[30]);
          }
          else
          {
                slideroutarray[1][1] = charspacer;
                NKROKeyboard.release(keys[30]);
          }

          ////////////////////////////////////////////////////////// Touch Key 15 End

          ////////////////////////////////////////////////////////// Touch Key 16

          ////////////////////////////////// 16A Cell31
          if (touchmode == 1)
          {
                if (sliderfarray[30] == 1 && sliderfarray[31] == 1) 
                {
                      slideroutarray[0][0] = keys[31];
                      NKROKeyboard.press(keys[31]);
                }
                else
                {
                      slideroutarray[0][0] = charspacer;
                      NKROKeyboard.release(keys[31]);
                }
          }
          ////////////////////////////////// 16B Cell32
          if (sliderfarray[30] == 1 || sliderfarray[31] == 1) 
          {
                slideroutarray[1][0] = keys[32];
                NKROKeyboard.press(keys[32]);
          }
          else
          {
                slideroutarray[1][0] = charspacer;
                NKROKeyboard.release(keys[32]);
          }

          ////////////////////////////////////////////////////////// Touch Key 16 End
          
    }
}

#endif
