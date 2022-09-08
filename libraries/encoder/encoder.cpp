#endif
#include "encoder.h"
#include "arduino.h"

encoder::posicion_enconder(int PinCLK, int PinDT, int baudios, int POSICION)
{
  Serial.begin(baudios);
  pinMode(PinCLK, INPUT);
  pinMode(PinDT, INPUT);
  CLK = PinCLK;
  DT = PinDT;
  attachInterrupt(digitalPinToInterrupt(PinDT), encoder, LOW);
  Serial.println("listo");
  Serial.println(POSICION);
  
}

encoder::_posicion(int POSICION, int ANTERIOR, const int CLK)
  {
  if (POSICION !=ANTERIOR){
  Serial.println(POSICION);
  ANTERIOR = POSICION;
  }
  }  
  static unsigned long ultimaInterrupcion = 0;
  unsigned long tiempoInterrupcion = millis();
   if (tiempoInterrupcion - ultimaInterrupcion > 100) {
    if (digitalRead(PinCLK) == HIGH)
    {
      POSICION++ ;
    }
    else { 
      POSICION-- ;
    }
   POSICION = min(100, max(0, POSICION));
   ultimaInterrupcion = tiempoInterrupcion;
   return POSICION
  }           
  } 

