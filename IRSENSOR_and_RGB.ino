#include <IRremote.h>
int IRpin = 3; 
IRrecv IR(IRpin);
decode_results cmd; 
String myCom; 
int speedPin = 10; 
int dir1 = 12; 
int dir2 = 13; 
int mSpeed; // motor speed at max voltage 
int delt =50; 
int count; 
int rPin = 5; 
int gPin = 10; 
int bPin = 9; 

int Pinb; 
int rPinb = 255; 
int gPinb = 255; 
int bPinb = 255; 
int a; 


int r=85 ; 
// counters 


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  IR.enableIRIn(); 
  pinMode(speedPin,OUTPUT); 
  pinMode(dir1,OUTPUT); 
  pinMode(dir2,OUTPUT); 
  pinMode(rPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(bPin,OUTPUT);
}

void loop() {
 
  while(IR.decode(&cmd)==0){

  }
  Serial.println(cmd.value,HEX);
  delay(1500); 
  IR.resume();
    // up
  if (cmd.value== 0xFF906F){ // 0x helps the computer know to look for a hexidecimal 
    count = count +1; 
    if (count >3){
    count = 3; 
  }
    myCom ="you pressed up";
    Serial.println(myCom);
  }
  // down
  if (cmd.value== 0xFFE01F){ // 0x helps the computer know to look for a hexidecimal 
    count = count - 1 ;
     if (count < 0){
    count = 0;
  }
    myCom ="you pressed down";
    Serial.println(myCom);
  }
  
  Pinb = r*count;
  // 0
  if (cmd.value== 0xFF6897){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 0";
    Serial.println(myCom);
  }
  // 1
  if (cmd.value== 0xFF30CF){ // 0x helps the computer know to look for a hexidecimal 
    a=1; 
   
    myCom ="you pressed 1";
    Serial.println(myCom);
  }

  if (a ==1){
     analogWrite(rPin,Pinb); 
  analogWrite(gPin,0); 
  analogWrite(bPin,0);
  }
  // 2
  
  if (cmd.value== 0xFF18E7){ // 0x helps the computer know to look for a hexidecimal 
    a=2; 
   
    myCom ="you pressed 2";
    Serial.println(myCom);
  }
 if (a ==2){
     analogWrite(rPin,0); 
  analogWrite(gPin,Pinb); 
  analogWrite(bPin,0);
 }
  // 3
  
  if (cmd.value== 0xFF7A85){ // 0x helps the computer know to look for a hexidecimal 
    a=3; 
    
    myCom ="you pressed 3";
    Serial.println(myCom);
  }
   if (a ==3){
     analogWrite(rPin,0); 
  analogWrite(gPin,0); 
  analogWrite(bPin,Pinb);
   }
  // 4
  if (cmd.value== 0xFF10EF){ // 0x helps the computer know to look for a hexidecimal 
    a = 4; 
    myCom ="you pressed 4";
    Serial.println(myCom);
  }
  if (a == 4){
     analogWrite(rPin,Pinb); 
  analogWrite(gPin,Pinb); 
  analogWrite(bPin,0);
  }
  // 5
  if (cmd.value== 0xFF38C7){ // 0x helps the computer know to look for a hexidecimal 
    a = 5; 
    myCom ="you pressed 5";
    Serial.println(myCom);
  }
  if (a == 5){
     analogWrite(rPin,0); 
  analogWrite(gPin,Pinb); 
  analogWrite(bPin,Pinb);
  }
  // 6
  if (cmd.value== 0xFF5AA5){ // 0x helps the computer know to look for a hexidecimal 
    a = 6; 
    myCom ="you pressed 6";
    Serial.println(myCom);
  }
  if (a == 6){
     analogWrite(rPin,Pinb); 
  analogWrite(gPin,0); 
  analogWrite(bPin,Pinb);
  }
  // 7
  if (cmd.value== 0xFF42BD){ // 0x helps the computer know to look for a hexidecimal 
    a = 7;
    myCom ="you pressed 7";
    Serial.println(myCom);
  }
  if (a == 7){
     analogWrite(rPin,Pinb); 
  analogWrite(gPin,Pinb/2); 
  analogWrite(bPin,0);
  }
  // 8
  if (cmd.value== 0xFF4AB5){ // 0x helps the computer know to look for a hexidecimal 
    a = 8;
    myCom ="you pressed 8";
    Serial.println(myCom);
  }
  if (a == 8){
     analogWrite(rPin,Pinb/2); 
  analogWrite(gPin,0); 
  analogWrite(bPin,Pinb);
  }
  // 9
  if (cmd.value== 0xFF52AD){ // 0x helps the computer know to look for a hexidecimal 
    a = 9;
    myCom ="you pressed 9";
    Serial.println(myCom);
  }
  if (a == 9){
     analogWrite(rPin,0); 
  analogWrite(gPin,Pinb); 
  analogWrite(bPin,Pinb/2);
  }
  // vol+
  if (cmd.value== 0xFF629D){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed vol+";
    Serial.println(myCom);
  }
  // vol-
  if (cmd.value== 0xFFA857){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed vol-";
    Serial.println(myCom);
  }

  
  // EQ
  if (cmd.value== 0xFF9867){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed EQ";
    Serial.println(myCom);
  }

  // ST
  if (cmd.value== 0xFFB04F){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed ST";
    Serial.println(myCom);
  }
  // pause/play
  if (cmd.value== 0xFF02FD){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed pause/play";
    Serial.println(myCom);
  }
  // forward
  if (cmd.value== 0xFFC23D){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed forward";
    Serial.println(myCom);
  }
  // reverse 
  if (cmd.value== 0xFF22DD){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed reverse";
    Serial.println(myCom);
  }

  // Function
  if (cmd.value== 0xFFE21D){ // 0x helps the computer know to look for a hexidecimal 
  analogWrite(rPin,0); 
  analogWrite(gPin,0); 
  analogWrite(bPin,0); 
    myCom ="you pressed Function";
    Serial.println(myCom);
  }
  // Power
  if (cmd.value== 0xFFA25D){ // 0x helps the computer know to look for a hexidecimal 
  analogWrite(rPin,rPinb); 
  analogWrite(gPin,gPinb); 
  analogWrite(bPin,bPinb); 

  // count = count + 1; 
    myCom ="you pressed Power";
    Serial.println(myCom);
  }

  Serial.println(Pinb); 
//   if (count >1){
//     count = 0; 
//   }
//   if (count == 1){
//     digitalWrite(dir1,HIGH);
//   digitalWrite(dir2,LOW); 
//   mSpeed = 255; 
// analogWrite(speedPin,mSpeed);
//   }
  
// else if (count !=1){

// }
  
 Serial.println(count);
}
