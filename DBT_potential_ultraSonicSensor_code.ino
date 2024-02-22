#include <LiquidCrystal.h>

int rs = 7; 
int en = 8; 
int d4 = 9; 
int d5 = 10; 
int d6 = 11; 
int d7 = 12; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 
int trigPin = 2; 
int echoPin = 3; 
float pingTT; 
float distinches; 
float distfeet; 
int dt = 150; 
int dt1 = 1; 
int dt2 = 2; 
int count = 0; 
int numMes = 50; 
int avMes; 
int j ; 
int bucket; 
int buzzPin =2; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(trigPin,OUTPUT); 
  pinMode(echoPin,INPUT); 
  pinMode(buzzPin,OUTPUT); 
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  digitalWrite(trigPin,LOW); 
   delayMicroseconds(10); 
  digitalWrite(trigPin,HIGH); 
  delayMicroseconds(10); 
   digitalWrite(trigPin,LOW);  
   pingTT = pulseIn(echoPin,HIGH);
   distinches = pingTT * 9/1295; 
   distfeet = distinches*0.0833;
   Serial.print(0); 
   Serial.print(","); 
   Serial.print(pingTT); 
   Serial.print(","); 
   Serial.println("- pingTravel time "); 
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Oject is: ");
  lcd.setCursor(0,1);
  lcd.print(distfeet);
  lcd.print(" feet away");
  Serial.println(distfeet);
  if  (distfeet <  3.1){
    //Buzzer Noise
     digitalWrite(buzzPin, HIGH); 
   
     
     
  }
else{
  digitalWrite(buzzPin,LOW);
}
  
  Serial.println(count); 
  Serial.print("this is count"); 
  

 

}
