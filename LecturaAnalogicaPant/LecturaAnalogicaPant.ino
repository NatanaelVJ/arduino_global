#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
float V, P;
float Offset =0.435; 


void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  

}

void loop() {

 int sensorValue = analogRead(A0); //La lectura analogica va desde 0 a 1023, si contamos el 0 son 1024. 

 Serial.println(sensorValue);
 delay(1);

 V = 0;
 for (int i= 0; i<10; i++){
 V = V + (sensorValue*5.0/1024.0);
 delay(50);

 
 
 }

 float Vout = V/10.0;
 
 float V1 = (sensorValue*5.0/1024.0);
 P = (V1-Offset)*400;

 lcd.clear();
 lcd.print("Voltaje: ");
 lcd.print(" ");
 lcd.print(V1);
 //lcd.print(".");
 
 lcd.setCursor(0,1);
 lcd.print("Presion: ");
 lcd.print(P);
 lcd.print("Kpa: ");
 
 delay (50);
}
