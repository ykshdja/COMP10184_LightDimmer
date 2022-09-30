/**
 * @author - Yash Khanduja, 000826385 - 30th-September, 2022
 * @version - 6.1.4 (-std=gnu+17)
 * Statement of Authorship - I Yash Khanduja, 000826385 - Hereby declare that this is my own work.
 * 
 */


#include <Arduino.h>
const int pushBtnPin = D5; // Button Pin
const int analogPin = A0; // Analog Pin
bool currentState = false; //LED State
bool prevBtnState = false;
int pot;
int led;

bool chechBtnPress()
{
   bool btnState = digitalRead(pushBtnPin) == LOW;
   bool prevState = prevBtnState;
   prevBtnState = btnState;
   if(!btnState)
   {
    return false;
   }
   return true;

}


void setup() {

  Serial.begin(115200); 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(pushBtnPin, INPUT_PULLUP);

}

void loop() {
if(chechBtnPress()){
  Serial.println("Button Pressed");
  currentState = !currentState;

}

if(currentState){
    pot = analogRead(analogPin);
    Serial.println(pot);
    led = map(pot,0,1023,0,255); // From 0 to 255;
    Serial.println(led);
    analogWrite(LED_BUILTIN,pot);
}
else{
   digitalWrite(LED_BUILTIN, HIGH);
}


}


/**
 * void checkButton()
{
  btnPressed = !btnPressed;
  //Serial.printf("ESP6288 Chip ID: %d\n", ESP.getChipId());
  Serial.print("Button Pressed(Digital) ON/OFF = ");
  Serial.println(btnPressed);

  if(btnPressed == HIGH)
  {
    Serial.println("ON");
    digitalWrite(LED_BUILTIN,LOW);
    
  }
  if(btnPressed == LOW){
       Serial.println("OFF");
      digitalWrite(LED_BUILTIN,HIGH);
  }
 while(digitalRead(pushbtnPin) == LOW);
 delay(100);

}
 * 
 * **/