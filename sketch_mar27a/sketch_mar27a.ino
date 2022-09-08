#include <PS2X_lib.h>

PS2X ps2x;

int error = 0;
byte vibrate = 0;
int Distancia = 0; 



void setup() {
                 
  pinMode(8, OUTPUT);    
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.begin(9600);
  error = ps2x.config_gamepad(8,12,A0,13, false, false);  //(clock, command, attention, data. para los True = sensor de presion y  vibracion)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
}


void loop() {
  // El motor da un paso
  digitalWrite(9, HIGH);
  delayMicroseconds(100);         
  digitalWrite(9, LOW);
  delayMicroseconds(100);
  Distancia = Distancia + 1;  
 
  // Comprobamos si el motor ha dado una vuelta completa (1600 pasos)
  if (Distancia == 15000)
  {
    // Si ha dado la vuelta cambiamos el sentido de rotacin
    if (digitalRead(8) == LOW)
    {
      digitalWrite(8, HIGH);
    }
    else
    {
      digitalWrite(8, LOW);
    }
    //reiniciamos el contador de pasos
    Distancia = 0;
   
    //esperamos un segundo
    delay(1000);
  }
}
