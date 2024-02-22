#include <DHT.h>
#include <LiquidCrystal.h>
int rs = 7; 
int en = 8; 
int d4 = 9; 
int d5 = 10; 
int d6 = 11; 
int d7 = 12; 
LiquidCrystal lcd(rs,en,d4,d5,d6,d7); 

#define Type DHT11
int sensePin = 2; 
DHT HT(sensePin,Type); 
float humidity; 
float tempC; 
float tempF; 
float tempK;
int dt = 4000; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  HT.begin();
  delay(dt); 
   lcd.begin(16,2); 

}

void loop() {
  // put your main code here, to run repeatedly:
   
  humidity = HT.readHumidity(); 
  tempC = HT.readTemperature(); 
  tempF = HT.readTemperature(true); 
  tempK = tempC + 273.15; 
  Serial.print("Humidity: "); 
  Serial.println(humidity); 
  Serial.print("Temp in C "); 
  Serial.println(tempC); 
  Serial.print("Temp in F ");
  Serial.println(tempF);
  Serial.print("Temp in K "); 
  Serial.println(tempK); 
  delay(dt); 
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(tempC); 
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("Humidity:");
  lcd.print(humidity); 
  






}
