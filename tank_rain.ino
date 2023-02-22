#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;

void setup() {
  // put your setup code here, to run once:
   myservo.attach(5);
  
  lcd.init();
  lcd.init();

  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("Sensor Value: ");

}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorValue = analogRead(27);

  lcd.setCursor(3,1);
  lcd.print(sensorValue);
  delay(1000);
  if ( sensorValue > 1000){

    //for (pos = 0; pos <= 55; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(55);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  //}
    
  }else{
     //for (pos = 55; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(0);              // tell servo to go to position in variable 'pos'
    delay(5);                       // waits 15ms for the servo to reach the position
  //}
    


  }
}
