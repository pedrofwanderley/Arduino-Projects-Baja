#include <max6675.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

#define ktcSO  7
#define ktcCS  6
#define ktcCLK  5

MAX6675 ktc(ktcCLK, ktcCS, ktcSO);

  
void setup() {
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.setCursor(0,0);
  lcd.print("Deg C = ");
  // give the MAX a little time to settle
  delay(500);
}

void loop() {
  // basic readout test
  
   float temp = ktc.readCelsius();
   lcd.setCursor(1,1);
   lcd.print(temp);
 
   delay(500);
}
