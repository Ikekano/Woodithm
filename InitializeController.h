// Header File for Initialization Functions
#ifndef _INITIALIZECONTROLLER_h
#define _INITIALIZECONTROLLER_h

#include "DebugSetup.h"
#include "MPR121Touch.h"
#include "IRSensor.h"
#include "Layout.h"
#include "Settings.h"
#include "SetupConfig.h"

bool ControllerCalibrated = 0; // Bool for calibration state

void setupCalLED()
{
    pinMode(LED_BUILTIN, OUTPUT); // Activates onboard LED for calibration status
    digitalWrite(LED_BUILTIN, LOW); // Turns ON LED
}

void setCalLED()
{
    digitalWrite(LED_BUILTIN, HIGH); // Turns OFF LED
}

void settingcheck()
{
      if (refresh < 1)
      {
          refreshdefault = 1;
          refreshoverride = " (240 Hz Auto-Override)";
          rr = 1000/240;
      }
      else if (refresh >= 1000)
      {
          refreshdefault = 1;
          refreshoverride = " (240 Hz Auto-Override)";
          rr = 1000/240;
      }

      if (disablecd < 1)
      {
          disablecddefault = 1;
          cdoverride = " (2 Seconds Auto-Override)";
          discd = 2000;
      }

      if (debugmode < 0 || debugmode > 3)
      {
          debugmode = 0;
      }
}

void setdisable()
{
      // Disable Key Behavior Set
      if (disablekey == 1)
      {
            if (touchdisable == 1)
            {
                slideroverride = " Slider Override ";
            }
            else
            {
                disarray[0] = 1;
            }
            
            if (irdisable == 1)
            {
                iroverride = " IR Override ";
            }

            if (funcdisable == 1)
            {
                funcoverride = " Function Override ";
            }

            if (touchdisable == 0 && irdisable == 0 && funcdisable == 0)
            {
                slideroverride = " NONE ";
            }
            
            diskeyname = "Slider Only";
      }
      else if (disablekey == 2)
      {
            if (touchdisable == 1)
            {
                slideroverride = " Slider Override ";
            }
            
            if (irdisable == 1)
            {
                iroverride = " IR Override ";
            }
            else
            {
                disarray[1] = 1;
            }

            if (funcdisable == 1)
            {
                funcoverride = " Function Override ";
            }

            if (touchdisable == 0 && irdisable == 0 && funcdisable == 0)
            {
                slideroverride = " NONE ";
            }
            
            diskeyname = "IR Only";
      }
      else if (disablekey == 3)
      {
            if (touchdisable == 1)
            {
                slideroverride = " Slider Override ";
            }
            else
            {
                disarray[0] = 1;
            }

            if (irdisable == 1)
            {
                iroverride = " IR Override ";
            }
            else
            {
                disarray[1] = 1;
            }

            if (funcdisable == 1)
            {
                funcoverride = " Function Override ";
            }

            if (touchdisable == 0 && irdisable == 0 && funcdisable == 0)
            {
                slideroverride = " NONE ";
            }
            
            diskeyname = "Slider and IR Only";
      }
      else if (disablekey == 4)
      {
            if (touchdisable == 1)
            {
                slideroverride = " Slider Override ";
            }
            else
            {
                disarray[0] = 1;
            }

            if (irdisable == 1)
            {
                iroverride = " IR Override ";
            }
            else
            {
                disarray[1] = 1;
            }

            if (funcdisable == 1)
            {
                funcoverride = " Function Override ";
            }
            else
            {
                disarray[2] = 1;
            }

            if (touchdisable == 0 && irdisable == 0 && funcdisable == 0)
            {
                slideroverride = " NONE ";
            }
            
            diskeyname = "Slider, IR, and Function Keys";
      }
      else if (disablekey == 5)
      {
            if (touchdisable == 1)
            {
                slideroverride = " Slider Override ";
            }
            
            if (irdisable == 1)
            {
                iroverride = " IR Override ";
            } 
            
            if (funcdisable == 1)
            {
                funcoverride = " Function Override ";
            }

            if (touchdisable == 0 && irdisable == 0 && funcdisable == 0)
            {
                slideroverride = " NONE ";
            }
                  
            diskeyname = "OFF";
      }
      else // Revert to default if input not valid
      {
            disablekey = 5;
            diskeydefault = 1;
            diskeyoverride = " (Defaulted)";
            setdisable();
      }
}

void InitializeController()
{
    setupCalLED(); // Sets up calibration LED indicatior
	  MPR121Start(); // Starts and configs all MPR121 Boards
	  IRsetup(); // Configures IR pins
	  settingcheck(); // Checks settings
	  layoutset(); // Configures Layout
	  setdisable(); // Configures Disable Key
}

void CalibrateController()
{
    MPRbaseCalibrate(); // Calibrate baseline readings
    ControllerCalibrated = 1; // Set calibration flags
}

#endif
