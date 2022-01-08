#include "config.h"
#include "joystick.h"
// UP: 20
// DOWN: 21
// LEFT: 30
// RIGHT: 31



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