// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);



const float  OffSet = 0.439 ;
float V,LT, P;


byte nivel[8] = {
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
B11111,
};



void setup() {
// set up the LCD's number of columns and rows:

// Print a message to the LCD.
lcd.begin(16, 2);
lcd.print("iniciando...");
lcd.createChar (1,nivel);
Serial.begin(9600);
}

void function(){  
  
   V = analogRead(0) * 5.00 / 1024;   //voltaje (0.4V - 4.5V)
   P = (V - OffSet) * 400*0.145038;   //Litros
   LT= 20*P ;
  //Serial.print("Voltage:");
  //Serial.print(V, 3);
  //Serial.println("V");
  
   lcd.clear();
   lcd.print("Cap.");
   lcd.print(" ");
   lcd.print(V, 1);
   lcd.print(" lt");


  if (V >=2){
   lcd.setCursor(0, 1);   //marca 1 
   lcd.write(byte(1));
   //lcd.setCursor(0,1);  // Escribir en fila de abajo
   //lcd.print("%"); 
   //lcd.print(" VALOR");
  }
   delay (500);
}

  


void loop() {

   
   //function();
   


   function();
   delay(500);
  

}
