#include "joystick.h"
#include "config.h"

void setup() {
  Serial.begin(9600); 
  
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  
}

void loop() {
 
  Serial.println(getValue());

  delay(700);
}