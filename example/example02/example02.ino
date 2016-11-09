const int ledPin[] = {12,8,7};
const int swcPin = 2;

boolean lastState = LOW; // last swich state
int ptnNum = 0; // pattern number(0 : turn off)

void setup() {
  int i;
  for(i=0;i<3;i++){
    pinMode(ledPin[i], OUTPUT);
  }
  attachInterrupt(0,swcAction, CHANGE);
  Serial.begin(9600);
}

void loop() {
  switch(ptnNum){
    int i;
    case 0: // turn off
      for(i=0;i<3;i++) digitalWrite(ledPin[i], LOW);
      break;
    case 1: // default
      for(i=0;i<3;i++) digitalWrite(ledPin[i], HIGH);
      break;
    case 2: // pattern 1
      for(i=0;i<3;i++) digitalWrite(ledPin[i], LOW);
      for(i=0;i<3;i++){
        digitalWrite(ledPin[i], HIGH);
        delay(250);
        digitalWrite(ledPin[i], LOW);
      }
      digitalWrite(ledPin[1], HIGH);
      delay(250);
      digitalWrite(ledPin[1], LOW);
      break;
    default: // pattern 2
      for(i=0;i<3;i++) digitalWrite(ledPin[i], LOW);
      digitalWrite(ledPin[0], HIGH);
      digitalWrite(ledPin[2], HIGH);
      delay(500);
      digitalWrite(ledPin[0], LOW);
      digitalWrite(ledPin[2], LOW);
      digitalWrite(ledPin[1], HIGH);
      delay(500);
      digitalWrite(ledPin[1], LOW);
      break;
  }
}
void swcAction(){
  delay(80);
  if(digitalRead(swcPin) == HIGH && lastState == LOW){
    ptnNum++;
    if(ptnNum == 4) ptnNum = 0;
    Serial.println(ptnNum);
    lastState = HIGH;
  }
  else{
    lastState = digitalRead(swcPin);
  }
}
