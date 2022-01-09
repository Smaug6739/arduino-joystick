#include <Arduino.h>
#include "joystick.h"
#include "config.h"


int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// UP: 1
// DOWN: 2
// LEFT: 4
// RIGHT: 8

int getValue (){

  // Read the joystick position
	xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  // map the joystick position
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);
  
  if(mapX > 100) {
    //UP
    return 1;
  }
  if(mapX < -100) {
    // DOWN
   return 2;
  } 
  if(mapY < -100) {
    // LEFT
    return 4;
  }
  if(mapY > 100) {
    // RIGHT
    return 8;
  }

  return 0;
}

// ------------FOR DEBUGGING----------------
/* 
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.print(mapY);
  Serial.print(" | Button: ");
  Serial.println(SW_state);

*/