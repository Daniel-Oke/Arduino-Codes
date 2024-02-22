#include <LiquidCrystal.h>
int rs = 7; 
int en = 8; 
int d4 = 9; 
int d5 = 10; 
int d6 = 11; 
int d7 = 12; 
float num; 
float num1; 
float num2;  
String Operator; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 
int dt = 5000; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 

 lcd.begin(16,2); 
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("input frist variable");
  while (Serial.available()==0){
  }
  num1 = Serial.parseFloat();
  Serial.print("first# is "); 
  Serial.println(num1); 
  lcd.clear(); 

  lcd.setCursor(0,0);
  lcd.print("input Second #");
  while (Serial.available()==0){
  }
  num2 = Serial.parseFloat();
   Serial.print("Second# is "); 
  Serial.println(num2); 
  lcd.clear();
//operator 
lcd.setCursor(0,0);
  lcd.print("input operator: ");
  lcd.setCursor(0, 1); 
  lcd.print("+ - * /"); 
  while (Serial.available()==0){
  }
  Operator = Serial.readString(); 
  Serial.println(Operator); 
  lcd.clear();
  if (Operator == "+"){
    num = num1 + num2; 
  }
  if (Operator == "-"){
    num = num1 - num2; 
  }
  if (Operator == "*"){
    num = num1 * num2; 
  }
  if (Operator == "/"){
    num = num1 / num2; 
  }
  Serial.println(num); 
lcd.setCursor(0,0);
lcd.print("the answer is: "); 
lcd.setCursor(0,1);
lcd.print(num);
delay(dt);

  
  
}
