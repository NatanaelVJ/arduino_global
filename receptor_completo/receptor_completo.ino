/* Receiver code for the Arduino Radio control with PWM output
 * Install the NRF24 library to your IDE
 * Upload this code to the Arduino UNO, NANO, Pro mini (5V,16MHz)
 * Connect a NRF24 module to it:
 
    Module // Arduino UNO,NANO
    
    GND    ->   GND
    Vcc    ->   3.3V
    CE     ->   D9
    CSN    ->   D10
    CLK    ->   D13
    MOSI   ->   D11
    MISO   ->   D12

This code receive 1 channels and prints the value on the serial monitor
Please, like share and subscribe : https://www.youtube.com/c/ELECTRONOOBS
*/


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

const uint64_t pipeIn = 0xE8E8F0F0E1LL;     //Remember that this code is the same as in the transmitter
RF24 radio(9, 10);  //CSN and CE pins

// The sizeof this struct should not exceed 32 bytes
struct Received_data {
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
 
};

int ch1_value = 0;
int ch2_value = 0;
int ch3_value = 0;
int ch4_value = 0;
int ch5_value = 0;
int ch6_value = 0;
int ch7_value = 0;



Received_data received_data;


/**************************************************/

void setup()
{
  Serial.begin(9600);
  //We reset the received values
  received_data.ch1 = 127;
  received_data.ch2 = 127;
  received_data.ch3 = 127;
  received_data.ch4 = 127;
  received_data.ch5 = 127;
  received_data.ch6 = 127;
  received_data.ch7 = 0;
  
 
  //Once again, begin and radio configuration
  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.openReadingPipe(1,pipeIn);
  
  //We start the radio comunication
  radio.startListening();

}

/**************************************************/

unsigned long last_Time = 0;

//We create the function that will read the data each certain time
void receive_the_data()
{
  while ( radio.available() ) {
  radio.read(&received_data, sizeof(Received_data));
  last_Time = millis(); //Here we receive the data
}
}

/**************************************************/

void loop()
{
  //Receive the radio data
  receive_the_data();

  
  ch1_value = map(received_data.ch1,0,255,1000,2000);  //1996 max
  ch2_value = map(received_data.ch2,0,255,1000,2000);  //1996 max
  ch3_value = map(received_data.ch3,0,255,1000,2000); // medio = 1498; Izquierda=1000; Derecha=1996
  ch4_value = map(received_data.ch4,0,255,1000,2000); // medio = 1498; arriba=1000; abajo=1996
  ch5_value = map(received_data.ch5,0,255,1000,2000); // medio = 1490; Izquierda=1000; Derecha=1996
  ch6_value = map(received_data.ch6,0,255,1000,2000); // medio = 1494-1498; arriba=1000; abajo=1996
  ch7_value = map(received_data.ch7,0,1,1000,2000);
  Serial.println(ch5_value);
  //Serial.println(ch4_value); //arriba 1000, abajo 2000 medio 1500 -1498 
  
  
 
  
  
}//Loop end
