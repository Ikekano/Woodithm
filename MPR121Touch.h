// Header File for MPR121 Functions
#ifndef _MPR121Touch_h
#define _MPR121Touch_h

#include "Adafruit_MPR121.h"
#include "DebugSetup.h"
#include "TouchSlider.h"

//#define ECR_DEFAULT // Special Custom Definition to change ECR_SETTING to default mode in Adafruit_MPR121.cpp
//#define ECR_LOCK // Special Custom Definition to change ECR_SETTING to locked mode in Adafruit_MPR121.cpp

// If you want to use the definitions below replace the ECR_SETTING code block with the one shown below
/*
#ifdef ECR_DEFAULT
  // enable X electrodes and start MPR121
  byte ECR_SETTING =
      B10000000 + 12; // 5 bits for baseline tracking & proximity disabled + X
                      // amount of electrodes running (12)
  writeRegister(MPR121_ECR, ECR_SETTING); // start with above ECR setting
#endif

#ifdef ECR_LOCK
  // enable X electrodes and start MPR121
  byte ECR_SETTING =
      B01000000 + 12; // 5 bits for baseline tracking & proximity disabled + X
                      // amount of electrodes running (12)
  writeRegister(MPR121_ECR, ECR_SETTING); // start with above ECR setting
#endif
 */

uint16_t baseread[3][12];
uint8_t basereg = 0x1E;

void MPR121Start()
{
	// Start each MPR121 Board with respective i2c addresses (Pin 4 is SDA and Pin 5 is SCL)
	// Set error flag if board fails to start
    if (!touch[0].begin(0x5A))
    {
        touch404B1 = 1;
    }
          
    if (!touch[1].begin(0x5B))
    {
        touch404B2 = 1;
    }

    if (!touch[2].begin(0x5C))
    {
        touch404B3 = 1;
    }

	// Set touch thresholds for all MPR121 Boards 
	for (int i = 0; i < 3; i++)
    {
        touch[i].setThresholds(3,1); // (Default thresholds for MPR121 should be 12,6) But it is better to comment out the line instead to revert to default
    }
}

void MPR121Read()
{
	// Update touch states (If board fails update array)
    if (!touch404B1 == 1)
    {
        current1 = touch[0].touched();
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            toucharray[0][i] = -1;
        }
    }
        
    if (!touch404B2 == 1)
    {
        current2 = touch[1].touched();
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            toucharray[1][i] = -1;
        }
    }
        
    if (!touch404B3 == 1)
    {
        current3 = touch[2].touched();
    }
    else
    {
        for (int i = 0; i < 12; i++)
        {
            toucharray[2][i] = -1;
        }
	  }
	
	  for (uint8_t i = 0; i < 12; i++)
    {

        ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 1 (0x5A) //////////////////////////////////////////////////////////////////////////////////////////////////
        if ((current1 & _BV(i)) && !(last1 & _BV(i))) // Check which ones have been touched
        {
            toucharray[0][i] = 1;
        }

        if (!(current1 & _BV(i)) && (last1 & _BV(i))) // Check which ones have been released
        {
            toucharray[0][i] = 0;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 2 (0x5B) //////////////////////////////////////////////////////////////////////////////////////////////////
        if ((current2 & _BV(i)) && !(last2 & _BV(i))) // Check which ones have been touched
        {
            toucharray[1][i] = 1;
        }

        if (!(current2 & _BV(i)) && (last2 & _BV(i))) // Check which ones have been released
        {
            toucharray[1][i] = 0;
        }
        ////////////////////////////////////////////////////////////////////////////////////////////////// MPR121 Board 3 (0x5C) //////////////////////////////////////////////////////////////////////////////////////////////////
        if ((current3 & _BV(i)) && !(last3 & _BV(i))) // Check which ones have been touched
        {
            toucharray[2][i] = 1;
        }

        if (!(current3 & _BV(i)) && (last3 & _BV(i))) // Check which ones have been released
        {
            toucharray[2][i] = 0;
        }
    }
	
	// Update Last States
    last1 = current1;
    last2 = current2;
    last3 = current3;
	
}

void MPRbaseCalibrate()
{
    uint16_t measure; // Temp Variable
    
    for (int v = 0; v < 3; v++)
    {
        for (int i = 0; i < 12; i++)
        {
            // Read Baseline Values (For calibration) and store them into an array
            measure = touch[v].filteredData(i);
            baseread[v][i] = measure;
        }
    }
    for (int v = 0; v < 3; v++)
    {
        for (int i = 0; i < 12; i++)
        {
            // Overwrite Baseline Value registers (with offset of 4)
            touch[v].writeRegister(basereg + i, ((baseread[v][i] >> 2) - 0x01));
            delay(1); // Add slight delay since writing to multiple registers very quickly is iffy.
        }
    }     
}

#endif
