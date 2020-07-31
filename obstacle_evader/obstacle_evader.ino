const int trigpin =10;
const int echopin = 11;
#define in1 2
#define in2 3
#define in3 4
#define in4 7
#define ENA 6
#define ENB 5
int sp=100;
float duration;
float distance;
int i=0;
#include <Servo.h>

Servo myservo;  


int pos = 0;

void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
   myservo.attach(9);
  myservo.write(90);
  pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);

}

void loop() {
  float n=dis();
   
if (n>50)
{
  forward();
}
  else if(n<50)
  {
    stp();
    delay(1000);
    for(i=90;i>=0;i--)
    {
      myservo.write(i);
      
      delay(15);
      }
      float leftservo=dis();
      for(i=0;i<=90;i++)
      {
        myservo.write(i);
        
        delay(15);
      }
      float rightservo=dis();
      for(i=180;i>=90;i--)
    {
      myservo.write(i);
      
      delay(15);
      }
      
    if(leftservo>rightservo)
    {
      left();
      delay(1000);
    }
    else if(rightservo>leftservo)
    {
      
     right();
    delay(1000);
    }
  }
  

}

float dis()
{
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  return distance;
 
}


void serv()
{
  
    for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    myservo.write(pos);              
    delay(15);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    delay(15);                       
  }
  
 
  }
  
void forward()

{
analogWrite(ENA,sp);
analogWrite(ENB,sp);
digitalWrite(in1,0);
digitalWrite(in2,1);  
digitalWrite(in4,1);
digitalWrite(in3,0); 
}

void backward()

{
analogWrite(ENA,sp);
analogWrite(ENB,sp);
digitalWrite(in1,1);
digitalWrite(in2,0);  
digitalWrite(in4,0);
digitalWrite(in3,1); 
}
void right()

{
analogWrite(ENA,sp);
analogWrite(ENB,sp);
digitalWrite(in1,0);
digitalWrite(in2,0);  
digitalWrite(in4,1);
digitalWrite(in3,0); 
}

void left()

{
 analogWrite(ENA,sp);
 analogWrite(ENB,sp);
digitalWrite(in1,0);
digitalWrite(in2,1);  
digitalWrite(in4,0);
digitalWrite(in3,0); 
}
void stp()
{
analogWrite(ENA,0);
analogWrite(ENB,0);
digitalWrite(in1,0);
digitalWrite(in2,0);  
digitalWrite(in4,0);
digitalWrite(in3,0); 
}
