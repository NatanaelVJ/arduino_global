#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
 
void setup()
{
        // Inicializamos el puerto serie BT que hemos creado
  BT.begin(9600); 
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(Serial.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(Serial.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     Serial.write(Serial.read());
  }
}
