const int buzzer = 4, touch_pin = 13;
int playing=0;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);
  digitalWrite(buzzer, HIGH);
}

void loop()
{
  digitalWrite(buzzer, HIGH);
  int val = touchRead(touch_pin);
  if(val < 30) {
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
