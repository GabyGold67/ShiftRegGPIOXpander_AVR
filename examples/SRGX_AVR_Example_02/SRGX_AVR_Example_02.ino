/**
  ******************************************************************************
  * @file	: SRGX_AVR_Example_02.ino
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
  *       Last update:   05/07/2025 21:50 GMT+0200 DST
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
   uint8_t srQty{4};

   uint8_t strtngVals [4] {0x00, 0x00,0x00,0x00};
   uint8_t* stVlsPtr = strtngVals;

uint8_t mask_1 [] {0b10001000, 0b00100010, 0b00110011, 0b01110111};
uint8_t mask_2 [] {0b01010101, 0b01010101, 0b01010101, 0b01010101};

uint8_t pinUpdtd{0};
uint8_t setVal{};

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
   Serial.println("Example starts");
   Serial.println("--------------");

   Serial.println("digitalWriteSrAllSet() method rises all pins");
   mySrgx.digitalWriteSrAllSet();
   delay(1000);

   Serial.println("digitalWriteSrAllReset() method clears all pins");
   mySrgx.digitalWriteSrAllReset();
   delay(1000);

   Serial.println("digitalWrite() method writing HIGH pin by pin");
   setVal = HIGH;
   for(uint8_t pinNum{0}; pinNum <= mySrgx.getMaxSRGXPin(); pinNum++){
      mySrgx.digitalWrite(pinNum, setVal);
      delay(200);
   }

   Serial.println("digitalWrite() method writing LOW pin by pin");
   setVal = LOW;
   for(uint8_t pinNum{0}; pinNum <= mySrgx.getMaxSRGXPin(); pinNum++){
      mySrgx.digitalWrite(pinNum, setVal);
      delay(200);
   }
   delay(1000);

   Serial.println("digitalWriteSrToAux() method writing TO THE BUFFER HIGH pin by pin and 'move & flush automatic' every 3rd pin ");
   setVal = HIGH;
   for(uint8_t pinNum{0}; pinNum <= mySrgx.getMaxSRGXPin(); pinNum++){
      if((pinNum+1) % 3 != 0)
         mySrgx.digitalWriteSrToAux(pinNum, setVal);
      else
         mySrgx.digitalWrite(pinNum, setVal);
      delay(200);
   }
   mySrgx.moveAuxToMain();
   delay(1000);

   Serial.println("digitalWriteSrToAux() method writing TO THE BUFFER LOW pin by pin and 'move & flush automatic' every 4th pin");
   setVal = LOW;
   for(uint8_t pinNum{0}; pinNum <= mySrgx.getMaxSRGXPin(); pinNum++){
      if((pinNum+1) % 4 != 0)
         mySrgx.digitalWriteSrToAux(pinNum, setVal);
      else
         mySrgx.digitalWrite(pinNum, setVal);
      delay(200);
   }
   mySrgx.moveAuxToMain();
   delay(1000);

   Serial.println("digitalWriteSrMaskSet() method sets pins using the mask {0b10001000, 0b00100010, 0b00110011, 0b01110111}");
   mySrgx.digitalWriteSrMaskSet(mask_1);
   delay(5000);

   Serial.println("digitalWriteSrMaskReset() method resets pins using the mask {0b01010101, 0b01010101, 0b01010101, 0b01010101}");
   mySrgx.digitalWriteSrMaskReset(mask_2);
   delay(5000);

   Serial.println("digitalWriteSrAllReset() method clears all pins");
   mySrgx.digitalWriteSrAllReset();
   delay(2000);

   Serial.println("stampOverMain() method overwrites the Main Buffer with the value {0b01010101, 0b01010101, 0b01010101, 0b01010101}");
   mySrgx.stampOverMain(mask_2);
   delay(5000);

   Serial.println("digitalWriteSrAllReset() method clears all pins before restarting tests");
   Serial.println("-----------------------------------------------------------------------");
   mySrgx.digitalWriteSrAllReset();
   delay(3000);
}

//================================================>> General use functions BEGIN
//==================================================>> General use functions END

//=======================================>> User Functions Implementations BEGIN
 /**
  * @brief Error Handling function
  * 
  * Placeholder for a Error Handling function, in case of an error the execution
  * will be trapped in this endless loop
  */
 void Error_Handler(){
   for(;;)
   {    
   }
   
   return;
 }
//=========================================>> User Functions Implementations END