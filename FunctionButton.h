// Header File for Function Button Functions
#ifndef _FUNCTIONBUTTON_h
#define _FUNCTIONBUTTON_h

#include "HID-Project.h"
#include "SetupConfig.h"
#include "DebugSetup.h"
#include "Layout.h"
#include "TouchSlider.h"

      // NOTE: Function Buttons are bound to F1-F3 keys by default
      //       F1 - 0x70 (Test)
      //       F2 - 0x71 (Service)
      //       F3 - 0x72 (Coin)
      //       (Make sure to change these in the appropriate .ini or .config files for the game you are playing to ensure that they will work)
      //
      //       F4 - 0x73 is there for free assignment and a placeholder if the disable key is disabled.
      //       Numpad_Enter is used for certain programs to load account data it will be automatically held down for 500ms very time it is pressed.
      //
      //       Currently the default behavior of the key is limited to tapping once every 250ms and may or may not interrupt slider and IR inputs while being pressed. 
      //       This shouldn't be that much of an issue since you should only tap these function keys only when you need to and not during gameplay.
      //

// Timer Definitions
unsigned long fntimer1a = 0;
unsigned long fntimer1b = 0;

unsigned long fntimer2a = 0;
unsigned long fntimer2b = 0;

unsigned long fntimer3a = 0;
unsigned long fntimer3b = 0;

unsigned long fntimer4a = 0;
unsigned long fntimer4b = 0;

// Variable Definitions for function button states
int funcarray[4];

// Function Prototype
void fnkeys(int keynum, String key);

void fnkeyRead()
{
	// Read Function Key States
	for (int i = 0; i < 4; i++)
    {
        funcarray[i] = toucharray[Functouchpads[0][i]][Functouchpads[1][i]];
    }
}

void fnkeyOut()
{
	if (funcdisable == 0 && funcdisableor == 0)
    {
        //////////////////////////// Func 1
        if (funcarray[0] == 1)
        {
            //NKROKeyboard.write(fkeys[1]);
            fnkeys(1,fkeys[1]);
        }
        else
        {
            fntimer1a = millis();
            //NKROKeyboard.release(fkeys[1]);  
        }
        
        //////////////////////////// Func 2
        if (funcarray[1] == 1)
        {
            //NKROKeyboard.press(fkeys[2]);
            //NKROKeyboard.press(KEY_F1);
            fnkeys(2,fkeys[2]);
        }
        else
        {
            //NKROKeyboard.release(fkeys[2]);
            //NKROKeyboard.release(KEY_F1);
            //fnkeys(0,fkeys[1]);
            fntimer2a = millis();
        }
        
        //////////////////////////// Func 3
        if (funcarray[2] == 1)
        {
            //NKROKeyboard.press(fkeys[3]);
            //NKROKeyboard.press(KEY_F2);
            fnkeys(3,fkeys[3]);
        }
        else
        {
            //NKROKeyboard.release(fkeys[3]); 
            //NKROKeyboard.release(KEY_F2);
            //fnkeys(0,fkeys[2]);
            fntimer3a = millis();
        }
        
        //////////////////////////// Func 4
        if (flayout == 1)
        {
            if (funcarray[3] == 1)
            {
                //NKROKeyboard.press(fkeys[4]);
                fnkeys(4,fkeys[4]);
            }
            else
            {
                fntimer4a = millis();
                //NKROKeyboard.release(fkeys[4]);  
            }
        }
          
    }
}

int fnkeyindex(String keyname)
{
    String fkeylist[13] = {"KEY_F1","KEY_F2","KEY_F3","KEY_F4","KEY_F5","KEY_F6","KEY_F7","KEY_F8","KEY_F9","KEY_F10","KEY_F11","KEY_F12","KEYPAD_ENTER"};
      
        int listindex = 0;
      
        for (int i = 0; i < 13; i++)
        {
            if (fkeylist[i] == keyname)
            {
                listindex = i + 1;
                break;
            }
            else
            {
                funckeyerror = 1;
            }
        } 
             
    return listindex;
}

