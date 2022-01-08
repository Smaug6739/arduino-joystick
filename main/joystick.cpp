#include <Arduino.h>
#include "joystick.h"
#include "config.h"


int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

// UP: 20
// DOWN: 21
// LEFT: 30
// RIGHT: 31

int getValue (){
  
  

	xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapX = map(xPosition, 0, 1023, -512, 512);
  mapY = map(yPosition, 0, 1023, -512, 512);


  
  if(mapX > 100) {
    return 20;
  }
  else if(mapX < -100) {
    return 21;
  } 
  if(mapY > 100) {
    return 31;
  }
  else if(mapY < -100) {
    return 30;
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