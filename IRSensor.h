// Header File for IR Sensor Functions
#ifndef _IRSENSOR_h
#define _IRSENSOR_h

#include "HID-Project.h"
#include "SetupConfig.h"
#include "DebugSetup.h"
#include "Layout.h"

      // NOTE: The IR Sensors will be hooked up as shown below.
      //       The IR Emitters will pull 5V power from the Stemma QT i2c bus. They are meant to be placed on the opposite side of the Seeduino board and IR recievers.
      //       I will be using an 8-Pin connector to connect the IR Recievers to the Seeduino and the Stemma QT cable to connect the IR Emitters so that the IR towers can be disconnected for storage.
      //       The 6 signal pins for the recievers will be connected to pins 1,2,3,8,9,10 for IR 1-6 respectively. (Ordered from lowest to highest sensor)     
      //
      //    IR Emitters     ===      Board3     ===     Board 2     ===     Board 1     ===     Seeduino Xiao     ===     IR Recievers 1-6
      //      5V + GND                                                                                                   5V + GND, Signal 1-6
      //   (From i2c Bus)                                                                                                   (8-Pin Cable)
      //
      //       At 5V (or even 3.3V) the emitters will overlap their light on the recivers and will restrict detection to the middle or the closer side to the reciever.
      //       To fix this issue, there needs to be a DC buck converter (a Mini360(or clone) is ideal but an LM2596 will also work but is overkill) on the emmitter side that takes 
      //       the 5V + GND from the i2c bus and lowers it to 1.75-2V for best results.
      //
      //       Your milage will vary, test by uncommenting the IRstatus() function in woodithm and turn debug off and disable IR output. Use a multimeter to monitor the voltage and lower the voltage 
      //       until one of the sensors activate without being blocked by anything then raise the voltage 0.05V at a time on test the IR sensors on the full range until your desired sensitivity.
      //         

// Variable Definitions for air sensor states
int IRarray[6];

void IRsetup()
{
	// IR sensor pins setup (pins 1,2,3,8,9,10 will be used) 
    // Pins are pulled UP so that a resistor is not needed
    for (int i = 0; i < 6; i++)
    {
        pinMode(IRarraypins[i],INPUT_PULLUP);
    }
}

void IRread()
{
	// Read all IR sensor states
    for (int i = 0; i < 6; i++)
    {
        IRarray[i] = !digitalRead(IRarraypins[i]);
    }
}

void IRout()
{
    if (irdisable == 0 && irdisableor == 0)
    { 
        //////////////////////////// IR 1
        if (IRarray[0] == 1)
        {
            NKROKeyboard.press(keys[34]);
        }
        else
        {
            NKROKeyboard.release(keys[34]);
        }
        //////////////////////////// IR 2
        if (IRarray[1] == 1)
        {
            NKROKeyboard.press(keys[35]);
        }
        else
        {
            NKROKeyboard.release(keys[35]);
        }
        //////////////////////////// IR 3
        if (IRarray[2] == 1)
        {
            NKROKeyboard.press(keys[36]);
        }
        else
        {
            NKROKeyboard.release(keys[36]);
        }
        //////////////////////////// IR 4
        if (IRarray[3] == 1)
        {
            NKROKeyboard.press(keys[37]);
        }
        else
        {
            NKROKeyboard.release(keys[37]);
        }
        //////////////////////////// IR 5
        if (IRarray[4] == 1)
        {
            NKROKeyboard.press(keys[38]);
        }
        else
        {
            NKROKeyboard.release(keys[38]);
        }
        //////////////////////////// IR 6
        if (IRarray[5] == 1)
        {
            NKROKeyboard.press(keys[39]);
        }
        else
        {
            NKROKeyboard.release(keys[39]);
        }
    }
}

#endif
