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

//======================================>> General use function prototypes BEGIN
void Error_Handler(int8_t errorCode); /*!<Error Handler function prototype, to be implemented by the user*/
//========================================>> General use function prototypes END

/*Constants for pin based methods*/
const uint16_t redPin{0x00}; // Red light pin
const uint16_t yellowPin{0x01}; // Yellow light pin
const uint16_t greenPin{0x02}; // Green light pin

/*Constants for mask based methods*/
const uint16_t redMsk{0x01 << redPin}; // Red light
const uint16_t yellowMsk{0x01 << yellowPin}; // Yellow light
const uint16_t greenMsk{0x01 << greenPin}; // Green light

uint8_t ds{10};
uint8_t sh_cp{12};
uint8_t st_cp{11};
uint8_t srQty{1};

uint8_t SRGXstrtngVal [1] {0x00};
uint16_t portStrtngVal{0x0000}; 

ShiftRegGPIOXpander mySrgx(ds, sh_cp, st_cp, srQty);
SRGXVPort myVPortNS = mySrgx.createSRGXVPort(0, 3);
SRGXVPort myVPortEW = mySrgx.createSRGXVPort(4, 3);

void setup() {
   Serial.begin(9600);

   mySrgx.begin(SRGXstrtngVal); 

   if(!(mySrgx.isValid(myVPortNS)))
      Error_Handler(0x02); // Error creating the virtual port, exit the task
   myVPortNS.begin(0x00);

   if(!(mySrgx.isValid(myVPortEW)))
      Error_Handler(0x03); // Error creating the virtual port, exit the task
   myVPortEW.begin(0x00);
}

/*
Warning: The delay() is a blocking statement, not recomended for regular use
but when specifically required and after checking the code conditions are 
adequate for it's use. Here the delay is repeatedly used to separete the library
methods use, for example simplicity. Check the use of millis() and micros() for 
regular development.  
*/

void loop() {
   {
      Serial.println("Set the ports pins to the first traffic lights state");
      myVPortNS.writePort(redMsk); 
      myVPortEW.writePort(greenMsk);
      delay(3000);
   }

   {
      Serial.println("Set the ports pins to the second traffic lights state");
      // myVPortNS.writePort(redMsk); 
      myVPortEW.writePort(yellowMsk);
      delay(1500);
   }

   {
      Serial.println("Set the ports pins to the third traffic lights state");
      myVPortNS.writePort(greenMsk); 
      myVPortEW.writePort(redMsk);
      delay(3000);
   }

   {
      Serial.println("Set the ports pins to the fourth traffic lights state");
      myVPortNS.writePort(yellowMsk); 
      // myVPortEW.writePort(redMsk);
      delay(1500);
   }
}

//=======================================>> User Functions Implementations BEGIN
 /**
  * @brief Error Handling function
  * 
  * Placeholder for a Error Handling function, in case of an error the execution
  * will be trapped in this endless loop
  */
 void Error_Handler(int8_t errorCode){
   Serial.println("Error Handler called with error code: " + String(errorCode));
   for(;;)
   {    
   }
   
   return;
 }
//=========================================>> User Functions Implementations END