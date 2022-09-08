// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

byte cuerpo[8] = {
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
lcd.print("hello, world!");
lcd.createChar (2,cuerpo);

}

void loop() {
// set the cursor to column 0, line 1
// (note: line 1 is the second row, since counting begins with 0):
lcd.setCursor(0, 1);
lcd.write(byte(2));
// print the number of seconds since reset:
//lcd.print(millis() / 1000);
}
