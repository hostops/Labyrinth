#include <Servo.h> 
Servo servo1;
Servo servo2;
int px=0;
int py=0;
int n=0;
void setup() 
{
  
  servo1.attach(9);
  servo2.attach(8);
}
void loop() 
{
  int x=analogRead(A0);
  int y=analogRead(A1);
  double x1=((x-285)/155.0);
  double y1=((y-285)/155.0);
  delay(4);
    servoPosite(x1,y1);
  
}
void servoPosite(double x, double y){
    if(x>=-0.10&&x<=1.10&&y>=-0.10&&y<=1.10){
      x*=180;
      y*=180;
      if(abs(px-x)<5&&abs(py-y)<5){
        servo1.write(x);
        servo2.write(y);
        delay(10);
        px=x;
        py=y;
        n=0;
      }else{
        n++;
        if(n>10){
          px=x;
          py=y;
        }
      }
  }
}

