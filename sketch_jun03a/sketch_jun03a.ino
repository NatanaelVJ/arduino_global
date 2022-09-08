#include <LiquidCrystal.h>

#define RS  13
#define E   11
#define D4  5
#define D5  4 
#define D6  3
#define D7  2

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup() {

  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(" Arduin000000");
  delay(2000);
  
  }

void loop() {
  lcd.setCursor(0,1);
  lcd.print( millis()/1000);
}
