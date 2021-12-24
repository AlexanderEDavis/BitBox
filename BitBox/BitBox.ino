/*
  BitBox

  Placeholder

  ©2021 Alexander Davis

  https://github.com/AlexanderEDavis/BitBox
*/

// TM1637 - Version: Latest
//#include <TM1637.h>

// Include the library
#include <TM1637Display.h>

// Define the connections pins
#define CLK 11
#define DIO 10

// Create a display object of type TM1637Display
TM1637Display display = TM1637Display(CLK, DIO);

// Create an array that turns all segments ON
const uint8_t allON[] = {0xff, 0xff, 0xff, 0xff};

// Create an array that turns all segments OFF
const uint8_t allOFF[] = {0x00, 0x00, 0x00, 0x00};

// Create an array that sets individual segments per digit to display the word "rdy"
const uint8_t rdy[] = {
  false,
  SEG_E | SEG_G,                            // r
  SEG_B | SEG_C | SEG_D | SEG_E | SEG_G,    // d
  SEG_B | SEG_C | SEG_D | SEG_F | SEG_G,    // y
};

// Defines the flags and variables used
int denary = 0;
int oldDenary = 0;
bool bit0 = false;
bool bit1 = false;
bool bit2 = false;
bool bit3 = false;
bool bit4 = false;
bool bit5 = false;
bool bit6 = false;
bool bit7 = false;
bool bit8 = false;

void setup() {
  pinMode(1, INPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  denary = 0;
}

void boot() {
  // Set the brightness to 5 (0=dimmest 7=brightest)
  display.setBrightness(7);

  // Set all segments ON
  display.setSegments(allON);

  delay(2000);
  display.clear();

  // Set bitFlags 0-8
  int i;
  for (i = 0; i < 9; i++) {
    if (i == 0) {
      bit0 = false;
    }
    if (i == 1) {
      bit1 = false;
    }
    if (i == 2) {
      bit2 = false;
    }
    if (i == 3) {
      bit3 = false;
    }
    if (i == 4) {
      bit4 = false;
    }
    if (i == 5) {
      bit5 = false;
    }
    if (i == 6) {
      bit6 = false;
    }
    if (i == 7) {
      bit7 = false;
    }
    if (i == 8) {
      bit8 = false;
    }
    display.showNumberDec(i);
    delay(5);
  }

  delay(2000);
  display.clear();

  // Prints rdy
  display.setSegments(rdy);
  delay(2000);
  display.showNumberDec(0);
}
/*
  void updateDisplay() {
  display.showNumberDec(denary);
  }*/

void loop() {
  // calls startup script
  boot();
  while (1) {
    if ((digitalRead(1)) && (bit0 == false)) {
      denary += 1;
      bit0 = true;
    }
    /*if ((digitalRead(1) == LOW)  &&  (bit0 == true)) {
      denary += -1;
      bit0 == false;

      } else {
      if ((digitalRead(1) == HIGH)  &&  (bit0 == false)) {
        denary += 1;
        bit0 == true;

      }

      }
      if((digitalRead(2) == HIGH)  &&  (bit1 == true)){
          denary += -2;
          bit1 == false;

      }else{
          if(digitalRead(2) == HIGH){
              denary += 2;
              bit1 == true;

          }

      }
      if((digitalRead(3))  &&  (bit2 == true)){
          denary += -4;
          bit2 == false;

      }else{
          if(digitalRead(3)){
              denary += 4;
              bit2 == true;

          }

      }
      if((digitalRead(4))  &&  (bit3 == true)){
          denary += -8;
          bit3 == false;

      }else{
          if(digitalRead(4)){
              denary += 8;
              bit3 == true;

          }

      }
      if((digitalRead(5))  &&  (bit4 == true)){
          denary += -16;
          bit4 == false;

      }else{
          if(digitalRead(5)){
              denary += 16;
              bit4 == true;

          }

      }
      if((digitalRead(6))  &&  (bit5 == true)){
          denary += -32;
          bit5 == false;

      }else{
          if(digitalRead(6)){
              denary += 32;
              bit5 == true;

          }

      }
      if((digitalRead(7))  &&  (bit6 == true)){
          denary += -64;
          bit6 == false;

      }else{
          if(digitalRead(7)){
              denary += 64;
              bit6 == true;

          }

      }
      if((digitalRead(8))  &&  (bit7 == true)){
          denary += -128;
          bit7 == false;

      }else{
          if(digitalRead(8)){
              denary += 128;
              bit7 == true;

          }

      }
      if((digitalRead(9))  &&  (bit8 == true)){
          denary += -256;
          bit8 == false;

      }else{
          if(digitalRead(9)){
              denary += 256;
              bit8 == true;

          }

      }*/
    // Updates display if number chnaged
    if (oldDenary == denary) {
      oldDenary = denary;
      display.showNumberDec(denary);
    }

  }
}
