// definição dos pinos de entrada do contador
#define oscilador 1
#define sensor 5

int qtd_osc=0;
int pulso = 0;
void setup(){
  
  Serial.begin(9600);
  pinMode (oscilador, INPUT);
  pinMode (sensor, INPUT);
  attachInterrupt(oscilador, ipt1, RISING);  
  attachInterrupt(sensor, ipt2, RISING); 
}

void ipt1(){
  qtd_osc++;
}

void ipt2(){
  pulso = 1; 
}


float tempo=0, velocidade=0;

void loop(){
    
  if (pulso == 1)
  {  
    tempo = qtd_osc * 0.00394;
    velocidade = 1.76 / tempo;
    qtd_osc = 0;
    pulso = 0;
    Serial.println(oscilador);
    Serial.println(velocidade);
  }
}  
