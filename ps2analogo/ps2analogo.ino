#include "PS2X_lib.h"  //for v1.6

PS2X ps2x; // create PS2 Controller Class

int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup(){
  Serial.begin(115200);
  
  error = ps2x.config_gamepad(10,12,11,13, true, true); //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  
  if(error == 0){
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
    Serial.println("Go to www.billporter.info for updates and to report bugs.");
  }
   
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
   
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
   
  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
   
  type = ps2x.readType(); 
    
  switch(type) {
    case 0:
      Serial.println("Unknown Controller type");
      break;
    case 1:
      Serial.println("DualShock Controller Found");
      break;
    case 2:
      Serial.println("GuitarHero Controller Found");
      break;
    default:
      break;
  }
}

void loop(){

    int ly;
    int lx;
    
    ps2x.read_gamepad(false, vibrate);        

    ly = ps2x.Analog(PSS_RY), DEC;
    lx = ps2x.Analog(PSS_RX), DEC;
    delay(50);
    Serial.print("LY = ");
    Serial.print(ly);
    Serial.print(" LX = ");
    Serial.println(lx);
     
   delay(50);


    
    
    
}
