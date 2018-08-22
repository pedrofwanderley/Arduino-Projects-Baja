/*CÓDIGO DESATUALIZADO*/


// Carrega a biblioteca do LCD
/* link de tutorial de configuração de arduino com placa 12c:
 *  https://portal.vidadesilicio.com.br/display-lcd-20x4-16x2-adaptador-i2c/
 */
/*
 * (Endereço,en,rw,rs,d4,d5,d6,d7,bl, blpol)
 */
void setup()
{
  Serial.begin(9600);
  // Define o LCD com 20 colunas e 4 linhas
  // As linhas nao de 0 à 3 e as colunas de 0 à 19;
  
  // Mostra informacoes no display
}

void loop()
{
   // read the first tension;
  int firstReadA0 = analogRead(A0);
  // read the second tension;
  int secondReadA0 = analogRead(A0);
  //Calculates the medium tension between frist and second read;
  float mediaA0 = (firstReadA0 + secondReadA0) / 2.0;
   
  int firstReadA1 = analogRead(A1);
  int secondReadA1 = analogRead(A1);
  float mediaA1 = (firstReadA1 + secondReadA1) / 4.0;

   
  int firstReadA2 = analogRead(A2);
  int secondReadA2 = analogRead(A2);
  float mediaA2 = (firstReadA2 + secondReadA2) / 2.0;


  
  // Set the lcd cursor to forth column and third line;
  // Should print on the lcd the calculated media, instanteneously;
  Serial.print(mediaA0);
  Serial.print(" ");
  Serial.println(mediaA1);

  delay(100);        // delay in between reads for stability
}

