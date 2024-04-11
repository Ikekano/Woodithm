// Header File for Layout Functions
#ifndef _LAYOUT_h
#define _LAYOUT_h

#include "DebugSetup.h"
#include "Settings.h"
#include "TouchSlider.h"
#include "SetupConfig.h"

void layoutset()
{
      // Preset arrays
      // Note: All characters are inputed in ASCII decimal (NOT HEX) values 
      //       If you want to add another layout or change the defaults using ASCII decimal numbers refer to this table: https://www.rapidtables.com/code/text/ascii-table.html or this tool: https://www.duplichecker.com/text-to-ascii.php
      //       Alternatively you can enter each key in the array manually with the proper syntax for a c++ character variable shown below 
      //       Note that some keys like ( ' ) are basically impossible to enter in char form so use the decimal 39 for ( ' ) 
      //       Leave spacers as 00 or NULL and NOT null
      //       You can uncomment the example below to see the syntax coloring
      //
      //       Again these layouts are refrenced from the slidershim github: https://github.com/4yn/slidershim/blob/main/res/layouts/layout.png (There maybe errors with some of these layouts)
      //
      //       char tasolayoutcharexample[40] = {00,',','I','8','K','U','M','7','J','Y','N','6','H','T','B','5','G','R','V','4','F','E','C','3','D','W','X','2','S','Q','Z','1','A',NULL,'/',39,'.',';',']','['};
      //
      //       Format: Spacer, Cells1-32, Spacer, IR1-6
      //       Index:     0       1-32      33    34-39

      char tasolayout[40] = {00,73,44,56,75,85,77,55,74,89,78,54,72,84,66,53,71,82,86,52,70,69,67,51,68,87,88,50,83,81,90,49,65,00,47,39,46,59,93,91};
      char umilayout[40] = {00,73,57,56,75,85,77,55,74,89,78,54,72,84,66,53,71,82,86,52,70,69,67,51,68,87,88,50,83,81,90,49,65,00,48,79,76,80,44,46};
      char yuanlayout[40] = {00,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,49,50,51,52,53,54,00,45,61,91,93,92,59};
      char customlayout[40] = {00,00}; // <- YOU NEED TO CONFIGURE THIS FOR IT TO WORK!!

      //       Format: Spacer, Function1-4
      //       Index:     0        1-4 
      //    
      //       Keep in mind that if you decide to use the disable key, whatever is set for function 4 will be ignored
      //
      //       Available Function Key assignments are:
      //       "KEY_F1" - "KEY_F12" (F1-F12)
      //       "KEYPAD_ENTER" (Numpad Enter)
      //

      String fkeylayout1[5] = {"","KEY_F1","KEY_F2","KEY_F3","KEY_F4"};
      String fkeylayout2[5] = {"","KEY_F1","KEYPAD_ENTER","KEY_F3","KEY_F4"};
      String customfkeylayout[5] = {""}; // <- YOU NEED TO CONFIGURE THIS FOR IT TO WORK!!

      // Keyboard Layout Set
      if (layout == 1)
      {
            for (int i = 0; i < 40; i++)
            {
                keys[i] = tasolayout[i];
            }
            layoutname = "Tasoller";
      }
      else if (layout == 2)
      {
            for (int i = 0; i < 40; i++)
            {
               keys[i] = umilayout[i];
            }
            layoutname = "Umiguri";
      }
      else if (layout == 3)
      {
            for (int i = 0; i < 40; i++)
            {
               keys[i] = yuanlayout[i];
            }
            layoutname = "Yuancon";
      }
      else if (layout == 4)
      {
            for (int i = 0; i < 40; i++)
            {
               keys[i] = customlayout[i];
            }
            layoutname = "Custom";
      }     
      else // Revert to default if input not valid
      {
            layout = 1;
            layoutdefault = 1;
            layoutoverride = " (Defaulted)";
            layoutset();
      }

      // Function Key Layout Set
      if (flayout == 1)
      {
            for (int i = 0; i < 5; i++)
            {
                fkeys[i] = fkeylayout1[i];
            }
            flayoutname = "F1-F4";
      }
      else if (flayout == 2)
      {
            for (int i = 0; i < 5; i++)
            {
                fkeys[i] = fkeylayout1[i];
            }
            flayoutname = "F1-F3 + Disable";
      }
      else if (flayout == 3)
      {
            for (int i = 0; i < 5; i++)
            {
                fkeys[i] = fkeylayout2[i];
            }
            flayoutname = "F1, F3, Numpad_Enter + Disable";
      }
      else if (flayout == 4)
      {
            for (int i = 0; i < 5; i++)
            {
                fkeys[i] = customfkeylayout[i];
            }
            flayoutname = "Custom";
      }
      else // Revert to default if input not valid
      {
            flayout = 1;
            flayoutdefault = 1;
            flayoutoverride = " (Defaulted)";
            layoutset();
      }

      // Initiallize Array
      for (int v = 0; v < 2; v++)
      {
            for (int i = 0; i < 16; i++)
            {
                  slideroutarray[v][i] = charspacer;         
            }
      }
}

#endif
