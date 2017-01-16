const int outPin = A1;

#include <Encoder.h>




Encoder knobLeft(2, 3);

int Rdistance = ((12)- 3.4) * 100;

const float Pi = 3.14159;




const long baseLine = 1000.0;

long positionLeft  = -999;







void setup()

{

  Serial.begin(9600);

  pinMode(outPin,OUTPUT);

}



//A1 direct
//A4 Power
void loop()

{
 double Enterdistance = 9.7;
 //Dont mess with distance


 
 double distance = Enterdistance + 1.195;
 //9.6 = 1.2

 
 analogWrite(A0,255);
 

 






long newLeft;

  newLeft = knobLeft.read();

  if (newLeft != positionLeft) {

    Serial.print("Encoder = ");

    Serial.print(newLeft);

    Serial.println();

    positionLeft = newLeft;

   }




  if (Serial.available()) {

    Serial.read();

    Serial.println("Done");

    knobLeft.write(0);

  }

/*   if(positionLeft>-100)
 {
 // analogWrite(A4,0);
  //delay(250-(positionLeft*-5));
 
  analogWrite(A4,255);//(55+(((-1*positionLeft))/100) *200))  ;
 }*/




double EndVal;
//End Value for encoder, wheel circumfrenfce with gear ratio scaling)
EndVal= distance * 360 / (7*PI * .10);


       newLeft = knobLeft.read();
positionLeft = newLeft;
      

  while (-EndVal>positionLeft) {

     analogWrite(A0, 0);

     delay(150);

     analogWrite(A0,255);

     delay(50);

    newLeft = knobLeft.read();

    Serial.print("Encoder = ");

    Serial.print(newLeft);

    Serial.println();

    positionLeft = newLeft;

   }

   analogWrite(A4,0);

   while(true){}

  }


