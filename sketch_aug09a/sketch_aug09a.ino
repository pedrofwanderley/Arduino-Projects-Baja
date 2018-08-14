#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
void setup()
{
  Serial.begin(9600);
  // Define o LCD com 20 colunas e 4 linhas
  // As linhas nao de 0 à 3 e as colunas de 0 à 19;
  lcd.begin(20, 4);
  
  /*
  // Mostra informacoes no display
  lcd.setCursor(1,0);
  lcd.print("Vel  --> ");
  lcd.setCursor(1,3);
  lcd.print("Rpm  --> ");
  */
  init_super_font(&lcd);
}

void loop()
{
  /*
   // read the first tension;
  int firstReadA0 = analogRead(A0);
  // read the second tension;
  int secondReadA0 = analogRead(A0);
  //Calculates the medium tension between frist and second read;
  float mediaA0 = (firstReadA0 + secondReadA0) / 2.0;
   
  int firstReadA1 = analogRead(A1);
  int secondReadA1 = analogRead(A1);
  float mediaA1 = (firstReadA1 + secondReadA1) / 2.0;

   
  int firstReadA2 = analogRead(A2);
  int secondReadA2 = analogRead(A2);
  float mediaA2 = (firstReadA2 + secondReadA2) / 2.0;


  
  // Set the lcd cursor to forth column and third line;
  // Should print on the lcd the calculated media, instanteneously;
  lcd.print(mediaA0);

  lcd.setCursor(10,0);
  lcd.print(mediaA1);

  lcd.setCursor(10,3);
  delay(1000);        // delay in between reads for stability
*/
}

