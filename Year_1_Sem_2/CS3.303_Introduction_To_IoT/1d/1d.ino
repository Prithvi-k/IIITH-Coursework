const int buzzer =4;
int playing=0;

void tone(byte pin,int freq)
{
  ledcSetup(0,8000,8);
  ledcAttachPin(pin,0);
  ledcWriteTone(0,freq);
  playing=pin;
}

void noTone(int arg)
{
  tone(playing,0);
  delay(1000);
}

void setup()
{
  pinMode(buzzer,OUTPUT);
}

void loop()
{
  tone(buzzer,2000);
  delay(2000);
  noTone(buzzer);
  delay(2000);
}
