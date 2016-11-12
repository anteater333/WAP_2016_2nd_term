void setup() {
  Serial.begin(9600);
}
int lux;
void loop() {
  lux = analogRead(A4);
  Serial.println(lux);
  delay(80);
}
