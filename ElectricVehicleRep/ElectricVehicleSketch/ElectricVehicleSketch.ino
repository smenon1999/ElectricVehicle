
#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

const int encoderPin1=2;
const int encoderPin2=3;
const int motorPin=A0;
const int servo1Pin1=1;
const int servo2Pin=4;



double distance=1000; //initialize with value on set [9,9.5,10,10.5,11,11.5,12]
double circumference= 251.3;
double numRotations=distance/circumference;
double numDegrees=(numRotations)*90;



Encoder knob(encoderPin1,encoderPin2);
long pos=0;

void setup() {
  // put your setup code here, to run once:
  knob.write(50);
  Serial.begin(9600);
  Serial.println(circumference);
  Serial.println(numRotations);
  Serial.println(numDegrees);
  Serial.println("Serial has begun");
  Serial.println(PI);
}

void loop() {
  
  while (knob.read() > -numDegrees) {
    Serial.print("Position: ");
    Serial.println(knob.read());
    analogWrite(motorPin,255);
  }
  
  analogWrite(motorPin, 0);
  while (true) {}
}
