#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL;     //debe ser la misma direccion para el receptor
RF24 radio(59, 48); // ce and csn 

struct Data_to_be_sent { //se pueden tener hasta 38 canales de 8 bits
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
 
 
};

Data_to_be_sent sent_data;



void setup() {

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.openWritingPipe(my_radio_pipe);
  
  //
  sent_data.ch1 = 0; //pot1
  sent_data.ch2 = 0; //pot2
  sent_data.ch3 = 127; //X_RIGHT
  sent_data.ch4 = 127; //Y_RIGHT
  sent_data.ch5 = 127; //X_LEFT
  sent_data.ch6 = 127; //Y_LEFT
  sent_data.ch7 = 0; //SWITCH_A
 
  

}
void loop() {

  sent_data.ch1 = map(analogRead(A10), 0, 1024, 0, 255);
  sent_data.ch2 = map(analogRead(A11), 0, 1024, 0, 255);
  sent_data.ch3 = map(analogRead(A8), 0, 1024, 0, 255);
  sent_data.ch4 = map(analogRead(A9), 0, 1024, 0, 255);
  sent_data.ch5 = map(analogRead(A15), 0, 1024, 0, 255);
  sent_data.ch6 = map(analogRead(A13), 0, 1024, 0, 255);
  sent_data.ch7 = digitalRead(9);
  

  radio.write(&sent_data, sizeof(Data_to_be_sent));
}
