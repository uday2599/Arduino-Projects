#define in1 4
#define in2 5
#define in3 6
#define in4 7

void setup() {
  pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);
Serial.begin(9600);


}

void loop() {
if(Serial.available()>0)
{
  int n = Serial.read();
  if(n=='5')
  {
    stp();
  }
  if(n=='1')
  {
    forward();
   
  }
  if(n=='4')
  {
    backward();
  }
  if(n=='2')
  {
    left();
  }
  if(n=='3')
  {
    right();
  }
  }
}

void forward()

{
digitalWrite(in1,0);
digitalWrite(in2,1);  
digitalWrite(in4,1);
digitalWrite(in3,0); 
}

void backward()

{
digitalWrite(in1,1);
digitalWrite(in2,0);  
digitalWrite(in4,0);
digitalWrite(in3,1); 
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
