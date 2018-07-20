
// Carrega a biblioteca do LCD
#include <LiquidCrystal.h>

// Inicializa o LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  Serial.begin(9600);
  // Define o LCD com 20 colunas e 4 linhas
  // As linhas nao de 0 à 3 e as colunas de 0 à 19;
  lcd.begin(20, 4);
  
  // Mostra informacoes no display
  lcd.setCursor(1,0);
  lcd.print("Velocidade");
  lcd.setCursor(1,1);
  lcd.print("Rpm");
  lcd.setCursor(1,3);
  lcd.print("Combustivel");
}

void loop()
{
   // read the first tension;
  int firstReadA0 = analogRead(A0);
  // read the second tension;
  int secondReadA0 = analogRead(A0);
  //Calculates the medium tension between frist and second read;
  float mediaA0 = (firstRead + secondRead) / 2.0;
   
  int firstReadA1 = analogRead(A1);
  int secondReadA1 = analogRead(A1);
  float mediaA1 = (firstReadA1 + secondReadA1) / 2.0;

   
  int firstReadA2 = analogRead(A2);
  int secondReadA2 = analogRead(A2);
  float mediaA2 = (firstReadA2 + secondReadA2) / 2.0;


  
  // Set the lcd cursor to forth column and third line;
  lcd.setCursor(10,3);
  // Should print on the lcd the calculated media, instanteneously;
  lcd.print(mediaA0);

  lcd.setCursor(10,0);
  lcd.print(mediaA1);

  lcd.setCursor(10,1);
  lcd.print(mediaA2);
  delay(1);        // delay in between reads for stability
}

