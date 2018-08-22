#include <max6675.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

#define ktcSO  5
#define ktcCS  6
#define ktcCLK  7

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);

  
void setup() {
  Serial.begin(9600);
  
  // give the MAX a little time to settle
}

void loop() {
  // basic readout test
  
   float temp = ktc.readCelsius();
   Serial.println(temp);
 
   delay(500);
}
