#ifnedf encoder.h
#define encoder_H
#include "arduino.h"

class encoder
{
  private:
        int ANTERIOR = 0;
        volatile int POSICION = 0;
        volatile boolean VueltaDetectada;
        volatile boolean DireccionRotacion;
        const int CLK;
        const int DT;
        const int SW;
        int POSICION;
  public:
        encoder(int PinCLK, int PinDT, int baudios);
        void posicion_enconder();
        void _posicion();
};









 
