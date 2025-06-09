/**
  ******************************************************************************
  * @file	: SRGX_AVR_Example_05.ino
  * @brief  : Code example of the use of the ShiftRegGPIOXpander_AVR library
  * 
  * Repository: https://github.com/GabyGold67/ShiftRegGPIOXpander_AVR
  * Simulation url: 
  * 
  * Framework: Arduino
  * Platform: * (Any but those needing multithreading protections)
  * 
  * @author	: Gabriel D. Goldman
  * mail <gdgoldman67@hotmail.com>
  * Github <https://github.com/GabyGold67>
  *
  * @date First release: 16/02/2025 
  *       Last update:   06/06/2025 11:10 GMT+0200 DST
  ******************************************************************************
  * @warning **Use of this library is under your own responsibility**
  * 
  * @warning The use of this library falls in the category described by The Alan 
  * Parsons Project (c) 1980 "Games People play" disclaimer:  
  * Games people play, you take it or you leave it  
  * Things that they say aren't alright  
  * If I promised you the moon and the stars, would you believe it?  
  * 
  * Released into the public domain in accordance with "GPL-3.0-or-later" license terms.
  ******************************************************************************
*/
#include <Arduino.h>
#include <ShiftRegGPIOXpander_AVR.h>

   uint8_t ds{10};
   uint8_t sh_cp{12};
   uint8_t st_cp{11};
   uint8_t srQty{1};
   
   uint8_t strtngVals [1] {0b01010101};
   uint8_t* stVlsPtr = strtngVals;

   ShiftRegGPIOXpander mySrgx(ds, sh_cp, st_cp, srQty);

void setup() {
   Serial.begin(9600);

   mySrgx.begin(stVlsPtr);
}

/*
Warning: The delay() is a blocking statement, not recomended for regular use
but when specifically required and after checking the code conditions are 
adequate for it's use. Here the delay is repeatedly used to separete the library
methods use, for example simplicity. Check the use of millis() and micros() for 
regular development.  
*/

void loop() {


}
