#define ir1 9
#define ir2 8
#define in1 4
#define in2 5
#define in3 6
#define in4 7


void setup() {
  pinMode(ir1,INPUT);
  pinMode(ir2,INPUT);
   pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);


}

void loop() {
  int n1 = digitalRead(ir1);
  int n2 = digitalRead(ir2);
  if(n1== 1 & n2== 1)
  {
    forward();  
    
  }
  if(n1== 0 & n2== 0)
  {
    stp();
  }
  if(n1== 1& n2== 0)
  {
    left();
  }
  if (n1== 0& n2== 1)
  {
    right();
  }
}
void forward()

{
digitalWrite(in1,0);
digitalWrite(in2,1);  
digitalWrite(in4,1);
digitalWrite(in3,0); 
}

void right()

{
digitalWrite(in1,0);
digitalWrite(in2,0);  
digitalWrite(in4,1);
digitalWrite(in3,0); 
}

void left()

{
digitalWrite(in1,0);
digitalWrite(in2,1);  
digitalWrite(in4,0);
digitalWrite(in3,0); 
}
void stp()
{
digitalWrite(in1,0);
digitalWrite(in2,0);  
digitalWrite(in4,0);
digitalWrite(in3,0); 
}
