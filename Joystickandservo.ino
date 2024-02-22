#include <Servo.h>
int Xpin =A0; 
int Ypin = A1; 
int switchPin = 2; 
int xVal;
int yVal; 
int sVal; 
int dt = 200;
int servoPin = 3; 
Servo myServo; 
float posnum; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(Xpin,INPUT); 
  pinMode(Ypin,INPUT); 
  pinMode(switchPin,INPUT); 
  digitalWrite(switchPin,HIGH);
  myServo.attach(servoPin);  
}

void loop() {
  // put your main code here, to run repeatedly:
  xVal = analogRead(Xpin); 
  yVal = analogRead(Ypin); 
  sVal =digitalRead(switchPin); 
  Serial.print("X Value = "); 
  Serial.print(xVal ); 

  Serial.print(" Yvalue = "); 
  Serial.print(yVal ); 
  Serial.print(" Switch STate is "); 
  Serial.println(sVal); 

  posnum = (0.175953)*xVal;
  myServo.write(posnum); 
}
