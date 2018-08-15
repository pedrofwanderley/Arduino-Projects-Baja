//Código para cálculo do RPM a partir da leitura de uma porta analógica;
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

void setup() {
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("RPM :");
  lcd.setCursor(5,0);
  lcd.print("VEL :");
}

void loop() {
  float tension = analogRead(A0);
  float regulated_tension = tension * 1.6;
  float rpm = regulated_tension * 1081.730769;
  lcd.setCursor(1,2);
  lcd.print(rpm);
  delay(1);
  
}
