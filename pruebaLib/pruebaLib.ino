#include "encoder.h"

int PinCLK = 3;
int PinDT = 2;
int baudios = 9600;
encoder metodo(PinCLK, PinDT);



void setup() {
  // put your setup code here, to run once:

}

void loop() {
 1POSICION = metodo._posicion(POSICION) 
 metodo.posicion_enconder(1POSICION)

}
