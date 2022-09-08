#include <PS2X_lib.h>


PS2X ps2x;

int error = 0;
byte vibrate = 0;
int Distancia = 0; 

int sentido1 = LOW;
int sentido2 = HIGH;
int BotonAzul = 0;

void setup() {

  Serial.begin(57600);
  delay(300);   


                 
  pinMode(8, OUTPUT);    
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);

 
  error = ps2x.config_gamepad(7,12,A0,13, true, true);  //(clock, command, attention, data. para los True = sensor de presion y  vibracion)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
  
}

void lee(){
  ps2x.read_gamepad(); 
}

void mueve(){
     digitalWrite(9, HIGH);
   delayMicroseconds(100);         
   digitalWrite(9, LOW);
   delayMicroseconds(100);
 
}



void loop() {

   
   lee();
   mueve();
   
   
   

   
 
   
 


}


  








