#include <Wire.h>
#include <DFRobot_RGBLCD.h>                          //LCD header file
const float  OffSet = 0.483 ;
float V;
int P;
unsigned int lcd_r = 0, lcd_g = 0, lcd_b = 0;
unsigned long delaytime = 0, lighttime = 0;

DFRobot_RGBLCD lcd(16, 2);
void setup()
{lcd.init();
  delay(250);
  Serial.begin(115200);
  Serial.println("hello start");
  lighttime = millis();
  lcd.setCursor(0, 0);
  lcd.print("Water Pressure:");
  lcd.setRGB(255, 255, 000);
}
void loop() {
 lcd_r = random(256);
  delayMicroseconds(10);
  lcd_g = random(256);
  delayMicroseconds(10);
  lcd_b = random(256);
  if (millis() - lighttime > 3000)
  {
    lcd.setRGB(lcd_r, lcd_g, lcd_b);
    lighttime = millis();
  }
  //delay(100);

    V = analogRead(0)* 5.00 / 1024;                     //Sensor output voltage
    P = (V - OffSet) * 400*10;                          //Calculate water pressure
    lcd.setCursor(3, 1);

    lcd.print(  P/ 10000% 10);                         //LCD display
    lcd.print(  P/ 1000% 10);
    lcd.print(   P/ 100 % 10);
    lcd.print(   P/ 10 % 10);
    lcd.print('.');
    lcd.print(  P  % 10);
    lcd.print(" kPa");

}
