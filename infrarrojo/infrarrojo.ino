#include <Servo.h> // DECLARO LA LIBRERIA 
Servo SERVO1; //IDENTIFICO LOS SERVOS


void setup() {


SERVO1.attach(3,600,1500);
}
void loop() {

  SERVO1.write(0);
  delay(1000);
  SERVO1.write(90);
  delay(1000);
  
  
  
  
  
  

}
