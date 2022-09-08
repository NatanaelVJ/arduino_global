#include <LiquidCrystal_I2C.h>

#include <PID_v1.h>

#include <Ultrasonic.h>

#include <Servo.h>

#include <Keypad.h>

const byte filas = 4; //four rows
const byte columnas = 3; //three columns
char keys[filas][columnas] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'#','0','*'}
};
byte pinsfilas[filas] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte pinscolumnas[columnas] = {9, 8, 7}; //connect to the column pinouts of the keypad


Keypad keypad = Keypad( makeKeymap(keys), pinsfilas, pinscolumnas, filas, columnas);


LiquidCrystal_I2C lcd(0x27,16,2);

Servo eje1;


int pinservo = 5;
int PULSOMIN = 1000;
int PULSOMAX = 2500;
int trigger = 3;
int echo =  2;
float tiempo_de_espera,distancia;
float Kp = 0.08;
float Ki = 0;
float Kd = 5;
double Setpoint, Input, Output, ServoOutput;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

int numero = 9;

 void setup() {
  
   eje1.attach(pinservo, PULSOMIN, PULSOMAX);
  
  Serial.begin (9600);
  pinMode (trigger,OUTPUT);
  pinMode (echo,INPUT);

lcd.init();
  lcd.backlight();
  lcd.clear();
 lcd.setCursor(0,0);
  lcd.print("Microcontrolador"); 
  lcd.setCursor (0,1);
  lcd.print("     PID ");
  delay(3000);

  
  Input = distancia;
  myPID.SetMode(AUTOMATIC);
  myPID.SetOutputLimits(-1000,2500);
 
}
void loop() {
 
 digitalWrite (trigger,LOW);
 delayMicroseconds(2);
 digitalWrite(trigger,HIGH);
 delayMicroseconds (10);
 digitalWrite (trigger,LOW);


 tiempo_de_espera = pulseIn (echo,HIGH);
 distancia =(tiempo_de_espera/2)/29.15;
 Serial.print (distancia);
 Serial.println("cm");
 
 lcd.setCursor(0,0);
 lcd.print("setP = ");
 lcd.println(numero);
 lcd.println("cm");
 lcd.setCursor (0,1);
 lcd.print(distancia);
 lcd.println("cm");
 delay(800);
 
 char tecla = keypad.getKey();
  lcd.display();
  {
  if (tecla != NO_KEY){
  numero = tecla - 48;  
  
  lcd.setCursor(0,0);
  lcd.print("setP = ");
  lcd.println(numero); 
  lcd.println("cm");
  }
  }

   

  {

Setpoint = numero;

 Input = distancia;
 myPID.Compute();
 ServoOutput = 70+Output;
 eje1.write(ServoOutput);


 }
 
 

}
