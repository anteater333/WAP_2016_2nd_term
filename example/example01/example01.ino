#define OUT 7

void setup() {
  pinMode(OUT, OUTPUT);
}

void loop() {
  digitalWrite(OUT, HIGH);
  delay(1000);
  digitalWrite(OUT, LOW);
  delay(1000);
}
