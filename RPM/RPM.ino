//Código para cálculo do RPM a partir da leitura de uma porta analógica;

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

float k_reg = 1.6;
float k = 1081.730769;

void setup() {
  Serial.begin(9600);
  lcd.setCursor(0,0);
  lcd.print("RPM :");
  lcd.setCursor(5,0);
  lcd.print("VEL :");
}

void loop() {
  //Receiving tension from arduino analog port
  float tension = analogRead(A0);
  
  // Regulatong tension received
  float regulated_tension = tension * k_reg;
  
  // Calculating rpm by using constant
  float rpm = regulated_tension * k;
  
  //Setting cursor on display
  lcd.setCursor(1,2);
  
  //Printing RPM on display
  lcd.print(rpm);
  delay(1);
  
}
