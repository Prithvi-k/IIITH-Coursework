int cur2_pin=4, cur2_count = 0;
float cur2_avg = 0.0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  cur2_pinMode(cur2_pin,INPUT);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  int cur2_adc=analogRead(cur2_pin);
  Serial.println(cur2_adc);
  float cur2_current = (cur2_adc * 0.003842) - 4.491;
  cur2_avg += cur2_current;
  cur2_count++;
  if(cur2_count == 10)
  {
    cur2_avg = cur2_avg / 10.0;
    Serial.println(cur2_avg);
    cur2_avg = 0.0;
    cur2_count = 0;
  }
  delay(200);
}