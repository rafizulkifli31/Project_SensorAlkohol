#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);// initialize the LCD Library w.r t. RS,E,D4,D5,D6,D7
int PIR_SENSOR_LOW=3;
int RED_LED=4;
int BLUE_LED=5; 

void setup() {
  // put your setup code here, to run once:
pinMode(PIR_SENSOR_LOW, INPUT_PULLUP);//configure pin5 as an input and enable the internal pull-up resistor
pinMode(RED_LED,OUTPUT);//configure pin4 as an output
pinMode(BLUE_LED,OUTPUT);//configure pin5 as output
lcd.begin(20,4);// set up the LCD's number of columns and rows
lcd.setCursor(0,0);// set cursor to column0 and rowl
lcd.print("SISTEM PENDETEKSI");// Print a message to the LCD.
lcd.setCursor(0,1);// set cursor to column0 and rowl
lcd.print("ALKOHOL");// Print a message to the LCD.
lcd.setCursor(0,2);// set cursor to column0 and row2
lcd.print("TELEKOMUNIKASI PNJ");// Print a message to the LCD.
delay(500); 
}

void loop() {
  // put your main code here, to run repeatedly:
  int PIR_SENSOR_LOW_READ = digitalRead(PIR_SENSOR_LOW);//read the pushbutton value into a variable
  if (PIR_SENSOR_LOW_READ == LOW)// Read PIN 5 as HIGH PIN
  {
    lcd.clear();
    lcd.setCursor(0,3);// set cursor to column0 and row2
    lcd.print("ALKOHOL NOT DETECTED");// Print a message to the LCD.
    digitalWrite(RED_LED, LOW);//High PIN3
    digitalWrite(BLUE_LED, HIGH);//LOW PIN2
    delay(50);
  }
  else //oterwise
  {
    lcd.clear();
    lcd.setCursor(0, 3);// set cursor to column0 and row3
    lcd.print("ALKOHOL DETECTED");// Print a message to the LCD.
    digitalWrite(BLUE_LED, LOW);//High PIN2
    digitalWrite(RED_LED, HIGH);//Low PIN3
    delay(50);
  }
}
