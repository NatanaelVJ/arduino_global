//Mapeo de pines
/*#define STBY 5//  
#define AIN1  8//   8
#define AIN2  7// 
#define PWMB  3// 3
#define PWMA  6// 6 
#define BIN1  4//    
#define BIN2  2//  2
*/
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#include <Servo.h>

#define rele 6
#define rele2 7 




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
Servo servoMotor;
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
  
  servoMotor.attach(A5);
  digitalWrite(rele, LOW);
  digitalWrite(rele2, LOW);
  pinMode(rele, OUTPUT);
  pinMode(rele2, OUTPUT);
  
  



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
  Serial.println(ch4_value);

  //ch4_value arriba 1000, abajo 1996 medio 1500 -1498 
  //ch5_value 1000 izquierda - 1996 derecha - medio = 1490;
    
  
  if (ch5_value > 1500 ){
    int servo = map(ch5_value, 1500, 2000, 90,60);
    servoMotor.write(servo);
    delay(5);
    }
  else if (ch5_value < 1480 ){

    int servo = map(ch5_value, 1500, 1000, 90,120);
    servoMotor.write(servo);
    delay(5);
    }    
  
//*************************************************************

 else if (ch4_value < 1490 ){   
    digitalWrite(rele, HIGH);
    digitalWrite(rele2, LOW);
    delay(50);
    
    }
  else if (ch4_value > 1600 ){   
    digitalWrite(rele2, HIGH);
    digitalWrite(rele, LOW);
    delay(50);
    }    
  else{
    digitalWrite(rele, LOW);
    digitalWrite(rele2, LOW);
    servoMotor.write(90);
    }


  
  
}
