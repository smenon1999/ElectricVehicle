int forward=A0;
int backward=A1;
int left=A2;
int right=A3;
int yMode;
int xMode;


void setup() {
  // put your setup code here, to run once:
  xMode=0;
  yMode=1;

}

void loop() {
  // put your main code here, to run repeatedly:

  if (yMode==1)
      analogWrite(forward, 255);
  if (yMode==2)
      analogWrite(backward, 255);
  if (xMode==1)
      analogWrite(left, 255);
  if (xMode==2)
      analogWrite(right, 255);
}
