#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <LiquidCrystal.h>


#define SW_LCD A2
#define DT_LCD A1
#define CLK_LCD A0

int counter, state, lastState;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
uint8_t arrow[8] = {0x0, 0x04 ,0x06, 0x1f, 0x06, 0x04, 0x00, 0x00}; //flecha

const uint64_t my_radio_pipe = 0xE8E8F0F0E1LL;     //debe ser la misma direccion para el receptor
RF24 radio(59, 48); // ce and csn 

struct Data_to_be_sent { //se pueden tener hasta 38 canales de 8 bits
  byte ch1;
  byte ch2;
  byte ch3;
  byte ch4;
  byte ch5;
  byte ch6;
  byte ch7;
  
 
};

Data_to_be_sent sent_data;



void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode (SW_LCD,INPUT);
  pinMode (DT_LCD,INPUT);
  pinMode (CLK_LCD,INPUT);

  radio.begin();
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);  
  radio.openWritingPipe(my_radio_pipe);
  
  //
  sent_data.ch1 = 0; //pot1
  sent_data.ch2 = 0; //pot2
  sent_data.ch3 = 127; //X_RIGHT
  sent_data.ch4 = 127; //Y_RIGHT
  sent_data.ch5 = 127; //X_LEFT
  sent_data.ch6 = 127; //Y_LEFT
  sent_data.ch7 = 0; //SWITCH

  lastState = digitalRead(CLK_LCD);
  

}

void LCD(){  
   lcd.clear();
   lcd.print("Ctrl Universal");
   lcd.print(" ");
   delay (50); 
}

void encoder_lcd(){
  state=digitalRead(CLK_LCD);
  if(state != lastState){
    if(digitalRead(DT_LCD) != state){
      counter++;
    } 
    else{
      counter--;
    }
    
    lcd.clear();
    lcd.print(counter);
    delay (50);
  }
}

void loop() {

  //LCD();
  encoder_lcd();
  sent_data.ch1 = map(analogRead(A10), 0, 1024, 0, 255);
  sent_data.ch2 = map(analogRead(A11), 0, 1024, 0, 255);
  sent_data.ch3 = map(analogRead(A8), 0, 1024, 0, 255);
  sent_data.ch4 = map(analogRead(A9), 0, 1024, 0, 255);
  sent_data.ch5 = map(analogRead(A15), 0, 1024, 0, 255);
  sent_data.ch6 = map(analogRead(A13), 0, 1024, 0, 255);
  sent_data.ch7 = digitalRead(9);
  

  radio.write(&sent_data, sizeof(Data_to_be_sent));
}
