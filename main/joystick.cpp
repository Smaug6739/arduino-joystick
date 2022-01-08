#include "joystick.h"
#include <Arduino.h>

int VRx2 = A0;
int VRy2 = A1;
int SW2 = 2;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapX = 0;
int mapY = 0;

int getValue (){
  
  

	xPosition = analogRead(VRx2);
  yPosition = analogRead(VRy2);
  SW_state = digitalRead(SW2);
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