#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

int Servo1 = 0;
int Servo2 = 1;
int Servo3 = 2;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servos.begin();  
servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}

void loop() {
  // put your main code here, to run repeatedly:

int sensorValue = analogRead(A0);

Serial.println(sensorValue);
delay(1);

if (sensorValue>900){

 setServo(Servo1,0);
 setServo(Servo2,0);
 setServo(Servo3,0);
 delay(200);
 }

 else 
setServo(Servo1,180);
setServo(Servo2,180);
setServo(Servo3,180);

}
