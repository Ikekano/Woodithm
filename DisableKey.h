// Header File for Disable Key Functions
#ifndef _DISABLEKEY_h
#define _DISABLEKEY_h

#include "FunctionButton.h"
#include "Settings.h"
#include "SetupConfig.h"

// Variable and Array Definitions
int diskey = 0;
int disarray[3] = {0,0,0};

// Timer Definitions
unsigned long timer1 = 0;
unsigned long timer2 = 0;

void DisableKey()
{
      // Touch disable toggle is set to a 2 second timer by default and can't be toggled faster than every 1 seconds (for good reason)
      
      if (flayout == 2)
      {
      
            timer1 = millis();
            
            if ((timer1 - timer2 > discd-rr) && (diskey == 1 && funcarray[3] == 1))
            {
                    //Serial.println(timer1 - timer2);
                    //Serial.println("Disable Key Disabled");
                    diskey = 0;
                    if (disarray[0] == 1)
                    {
                        Serial.println("Slider Enabled");
                        touchdisable = 0;
                    }
                    
                    if (disarray[1] == 1)
                    {
                        Serial.println("IR Enabled");
                        irdisable = 0;
                    }
                    
                    if (disarray[2] == 1)
                    {
                        Serial.println("Func. Enabled");
                        funcdisable = 0;
                    }
                    timer2 = timer1; // Update Last Time
            }  
            else if ((timer1 - timer2 > discd-rr) && (diskey == 0 && funcarray[3] == 1))
            {
                    //Serial.println(timer1 - timer2);
                    //Serial.println("Disable Key Enabled");
                    diskey = 1;
                    if (disarray[0] == 1)
                    {
                        Serial.println("Slider Disabled");
                        touchdisable = 1;
                    }
                    
                    if (disarray[1] == 1)
                    {
                        Serial.println("IR Disabled");
                        irdisable = 1;
                    }
                    
                    if (disarray[2] == 1)
                    {
                        Serial.println("Func. Disabled");
                        funcdisable = 1;
                    }
                    timer2 = timer1; // Update Last Time
            }
      }	
}

#endif
