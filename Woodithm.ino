//                                                                                                                 WOODITHM CONTROLLER
// This sketch is for use to create the brokeithm controller and REQUIRES 3 ADAFRUIT MPR121 BOARDS.
//
// Parts List: 
// 1x Pick a Main Board
//        Seeeduino Xiao (SAMD21) (Find it on amazon or wherever you prefer) 
//                          OR 
//        Adafruit QT Py - SAMD21 Dev Board with STEMMA QT https://www.adafruit.com/product/4600
//    (Please keep in mind I will be using a Seeeduino Xiao for mine, but either will work similarly without too many modifications)
//
// 3x Adafruit 12-Key Capacitive Touch Sensor Breakout - MPR121 - STEMMA QT https://www.adafruit.com/product/1982
// 3-4x STEMMA QT / Qwiic JST SH 4-pin Cable (100mm) https://www.adafruit.com/product/4210 (3x if you are using the Seeeduino Xiao / 4x if you are using the Adafruit QT Py)
// 6x IR Break Beam Sensor with Premium Wire Header Ends - 5mm LEDs https://www.adafruit.com/product/2168
// 1x Mini360 (Or DN-Mini-360) or LM2597 DC Buck Converter Module - Look on eBay or Aliexpress
//
// Optional Parts List:
// 1x STEMMA QT / Qwiic JST SH 4-pin to Premium Male Headers Cable (150mm) https://www.adafruit.com/product/4209 (If you buy the Adafruit QT Py you will ONLY need this if you want to send 5V down the i2c line for the IR LEDs)
//
// 1x Seeeduino XIAO Expansion Board - Works With Adafruit QT Py https://www.adafruit.com/product/5033 (this board is completely optional since hookups for the Xiao will be easier however I will NOT but using it you're on you own if you choose this)
//
//
// Later(TM) Parts List:
// 1x Adafruit 16-Channel 12-bit PWM/Servo Driver - I2C interface - PCA9685 https://www.adafruit.com/product/815
//
// Library Refrence Documentation:
//
// Keyboard : https://www.arduino.cc/reference/en/language/functions/usb/keyboard/
// MPR121 : https://learn.adafruit.com/adafruit-mpr121-12-key-capacitive-touch-sensor-breakout-tutorial/wiring 
// MPR121 (Multi) : https://forum.arduino.cc/t/multiple-mpr121-capacitive-sensors-addresses-and-installation/453518
// OpeNiTHM : https://github.com/jmontineri/OpeNITHM
// 
//
// This Project began concept design on July 26th 2023 and coding began on July 30th 2023
//

//////////////////////////////////////////////////////////////////////////////////////////////////////////// Header //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Arduino Headers
#include "Adafruit_MPR121.h"
#include "HID-Project.h"
#include <Wire.h>

// Woodithm Headers
#include "SetupConfig.h"
#include "Layout.h"
#include "DebugSetup.h"
#include "Debug.h"
#include "Settings.h"
#include "MPR121Touch.h"
#include "TouchSlider.h"
#include "IRSensor.h"
#include "FunctionButton.h"
#include "DisableKey.h"
#include "InitializeController.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////// Header End ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() 
{
  
      NKROKeyboard.begin(); // Starts NKRO Keyboard

      Serial.begin(230400); // Start serial output

      InitializeController(); // Initiallize Controller
      
}

void loop() 
{
      // Locked Calibration (Refer to Setting.h for more info)
      // Controller Calibration happens within the first 3 seconds of being powered on. Do not touch the slider during this time. Calibration should only take 1/4 of a second.
      if ((millis() > 3000 && millis() < 3250) && mprcl == 1)
      {
          CalibrateController(); // Recalibrate Controller and Lock Calibration
      }
      else if ((millis() > 3500 && millis() < (3500 + (20*rr))) && ControllerCalibrated == 1)
      {
          setCalLED(); // Turns calibration LED off after calibration
      }

      //layoutprint(); // Layout Debug
      DebugALL(); // Debug Mode (Leave this uncommented unless you want to completely disable it)
//////////////////////////////////////////////////////////////////// Touch
 
      MPR121Read();
      //DebugData(); // Touch Sensor Debug

//////////////////////////////////////////////////////////////////// Slider

      SliderRead(); // Read Slider
      //DebugTArray(); // Touch Array Debug
      //DebugTMArray(); // Touch Map Debug
      SliderOut(); // Output Slider

//////////////////////////////////////////////////////////////////// IR

      IRread(); // Read IR
      //IRstatus(); // Debug IR
      IRout(); // Output IR
      
//////////////////////////////////////////////////////////////////// Function Buttons

      fnkeyRead(); // Read Function keys
      fnkeyOut(); // Output Function keys
      
//////////////////////////////////////////////////////////////////// Disable Key

      DisableKey(); // Read disable key and activate when pressed
      //DebugDArray(); // Disable Debug

delay(rr);
}
