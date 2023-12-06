int pin = 14, cur1_count = 0;
float cur1_avg = 0.0;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin,INPUT);
}
  
void loop() {
  // put your main code here, to run repeatedly:
  int cur1_adc=analogRead(pin);
  // Serial.println(cur1_adc);
  float cur = (cur1_adc * -0.0010) + 3.507;
  cur1_avg += cur;
  cur1_count++;
  if(cur1_count == 10)
  {
    cur1_avg = cur1_avg / 10.0;
    Serial.println(cur1_avg);
    cur1_avg = 0.0;
    cur1_count = 0;
  }
  delay(200);
}