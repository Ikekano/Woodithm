// Header File for Debug Functions
#ifndef _DEBUG_h
#define _DEBUG_h

#include "SetupConfig.h"
#include "IRSensor.h"
#include "MPR121Touch.h"
#include "TouchSlider.h"
#include "DisableKey.h"

void IRstatus()
{
      for (int i = 0; i < 6; i++)
      {
          Serial.print(IRarray[i]);
          Serial.print(" ");
      }
      Serial.println();
}

void DebugTArray()
{
      for (int v = 0; v < 3; v++)
      {
          for (int i = 0; i < 12; i++)
          {
              Serial.print(toucharray[v][i]);
              Serial.print(" ");
          }
          Serial.println();
      }
      Serial.println();
}

void DebugTMArray()
{
      for (int v = 0; v < 2; v++)
      {
            for (int i = 0; i < 16; i++)
            {
                  Serial.print(sliderarray[v][i]);
                  Serial.print(" ");
            }
            Serial.println();
      }
      Serial.println();      
}

void DebugDArray()
{
      for (int i = 0; i < 3; i++)
      {
          Serial.print(disarray[i]);
          Serial.print(" ");
      }
      Serial.println();
}

void layoutprint()
{
      for (int i = 0; i < 40; i++)
      {
          Serial.print(keys[i]);
          Serial.print(" ");
      }
      for (int i = 0; i < 5; i++)
      {
          Serial.print(fkeys[i]);
          Serial.print(" ");
      }
      Serial.println();
}

void DebugData()
{
      int selectdebugboard = 0; // Choose which board to test 0-2 for boards 1-3
      
      Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(touch[selectdebugboard].touched(), HEX);
      Serial.print("Filt: ");
      for (uint8_t i = 0; i < 12; i++) 
      {
          Serial.print(touch[selectdebugboard].filteredData(i)); Serial.print("\t");
      }
      Serial.println();
      Serial.print("Base: ");
      for (uint8_t i = 0; i < 12; i++) {
          Serial.print(touch[selectdebugboard].baselineData(i)); Serial.print("\t");
      }
      Serial.println();
      Serial.print("ARR: ");
      for (uint8_t i=0; i<12; i++) {
         Serial.print(baseread[selectdebugboard][i]); Serial.print("\t");
      }
      Serial.println();   
}

