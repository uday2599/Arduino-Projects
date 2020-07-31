const int trigpin =9;
const int echopin = 10;

long duration;
int distance;
int i=0;
void setup() {
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);
  

}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2);

  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  duration = pulseIn(echopin,HIGH);
  distance = duration*0.034/2;
  
  if (distance==3)
  {i++;
  delay(2000);
  if(i%2==1)
  {Serial.println("you left the door open");
  }
  if(i%2!=1)
  {
    Serial.println("you closed the door");
  }}
  
  


}
