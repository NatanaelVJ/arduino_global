#include <LiquidCrystal.h> 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {  
  Serial.begin(9600);  
  
  Serial.println("Prueba de DHT");  
 
}

void loop() { 
  Serial.println("Prueba de DHT");   

}  
