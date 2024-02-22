int b1 = 12; 
int b1Val; 
int b2 = 13; 
int b2Val; 
int ledpin = 9; 
int volta=0; 
int dela = 150;
int buzzPin= 11; 

void setup() {
  // put your setup code here, to run once:
 pinMode(b1,INPUT); 
 pinMode(b2,INPUT); 
 pinMode(ledpin,OUTPUT);
 pinMode(buzzPin,OUTPUT); 
 Serial.begin(9600); 

}

void loop() {
  // put your main code here, to run repeatedly:
  // MAX VOLTAGE = 255
 b1Val = digitalRead(b1); 
 b2Val = digitalRead(b2); 
 delay(dela); 

if (b1Val == 0){
   volta = volta+51; 
}
if(b2Val == 0){
  volta = volta - 51; 
}
Serial.print(b1Val); 
Serial.println(b2Val); 

  
if (volta >= 0 && volta <= 255){  
  analogWrite(ledpin,volta); 
  }
 
 if ( volta > 255){
   analogWrite(ledpin,0);
   digitalWrite(buzzPin,HIGH); 
   delay(dela); 
   digitalWrite(buzzPin,LOW);
   volta = 0;  
  
 }
 if (volta < 0 ){
   analogWrite(ledpin,0);
   digitalWrite(buzzPin,HIGH); 
   delay(dela); 
   digitalWrite(buzzPin,LOW);
   volta = 255;  
  
 }

}
