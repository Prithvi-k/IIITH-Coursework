int pin=4;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin,INPUT);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("!");
  int adc=analogRead(pin);
  float v=adc*5000/5800.0;
  float cur=v-2500;//2470.345;
  cur/=185;
  // if(-0.15<cur && cur<0.15)
  //   cur=0;
  Serial.println(-cur);
  delay(500);
}