#include <Wire.h>  // llamar a la libreria 
#include <PS2X_lib.h>

PS2X ps2x;
int error = 0;
byte vibrate = 0;


int analogPin = A1; // entrada del potenciometro
int val, value; //constantes



void setup() {
  Wire.begin(); 
  error = ps2x.config_gamepad(7,12,A0,13, true, true);  //(clock, command, attention, data. para los True = sensor de presion y  vibracion)
  

}

void loop() {
  
  delay(50); 
  int val = 1;
  int va2 = 2;
  int va3 = 3;
  int va4 = 4;
  ps2x.read_gamepad();
  Wire.beginTransmission(23); //asignacion del puerto i2c    

  
   if(ps2x.Button(PSB_BLUE))
  {
   delay(50);       
   Wire.write(val); 
   Wire.endTransmission();
  } 
  else if(ps2x.Button(PSB_GREEN)){
   delay(50);   
   Wire.write(va2); 
   Wire.endTransmission();  
    } 
  else if(ps2x.Button(PSB_PINK)){
   delay(50);   
   Wire.write(va3); 
   Wire.endTransmission();  
    } 
  else if(ps2x.Button(PSB_RED)){
   delay(50);   
   Wire.write(va4); 
   Wire.endTransmission();  
    } 
 
}













