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

// Define the switch pins
const int bit1pin = A1;
const int bit2pin = A2;
const int bit3pin = A3;
const int bit4pin = A4;
const int bit5pin = A5;
const int bit6pin = A6;
const int bit7pin = A7;
const int bit8pin = A8;
const int bit9pin = A9;

// Floats for ADC voltage & Input voltage
float adc_voltage = 0.0;
float in_voltage = 0.0;

// Floats for resistor values in divider (in ohms)
float R1 = 30000.0;
float R2 = 7500.0;

// Float for Reference Voltage
float ref_voltage = 5.0;

// Integer for ADC value
int adc_value = 0;

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
bool bit1 = false;
bool bit2 = false;
bool bit3 = false;
bool bit4 = false;
bool bit5 = false;
bool bit6 = false;
bool bit7 = false;
bool bit8 = false;
bool bit9 = false;

void setup() {
  // Setup Serial Monitor
  Serial.begin(9600);
  Serial.println("DC Voltage Test");
  denary = 0;
  oldDenary = 0;
  // Set the brightness to 5 (0=dimmest 7=brightest)
  display.setBrightness(7);

  // Set all segments ON
  display.setSegments(allON);

  delay(2000);
  display.clear();

  // Set bitFlags 1-9
  int i;
  for (i = 1; i < 10; i++) {
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
    if (i == 9) {
      bit9 = false;
    }
    display.showNumberDec(i);
    delay(5);
  }

  display.clear();

  // Prints rdy
  display.setSegments(rdy);
  delay(2000);
  display.showNumberDec(0);
}

void resetSenseLoop() {
  adc_voltage = 0.0;
  in_voltage = 0.0;

  R1 = 30000.0;
  R2 = 7500.0;

  ref_voltage = 5.0;

  adc_value = 0;
}

void checkSenseLoop() {
  // Determine voltage at ADC input
  adc_voltage  = (adc_value * ref_voltage) / 1024.0;

  // Calculate voltage at divider input
  in_voltage = adc_voltage / (R2 / (R1 + R2)) ;
}

void updateDisplay() {
  // Updates display if number chnaged
  if (oldDenary != denary) {
    oldDenary = denary;
    display.showNumberDec(denary);
  }
}

void loop() {
  // Checks if bit 1 is active
  resetSenseLoop();
  adc_value = analogRead(bit1pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit1 == false)) {
    denary += 1;
    bit1 = true;
  } else if ((in_voltage <= 11) && (bit1 == true)) {
    denary -= 1;
    bit1 = false;
  }

  // Checks if bit 2 is active
  resetSenseLoop();
  adc_value = analogRead(bit2pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit2 == false)) {
    denary += 2;
    bit2 = true;
  } else if ((in_voltage <= 11) && (bit2 == true)) {
    denary -= 2;
    bit2 = false;
  }

  // Checks if bit 3 is active
  resetSenseLoop();
  adc_value = analogRead(bit3pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit3 == false)) {
    denary += 4;
    bit3 = true;
  } else if ((in_voltage <= 11) && (bit3 == true)) {
    denary -= 4;
    bit3 = false;
  }

  // Checks if bit 4 is active
  resetSenseLoop();
  adc_value = analogRead(bit4pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit4 == false)) {
    denary += 8;
    bit4 = true;
  } else if ((in_voltage <= 11) && (bit4 == true)) {
    denary -= 8;
    bit4 = false;
  }

  // Checks if bit 5 is active
  resetSenseLoop();
  adc_value = analogRead(bit5pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit5 == false)) {
    denary += 16;
    bit5 = true;
  } else if ((in_voltage <= 11) && (bit5 == true)) {
    denary -= 16;
    bit5 = false;
  }

  // Checks if bit 6 is active
  resetSenseLoop();
  adc_value = analogRead(bit6pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit6 == false)) {
    denary += 32;
    bit6 = true;
  } else if ((in_voltage <= 11) && (bit6 == true)) {
    denary -= 32;
    bit6 = false;
  }

  // Checks if bit 7 is active
  resetSenseLoop();
  adc_value = analogRead(bit7pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit7 == false)) {
    denary += 64;
    bit7 = true;
  } else if ((in_voltage <= 11) && (bit7 == true)) {
    denary -= 64;
    bit7 = false;
  }

  // Checks if bit 8 is active
  resetSenseLoop();
  adc_value = analogRead(bit8pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit8 == false)) {
    denary += 128;
    bit8 = true;
  } else if ((in_voltage <= 11) && (bit8 == true)) {
    denary -= 128;
    bit8 = false;
  }

  // Checks if bit 9 is active
  resetSenseLoop();
  adc_value = analogRead(bit9pin);
  checkSenseLoop();
  if ((in_voltage >= 11) && (bit9 == false)) {
    denary += 256;
    bit9 = true;
  } else if ((in_voltage <= 11) && (bit9 == true)) {
    denary -= 256;
    bit9 = false;
  }

  // Calls updateDisplay function
  updateDisplay();
}
