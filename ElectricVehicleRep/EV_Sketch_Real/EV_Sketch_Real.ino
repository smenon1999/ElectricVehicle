
#define ENCODER_USE_INTERRUPTS
#include <Encoder.h>

const int encoderPin1=2;
const int encoderPin2=3;
const int motorPin=A0;


double distance=3000;
double circumference=251.3;
double numRotations=distance/circumference;
double numDegrees=numRotations*100;

int pos=-1000;
int numChanges=0;

Encoder shaft(encoderPin1,encoderPin2);




void setup() {
  shaft.write(0);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  Serial.println(numChanges);
  analogWrite(motorPin,255);
  int newPos=shaft.read();
  if (newPos!=pos) {

    numChanges++;
    pos=newPos;
  }
  if (numChanges>=numDegrees) {
    analogWrite(motorPin,0);
    while(true){}
  Serial.println(pos);
  }
 
  // put your main code here, to run repeatedly:

}
