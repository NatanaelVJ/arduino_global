#include<Wire.h>

unsigned long lastTime = 0, sampleTime = 100;

void setup() {

Serial.begin(9600);

}

void loop() {

  if(millis()-lastTime>=sampleTime)
  {
    lastTime = millis();  
 
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
   }    


}
