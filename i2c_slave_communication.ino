/*
 LCD part reference to:
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

#include <LiquidCrystal.h>
#include <Wire.h>

#define LED_PIN 13
boolean ledon = HIGH;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte slave_address = 7;
int echonum = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print startup message to the LCD.
  lcd.print("Arduino Uno");
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);
  
  Wire.begin(slave_address);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

}

void loop() {

}

char echo[32];
int index = 0;

void requestEvent(){
  toggleLED();
  if(index==0){
    Wire.write(echonum);
  }else{
    Wire.write(echo[echonum-1-(index-1)]);
  }
  index++;
}

void receiveEvent(int howMany) {
  
  lcd.clear();
  
  int numOfBytes = Wire.available();
  //display number of bytes and cmd received, as bytes
  lcd.setCursor(0, 0);
  lcd.print("len:");
  lcd.print(numOfBytes);
  lcd.print(" ");
  
  byte b = Wire.read();  //cmd
  lcd.print("cmd:");
  lcd.print(b);
  lcd.print(" ");
  
  index = 0;

  //display message received, as char
  lcd.setCursor(0, 1);
  for(int i=0; i<numOfBytes-1; i++){
    char data = Wire.read();
    lcd.print(data);
    
    echo[i] = data;
  }
  
  echonum = numOfBytes-1;
}

void toggleLED(){
  ledon = !ledon;
  if(ledon){
    digitalWrite(LED_PIN, HIGH);
  }else{
    digitalWrite(LED_PIN, LOW);
  }
}
