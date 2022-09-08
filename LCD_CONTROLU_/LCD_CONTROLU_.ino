// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
// set up the LCD's number of columns and rows:

// Print a message to the LCD.
lcd.begin(16, 2);
lcd.print("iniciando...");
Serial.begin(9600);
delay(500);
}

void LCD(){  
   lcd.clear();
   lcd.print("Prueba control");
   lcd.print(" ");

   
}

  


void loop() {


   LCD();
   delay(500);
  

}
