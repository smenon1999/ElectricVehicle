#include <Encoder.h>

Encoder shaft(2,3);
const int motorPin=A0;

//millimeters
double distance=12000;
double circumference=80*PI;
double numRev=distance/circumference;
double numTickShaft=numRev*180;
// divide by 1.666667 for red car
double numTicks=numTickShaft/1.66667;

 int pos;
void setup() {
  pos=0;
  attachInterrupt(digitalPinToInterrupt(2), interruptFunction, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), interruptFunction, CHANGE);
  Serial.begin(9600);
  Serial.println("Serial has started");
    Serial.println(numTicks);
    

}

void loop() {
  if (pos <= -numTicks) {
    Serial.println(pos);
    analogWrite(motorPin,0);
    while (true) {}
  }
  Serial.println(pos);
  analogWrite(motorPin,255);
  // put your main code here, to run repeatedly:

}

void interruptFunction() {
  if (digitalRead(2)==digitalRead(3)) {
      pos--;
  }
 

}


