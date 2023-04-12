int sensor_power_pin = 13, signal_pin = 27;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensor_power_pin, OUTPUT);
  digitalWrite(sensor_power_pin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(sensor_power_pin, HIGH);
  delay(10);
  int reading = analogRead(signal_pin);
  digitalWrite(sensor_power_pin, LOW);

  int value = map(reading, 0, 1525, 0, 40);
  Serial.println(value);
  delay(2000);
}
