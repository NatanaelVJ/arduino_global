#include <QTRSensors.h>


//Mapeo de pines
#define STBY 8  
#define AIN1  9   
#define AIN2  10 
#define PWMB  5
#define PWMA  11 
#define BIN1  7    
#define BIN2  6  


void setup() {
  // put your setup code here, to run once:
  pinMode(BIN2  ,OUTPUT);
  pinMode(STBY  ,OUTPUT);
  pinMode(BIN1  ,OUTPUT);
  pinMode(PWMB  ,OUTPUT);
  pinMode(AIN1  ,OUTPUT);
  pinMode(AIN2  ,OUTPUT);
  pinMode(PWMA  ,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(500);
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  delay (500);
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,HIGH);
  delay(500);
    digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  delay (500);
  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,HIGH);
  delay(500);
  

}
