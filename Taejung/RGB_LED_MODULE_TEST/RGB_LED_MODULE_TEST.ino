/*
1? ???? RGB_LED? ???? ?????.
??? ?? : SZH-EK058
*/
const int ledred = 11;
const int ledgreen = 10;
const int ledblue = 9;

void setColor(int red,int green,int blue){
  analogWrite(ledred,red);
  analogWrite(ledgreen,green);
  analogWrite(ledblue,blue);  
}

void setup(){
  pinMode(ledred,OUTPUT);
  pinMode(ledgreen,OUTPUT);
  pinMode(ledblue,OUTPUT);
}

void loop(){
  setColor(255,0,0); //Red
  delay(1000);
	setColor(255,153,0); //Orange
  delay(1000);
	setColor(255,255,0); //Yellow
  delay(1000);
	setColor(0,255,0); //Green
  delay(1000);
	setColor(0,0,255); //Blue
  delay(1000);
	setColor(0,0,102); //Navy
  delay(1000);
	setColor(02,0,153); //Purple
  delay(1000);
}


