// include the library code:
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int servo_pin = 9 ;
const byte potansiyometre_pin = A1 ;
int pot_deger ;
int son_deger = 0 ;
int pwm;

void setup() {
  
  pinMode(servo_pin,OUTPUT) ;
  
  Serial.begin(9600) ;
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2) ;
  // Print a message to the LCD.
  
}

void loop() {
  
  pot_deger = analogRead(potansiyometre_pin) ;
  int yeni_deger = map(pot_deger,0,1023,0,180) ;

  Serial.println(yeni_deger);
  lcd.setCursor(0, 0) ;
  lcd.print("Pot_deger: ") ;
  lcd.setCursor(10, 0) ;
  lcd.print(yeni_deger);
  
  if(yeni_deger != son_deger){
  	son_deger = yeni_deger ;
    lcd.print("                         "); //ekranı temizledik
  	lcd.setCursor(0, 0) ;
    lcd.print("Pot_deger: ") ;
  	lcd.setCursor(10, 0) ;
  	lcd.print(yeni_deger);  
    servoPulse(servo_pin, yeni_deger);
    delay(10) ;
    }
  
  else {
    lcd.print("                         "); //ekranı temizledik
  	lcd.setCursor(0, 0) ;
    lcd.print("Pot_deger: ") ;
  	lcd.setCursor(10, 0) ;
  	lcd.print(yeni_deger);  
    servoPulse(servo_pin, yeni_deger);
    delay(10) ;
    }
  
  
  
}

void servoPulse(int servo_pin, int yeni_deger){ // Convert angle to microseconds
  pwm = (yeni_deger*11) + 500;
  digitalWrite(servo_pin,HIGH) ;
  delayMicroseconds(pwm) ;
  digitalWrite(servo_pin,LOW) ;
  delay(50) ; // Refresh cycle of servo
 
}