#include <IRremote.h>
int IRpin = 9; 
IRrecv IR(IRpin);
decode_results cmd; 
String myCom; 
int speedPin = 10; 
int dir1 = 12; 
int dir2 = 13; 
int mSpeed; // motor speed at max voltage 
int delt =50; 
int count = 0 ; 
int countU = 0 ;

int cam; 
int L ; 
int R  ; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  IR.enableIRIn(); 
  pinMode(speedPin,OUTPUT); 
  pinMode(dir1,OUTPUT); 
  pinMode(dir2,OUTPUT); 
}

void loop() {
  while(IR.decode(&cmd)==0){

  }
  Serial.println(cmd.value,HEX);
  delay(1500); 
  IR.resume();
  // 0
  if (cmd.value== 0xFF6897){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 0";
    Serial.println(myCom);
  }
  // 1
  if (cmd.value== 0xFF30CF){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 1";
    Serial.println(myCom);
  }
  // 2
  if (cmd.value== 0xFF18E7){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 2";
    Serial.println(myCom);
  }

  // 3
  if (cmd.value== 0xFF7A85){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 3";
    Serial.println(myCom);
  }
  // 4
  if (cmd.value== 0xFF10EF){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 4";
    Serial.println(myCom);
  }
  // 5
  if (cmd.value== 0xFF38C7){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 5";
    Serial.println(myCom);
  }
  // 6
  if (cmd.value== 0xFF5AA5){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 6";
    Serial.println(myCom);
  }
  // 7
  if (cmd.value== 0xFF42BD){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 7";
    Serial.println(myCom);
  }
  // 8
  if (cmd.value== 0xFF4AB5){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 8";
    Serial.println(myCom);
  }
  // 9
  if (cmd.value== 0xFF52AD){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed 9";
    Serial.println(myCom);
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
  // up
  if (cmd.value== 0xFF906F){ // 0x helps the computer know to look for a hexidecimal 
    countU = countU + 1;
    myCom ="you pressed up";
    cam = 1; 
    Serial.println(myCom);
  }
  // down
  if (cmd.value== 0xFFE01F){ // 0x helps the computer know to look for a hexidecimal 
    countU = countU - 1 ;
    myCom ="you pressed down";
    cam = 2;
    Serial.println(myCom);
  }// EQ
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
   R= 1; 
   L = 0; 

    myCom ="you pressed forward";
    Serial.println(myCom);
  }
  // reverse 
  if (cmd.value== 0xFF22DD){ // 0x helps the computer know to look for a hexidecimal 
  R= 0; 
   L = 1; 


    myCom ="you pressed reverse";
    Serial.println(myCom);
  }

  // Function
  if (cmd.value== 0xFFE21D){ // 0x helps the computer know to look for a hexidecimal 

    myCom ="you pressed Function";
    Serial.println(myCom);
  }
  // Power
  if (cmd.value== 0xFFA25D){ // 0x helps the computer know to look for a hexidecimal 
  count = count + 1; 
    myCom ="you pressed Power";
    Serial.println(myCom);
  }
  if (count >1){
    count = 0; 
  }
 if (countU > 3){
    countU = 3; 
  }
 else if (countU < 0){
    countU = 0; 
  }
  if (count == 1){
     digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  mSpeed = 255; 
analogWrite(speedPin,mSpeed);
  if( L == 1 && R == 0 ){
     digitalWrite(dir1,HIGH);
  digitalWrite(dir2,LOW);
  }
if( L == 0 && R == 1 ){
    digitalWrite(dir1,LOW);
  digitalWrite(dir2,HIGH);
  }
  //

  }
  
 if  (count == 1 && cam ==1 ){
     mSpeed = 85*countU; 
     if(mSpeed > 255){
      mSpeed = 255;
     }
analogWrite(speedPin,mSpeed);
  }

  else if  (count == 1 && cam ==2 ){
     mSpeed = 85*countU; 
     if(mSpeed < 0){
      mSpeed = 0;
     }
analogWrite(speedPin,mSpeed);
  }
  
else if (count != 1){
mSpeed = 0; 
analogWrite(speedPin,mSpeed);
}
 Serial.println(count);
 Serial.println(countU);
 Serial.println(cam);




}
