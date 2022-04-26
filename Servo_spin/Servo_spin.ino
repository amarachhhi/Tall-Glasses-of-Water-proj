#include <Servo.h>

const int GothelbuttonPin = 13;
const int motherGothelLEDPin = 8;

int buttonState = 0;
Servo servo;

void setup() {
  // put your setup code here, to run once:

  // servo setup
  servo.attach(3);

  //LED setup
  pinMode(motherGothelLEDPin, OUTPUT);

  //button setup 
  pinMode(GothelbuttonPin, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(GothelbuttonPin);
  if(digitalRead(13)==LOW){
    servo.write(180);
  } else {
    servo.write(0);
    if(buttonState == 0){
    digitalWrite(motherGothelLEDPin, HIGH);
  } else{
    digitalWrite(motherGothelLEDPin, LOW);
  }
  
  Serial.println(buttonState);
  }
}