void fnkeys(int keynum, String key)
{
    int keydl = 50; // Sets key press time
      
    if (keynum == 1)
    {       
        int listindex = fnkeyindex(key);

        if ((fntimer1a - fntimer1b) > (250-rr))
        {
            switch(listindex)
            {
            	case 1:
                    NKROKeyboard.press(KEY_F1);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F1);
                    break;
            	case 2:
                    NKROKeyboard.press(KEY_F2);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F2);
                    break;
                case 3:
                    NKROKeyboard.press(KEY_F3);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F3);
                    break;
                case 4:
                    NKROKeyboard.press(KEY_F4);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F4);
                    break;
                case 5:
                    NKROKeyboard.press(KEY_F5);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F5);
                    break;
                case 6:
                    NKROKeyboard.press(KEY_F6);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F6);
                    break;
                case 7:
                    NKROKeyboard.press(KEY_F7);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F7);
                    break;
                case 8:
                    NKROKeyboard.press(KEY_F8);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F8);
                	break;
                case 9:
                    NKROKeyboard.press(KEY_F9);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F9);
                    break;
                case 10:
                    NKROKeyboard.press(KEY_F10);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F10);
                    break;
                case 11:
                    NKROKeyboard.press(KEY_F11);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F11);
                    break;
                case 12:
                    NKROKeyboard.press(KEY_F12);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F12);
                    break;
                case 13:
                    NKROKeyboard.press(KEYPAD_ENTER);
                    delay(500);
                    NKROKeyboard.release(KEYPAD_ENTER);
                    break;
            }
        }
        fntimer1b = fntimer1a; // Update Timer
    }

    if (keynum == 2)
    {       
        int listindex = fnkeyindex(key);

        if ((fntimer2a - fntimer2b) > (250-rr))
        {
            switch(listindex)
            {
                case 1:
                    NKROKeyboard.press(KEY_F1);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F1);
                    break;
                case 2:
                    NKROKeyboard.press(KEY_F2);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F2);
                    break;
                case 3:
                    NKROKeyboard.press(KEY_F3);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F3);
                    break;
                case 4:
                    NKROKeyboard.press(KEY_F4);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F4);
                    break;
                case 5:
                    NKROKeyboard.press(KEY_F5);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F5);
                    break;
                case 6:
                    NKROKeyboard.press(KEY_F6);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F6);
                    break;
                case 7:
                    NKROKeyboard.press(KEY_F7);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F7);
                    break;
                case 8:
                    NKROKeyboard.press(KEY_F8);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F8);
                    break;
                case 9:
                    NKROKeyboard.press(KEY_F9);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F9);
                    break;
                case 10:
                    NKROKeyboard.press(KEY_F10);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F10);
                    break;
                case 11:
                    NKROKeyboard.press(KEY_F11);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F11);
                    break;
                case 12:
                    NKROKeyboard.press(KEY_F12);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F12);
                    break;
                case 13:
                    NKROKeyboard.press(KEYPAD_ENTER);
                    delay(500);
                    NKROKeyboard.release(KEYPAD_ENTER);
                    break;
                }
        }
        fntimer2b = fntimer2a; // Update Timer
    }

    if (keynum == 3)
    {       
        int listindex = fnkeyindex(key);

        if ((fntimer3a - fntimer3b) > (250-rr))
        {
            switch(listindex)
            {
                case 1:
                    NKROKeyboard.press(KEY_F1);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F1);
                    break;
                case 2:
                    NKROKeyboard.press(KEY_F2);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F2);
                    break;
                case 3:
                    NKROKeyboard.press(KEY_F3);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F3);
                    break;
                case 4:
                    NKROKeyboard.press(KEY_F4);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F4);
                    break;
                case 5:
                    NKROKeyboard.press(KEY_F5);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F5);
                    break;
                case 6:
                    NKROKeyboard.press(KEY_F6);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F6);
                    break;
                case 7:
                    NKROKeyboard.press(KEY_F7);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F7);
                    break;
                case 8:
                    NKROKeyboard.press(KEY_F8);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F8);
                    break;
                case 9:
                    NKROKeyboard.press(KEY_F9);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F9);
                    break;
                case 10:
                    NKROKeyboard.press(KEY_F10);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F10);
                    break;
                case 11:
                    NKROKeyboard.press(KEY_F11);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F11);
                    break;
                case 12:
                    NKROKeyboard.press(KEY_F12);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F12);
                    break;
                case 13:
                    NKROKeyboard.press(KEYPAD_ENTER);
                    delay(500);
                    NKROKeyboard.release(KEYPAD_ENTER);
                    break;
            }
        }
        fntimer3b = fntimer3a; // Update Timer
    }

    if (keynum == 4)
    {       
        int listindex = fnkeyindex(key);

        if ((fntimer4a - fntimer4b) > (250-rr))
        {
            switch(listindex)
            {
                case 1:
                    NKROKeyboard.press(KEY_F1);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F1);
                    break;
                case 2:
                    NKROKeyboard.press(KEY_F2);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F2);
                    break;
                case 3:
                    NKROKeyboard.press(KEY_F3);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F3);
                    break;
                case 4:
                    NKROKeyboard.press(KEY_F4);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F4);
                    break;
                case 5:
                    NKROKeyboard.press(KEY_F5);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F5);
                    break;
                case 6:
                    NKROKeyboard.press(KEY_F6);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F6);
                    break;
                case 7:
                    NKROKeyboard.press(KEY_F7);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F7);
                    break;
                case 8:
                    NKROKeyboard.press(KEY_F8);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F8);
                    break;
                case 9:
                    NKROKeyboard.press(KEY_F9);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F9);
                    break;
                case 10:
                    NKROKeyboard.press(KEY_F10);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F10);
                    break;
                case 11:
                    NKROKeyboard.press(KEY_F11);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F11);
                    break;
                case 12:
                    NKROKeyboard.press(KEY_F12);
                    delay(keydl);
                    NKROKeyboard.release(KEY_F12);
                    break;
                case 13:
                    NKROKeyboard.press(KEYPAD_ENTER);
                    delay(500);
                    NKROKeyboard.release(KEYPAD_ENTER);
                    break;
            }
        }
        fntimer4b = fntimer4a; // Update Timer
    }
}

#endif
