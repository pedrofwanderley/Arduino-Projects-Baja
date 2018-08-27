
//Código para cálculo do RPM a partir da leitura de uma porta analógica;
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);

// definição dos pinos de entrada do contador
#define oscilador 1
#define sensor 5
//VELOCIDADE-------
int qtd_osc=0;
int pulso = 0;
//---------------

//RPM-----------------
float k_reg = 2.0;
float k = 900.0;
//--------------------
void setup() {
  Serial.begin(9600);
  /*
  lcd.begin(20,4);
  */
  //VELOCIDADE------------------------------
  /*
  pinMode (oscilador, INPUT);
  pinMode (sensor, INPUT);
  attachInterrupt(oscilador, ipt1, RISING);  
  attachInterrupt(sensor, ipt2, RISING); 
  lcd.setCursor(0,0);
  lcd.print("VEL:");
  */
  // ---------------------------------------
   //RPM-----------------------------------
   /*
  lcd.setCursor(10,0);
  lcd.print("RPM:");
  */
}

//VELOCIDADE-----------------------------------
/*
void ipt1(){
  qtd_osc++;
}

void ipt2(){
  pulso = 1; 
}

float tempo=0, velocidade=0;
//---------------------------------------------
*/

void loop() {
  //RPM---------------------------------------------------
  //Receiving tension from arduino analog port       //
  float tension = analogRead(A0);                    //
  
  // Regulatong tension received
  float regulated_tension = tension * k_reg;
  
  // Calculating rpm by using constant
  float rpm = regulated_tension * k;
  //-------------------------------------------------------

  /*
  //VELOCIDADE---------------------------------------------
   if (pulso == 1)
  {  
    tempo = qtd_osc * 0.00394;
    velocidade = 1.76 / tempo;
    qtd_osc = 0;
    pulso = 0;
    lcd.setCursor(10,2);
    lcd.print(analogRead(A0));
  }
  //-------------------------------------------------------
  //Setting cursor on display
  */
  /*
  lcd.setCursor(0,2);
  //Printing RPM on display
  lcd.print(rpm);
  */
  Serial.print("rpm:");
  Serial.print("\n");
  Serial.print(rpm);
  Serial.print("\n");
  delay(500);
}
