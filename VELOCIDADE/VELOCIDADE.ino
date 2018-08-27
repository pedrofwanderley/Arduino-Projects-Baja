#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
// definição dos pinos de entrada do contador
#define oscilador 10
#define sensor 0

volatile int qtd_osc=0;
volatile int exibir=0;
volatile int osc=1, OsciladorAnterior=0;
volatile float tempo=0, velocidade=0;

void setup()
{
  Serial.begin(9600);
  Serial.begin(9600);
  lcd.begin(20,4);
  pinMode (oscilador, INPUT);
  pinMode (sensor, INPUT);                                                                      
  attachInterrupt(sensor, ipt, RISING); 
  lcd.setCursor(0,0);
  lcd.print("VELOCIDADE:");
}

//INTERRUPÇÃO A CADA PULSO DO SENSOR
void ipt(){ 
    tempo = qtd_osc * 0,000007734;//PERIODO(AINDA FALTA);
    if(tempo != 0){
    velocidade = (2*3.1415*0.03895) * 277.1 / tempo;
    lcd.setCursor(0,2);
    lcd.print(velocidade);
    qtd_osc = 0;    
    }
 }
//FIM DA INTERRUPÇÃO



void loop()
{
  OsciladorAnterior = osc;
  osc=(digitalRead(oscilador));
  if (OsciladorAnterior == 0 && osc == 1)
  {
    qtd_osc++;
  }
}  
