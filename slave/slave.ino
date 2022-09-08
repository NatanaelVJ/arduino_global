#include<Wire.h> // definir libreria 


int LED = 13;
int va1,va2,va3,va4,rd;
int tempo;
int sentido1 = LOW;
int sentido2 = HIGH;



void setup() {

     pinMode(LED, OUTPUT);
     Wire.begin(23); //i2c 23
     Wire.onReceive(receiveEvent);

     Serial.begin(9600);
     Serial.println("I2C Slave Demostration"); //

     pinMode(8, OUTPUT);    
     pinMode(9, OUTPUT);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
}

void receiveEvent(){
  
  rd = Wire.read();  
  delay(50);
  
  }

void loop() {
     Wire.read(); 

     //delay(50);
     
     if(rd == 1){

     digitalWrite(LED, HIGH);
     delay(1000);
     digitalWrite(LED, LOW);
     delay(1000);
     }

     if(rd == 2){
      digitalWrite(LED, LOW);
      }

     if (rd == 3){
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      delayMicroseconds(100);         
      digitalWrite(9, LOW);
      delayMicroseconds(100);
     }
     
     if (rd == 4){
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      delayMicroseconds(100);         
      digitalWrite(9, LOW);
      delayMicroseconds(100);
     }

     
}
