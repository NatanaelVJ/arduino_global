#include <Servo.h>
 


Servo PiernaD_Tibia, PiernaD_Femur, PiernaI_Tibia, PiernaI_Femur;
 
void setup() {
  
  Serial.begin(9600);
 
  
  PiernaD_Femur.attach(3);
  PiernaD_Tibia.attach(5);
  
  PiernaI_Femur.attach(10);
  PiernaI_Tibia.attach(11);
  
}
 
void loop() {
  
  PiernaD_Femur.write(90);
  PiernaD_Tibia.write(90);
  
  //PiernaI_Femur.write(90);
  //PiernaI_Tibia.write(90);

  delay(500);
 
 
}
