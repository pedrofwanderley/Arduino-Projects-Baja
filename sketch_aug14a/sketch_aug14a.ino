//Código para cálculo do RPM a partir da leitura de uma porta analógica;

void setup() {
  Serial.begin(9600);
}

void loop() {
  float tension = analogRead(A0);
  float regulated_tension = tension * 1.6;
  float rpm = regulated_tension * 1081.730769;
  Serial.print(rpm);
  delay(1);
  
}
