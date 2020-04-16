#include<LiquidCrystal.h>
LiquidCrystal lcd (8,9,10,11,12,13);

const int red= 6;
const int green=4;
const int blue =5;

const int suhu= A5;
const int vibration =7;

int baselineTemp =0;
int celcius = 0;



void setup()
{
  lcd.begin(16,2);
  pinMode(suhu,INPUT);
  pinMode(vibration, OUTPUT);
  
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
  
  digitalWrite(green, HIGH);
  delay(500);
}

void loop(){
 baselineTemp=40;
  celcius = map(((analogRead(suhu)-20)*3.04), 0, 1023, -40, 125);
    
  lcd.setCursor(1,0);
  lcd.print("Suhu Sekarang");
  
  lcd.setCursor(6,1);
  lcd.print(celcius);
  lcd.print(" C");
  
 if(celcius>20){
    digitalWrite(vibration,HIGH);
   
    digitalWrite(red, HIGH);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    
  
 }else{
    digitalWrite(blue, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
   
   digitalWrite(vibration, LOW);
  }  
}
