
const int motorPin=A0;

//measurement in millimeters..............................
double distance=12050; //[9000,10000,11000,12000]
double circumference=107*PI;
double numRev=distance/circumference;
double numTickShaft=numRev*180;
double numTicks=numTickShaft;


double dist8=8500;
double numRev8=dist8/circumference;
double numTick8=numRev8*180;

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
  if (pos <= -numTick8) {
    Serial.println("this is being executed");
    
    analogWrite(motorPin,130);//less than 10.3
    delay(25);
    analogWrite(motorPin,0);//less than 10.3
    delay(150);
  }
  else {
  Serial.println(pos);
  analogWrite(motorPin,255);
  }
  // put your main code here, to run repeatedly:

}

void interruptFunction() {
  if (digitalRead(2)==digitalRead(3)) {
      pos--;
  }
 

}