void DebugALL()
{
  
      if (debugmode != 0)
      {
            
            if (debugoutput == 0)
            {
                  touchdisableor = 1;
                  irdisableor = 1;
                  funcdisableor = 1;
            }
            
            if (debugmode == 1 || debugmode == 2)
            {
                  if (debugmode == 2)
                  {
                     rr = 1000/20; // Go into debug refresh rate of 20 Hz
                     refresh = 20;
                  }
            
                  Serial.println();
                  Serial.print("\t\t\t\t\t\t DEBUG MODE ");
                  Serial.print(debugmode);
                  Serial.println();
                  
                  Serial.print("Refresh Rate: ");
                  Serial.print(refresh);
                  Serial.print(" Hz");
                  Serial.println(refreshoverride);
                  
                  Serial.print("Touch 1 (0x5A): ");
                  for (int i = 0; i < 12; i++)
                  {
                      Serial.print(toucharray[0][i]);
                      Serial.print(" ");
                  }
                  Serial.println();
                  
                  Serial.print("Touch 2 (0x5B): ");
                  for (int i = 0; i < 12; i++)
                  {
                      Serial.print(toucharray[1][i]);
                      Serial.print(" ");
                  }
                  Serial.println();
                  
                  Serial.print("Touch 3 (0x5C): ");
                  for (int i = 0; i < 12; i++)
                  {
                      Serial.print(toucharray[2][i]);
                      Serial.print(" ");
                  }
                  
                  Serial.println();
                  Serial.println();

                  Serial.print("Touch Cells (Linear): ");
                  for (int i = 0; i < 32; i++)
                  {
                      Serial.print(sliderfarray[i]);
                      Serial.print(" ");
                  }
                  
                  Serial.println(); 

                  Serial.println("Touch Cell (Map): ");
                  for (int v = 0; v < 2; v++)
                  {
                      for (int i = 0; i < 16; i++)
                      {
                          Serial.print(sliderarray[v][i]);
                          Serial.print(" ");
                      }
                      Serial.println();
                  }

                  Serial.println();

                  Serial.print("IR: ");
                  for (int i = 0; i < 6; i++)
                  {
                      Serial.print(IRarray[i]);
                      Serial.print(" ");
                  }
                  Serial.println();

                  Serial.print("Function Keys: ");
                  for (int i = 0; i < 4; i++)
                  {
                      Serial.print(funcarray[i]);
                      Serial.print(" ");
                  }
                  Serial.println();
                  
            }
            else if (debugmode == 3)
            {
            
                rr = 1000/5; // Go into debug refresh rate of 5 Hz
          
                Serial.println();
                Serial.println("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
                Serial.print("\t\t\t\t\t\t DEBUG MODE ");
                Serial.print(debugmode);
                Serial.println();
                
                // Settings
                Serial.println("/////////////////////// Settings");
                
                Serial.print("Refresh Rate: ");
                Serial.print(refresh);
                Serial.print(" Hz");
                Serial.println(refreshoverride);
          
                Serial.print("Layout: ");
                Serial.print(layoutname);
                Serial.println(layoutoverride);
          
                Serial.print("FLayout: ");
                Serial.print(flayoutname);
                Serial.println(flayoutoverride);
          
                Serial.print("Disable Type: ");
                Serial.print(diskeyname);
                Serial.println(diskeyoverride);
                Serial.println();
          
                // Touch
                Serial.println("/////////////////////// Touch");
                
                Serial.print("Touch 1 (0x5A): ");
                for (int i = 0; i < 12; i++)
                {
                    Serial.print(toucharray[0][i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.print("Touch 2 (0x5B): ");
                for (int i = 0; i < 12; i++)
                {
                    Serial.print(toucharray[1][i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.print("Touch 3 (0x5C): ");
                for (int i = 0; i < 12; i++)
                {
                    Serial.print(toucharray[2][i]);
                    Serial.print(" ");
                }
                Serial.println(); 

                Serial.print("Touch Cells (Linear): ");
                for (int i = 0; i < 32; i++)
                {
                    Serial.print(sliderfarray[i]);
                    Serial.print(" ");
                }
                Serial.println(); 

                Serial.println("Touch Cell (Map): ");
                for (int v = 0; v < 2; v++)
                {
                    for (int i = 0; i < 16; i++)
                    {
                        Serial.print(sliderarray[v][i]);
                        Serial.print(" ");
                    }
                    Serial.println();
                }
                
                Serial.println();


                // Slider
                Serial.println("/////////////////////// Slider");

                Serial.println("Slider: ");
                for (int v = 0; v < 2; v++)
                {
                    for (int i = 0; i < 16; i++)
                    {
                        Serial.print(slideroutarray[v][i]);
                        Serial.print(" ");
                    }
                    Serial.println();
                }

                Serial.print("Slider Disabled: ");
                Serial.print(touchdisable);
                Serial.print(" Debug Mode Disabled: ");
                Serial.println(touchdisableor);
                Serial.println();
                
                // IR
                Serial.println("/////////////////////// IR");
                
                Serial.print("IR: ");
                for (int i = 0; i < 6; i++)
                {
                    Serial.print(IRarray[i]);
                    Serial.print(" ");
                }
                Serial.println();
          
                Serial.print("IR Disabled: ");
                Serial.print(irdisable);
                Serial.print(" Debug Mode Disabled: ");
                Serial.println(irdisableor);
                Serial.println();
          
                // Function Keys
                Serial.println("/////////////////////// Function Keys");

                Serial.print("Function Keys: ");
                for (int i = 0; i < 4; i++)
                {
                    Serial.print(funcarray[i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.print("Function Disabled: ");
                Serial.print(funcdisable);
                Serial.print(" Debug Mode Disabled: ");
                Serial.println(funcdisableor);
                Serial.println();
          
                // Disable
                Serial.println("/////////////////////// Disable");
                
                Serial.print("Disable Cooldown: ");
                Serial.print(disablecd);
                Serial.print(" Seconds");
                Serial.println(cdoverride);
                
                Serial.print("Disable Set: ");
                for (int i = 0; i < 3; i++)
                {
                    Serial.print(disarray[i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.print("Disable Key: ");
                Serial.println(diskey);
          
                Serial.print("Disable Overrides:");
                Serial.print(slideroverride);
                Serial.print(iroverride);
                Serial.println(funcoverride);
                Serial.println();
                
                // Debug flags
                Serial.println("/////////////////////// Debug Flags");
                
                Serial.print("Board 1 Error: ");
                Serial.println(touch404B1);
                Serial.print("Board 2 Error: ");
                Serial.println(touch404B2);
                Serial.print("Board 3 Error: ");
                Serial.println(touch404B3);
                
                Serial.print("Refresh Rate Defaulted: ");
                Serial.println(refreshdefault);
                Serial.print("Layout Defaulted: ");
                Serial.println(layoutdefault);
                Serial.print("FLayout Defaulted: ");
                Serial.println(flayoutdefault);
                Serial.print("Disable Key Defaulted: ");
                Serial.println(diskeydefault);
                Serial.print("Disable Cooldown Defaulted: ");
                Serial.println(disablecddefault);

                Serial.print("Invalid Function Key Assignment: ");
                Serial.println(funckeyerror);

                Serial.println();

                // Layout
                Serial.println("/////////////////////// Keyboard Layout");
                Serial.print("Slider Layout:");
                for (int i = 0; i < 33; i++)
                {
                    Serial.print(keys[i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.print("IR Layout:");
                for (int i = 33; i < 40; i++)
                {
                    Serial.print(keys[i]);
                    Serial.print(" ");
                }
                Serial.println();

                Serial.print("Function Layout:");
                for (int i = 0; i < 5; i++)
                {
                    Serial.print(fkeys[i]);
                    Serial.print(" ");
                }
                Serial.println();
                
                Serial.println();
                Serial.println("//////////////////////////////////////////////////////////////////////////////////////////////////////////////////");
                
            }
            else if (debugmode == 4)
            {
                rr = 1000/20; // Go into debug refresh rate of 20 Hz
                DebugTMArray();
            }
            else if (debugmode == 5)
            {
                rr = 1000/20; // Go into debug refresh rate of 20 Hz
                IRstatus();
            }
      }     
}

#endif
