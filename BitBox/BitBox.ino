/*
  BitBox

  Placeholder

  ©2021 Alexander Davis

  https://github.com/AlexanderEDavis/BitBox
*/

#include <Wire.h>
#include <SoftwareSerial.h>
#include "src/mechatronics_lib.h"

#include <Arduino.h>

float denary = 0;
float value = 0;

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {
  pinMode(1,INPUT);
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  denary = 0;
  value = 1;
  while(!(value == 256.000000)){
      // To be defined
      value += value * 2;

  }
  while(1) {
      if((digitalRead(1))  &&  (/)){
          denary += -1;
          // To be defined

      }else{
          if(digitalRead(1)){
              denary += 1;
              // To be defined

          }

      }
      if((digitalRead(2))  &&  (/)){
          denary += -2;
          // To be defined

      }else{
          if(digitalRead(2)){
              denary += 2;
              // To be defined

          }

      }
      if((digitalRead(3))  &&  (/)){
          denary += -4;
          // To be defined

      }else{
          if(digitalRead(3)){
              denary += 4;
              // To be defined

          }

      }
      if((digitalRead(4))  &&  (/)){
          denary += -8;
          // To be defined

      }else{
          if(digitalRead(4)){
              denary += 8;
              // To be defined

          }

      }
      if((digitalRead(5))  &&  (/)){
          denary += -16;
          // To be defined

      }else{
          if(digitalRead(5)){
              denary += 16;
              // To be defined

          }

      }
      if((digitalRead(6))  &&  (/)){
          denary += -32;
          // To be defined

      }else{
          if(digitalRead(6)){
              denary += 32;
              // To be defined

          }

      }
      if((digitalRead(7))  &&  (/)){
          denary += -64;
          // To be defined

      }else{
          if(digitalRead(7)){
              denary += 64;
              // To be defined

          }

      }
      if((digitalRead(8))  &&  (/)){
          denary += -128;
          // To be defined

      }else{
          if(digitalRead(8)){
              denary += 128;
              // To be defined

          }

      }
      if((digitalRead(9))  &&  (/)){
          denary += -256;
          // To be defined

      }else{
          if(digitalRead(9)){
              denary += 256;
              // To be defined

          }

      }

    _loop();
  }

}

void _loop() {
}

void loop() {
  _loop();
}
