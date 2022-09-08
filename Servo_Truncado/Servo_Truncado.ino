#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

int i,pos;

void setup() {
  servos.begin();
  Serial.begin(9600);
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  

}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}


void servo (){


 int temp = 2000;

   //sentido 1

    setServo(0,90);
    delay(2000); // 3280 vuelta
    setServo(0,99);
    delay(2000);
    
     
    //sentido 2
    
     setServo(0,105);
    delay(2000);
    setServo(0,99);
    delay(2000);
    
     
    //sentido 1
    
    setServo(1,104);
    delay(temp);
    setServo(1,100);
    delay(temp);

    //sentido 2
    
    setServo(1,96);
    delay(temp); // 3280 vuelta
    setServo(1,100);
    delay(temp);
    
     
    //sentido 1
    
    setServo(2,95);
    delay(temp);
    setServo(2,99);
    delay(temp);

    //sentido 2
    
    setServo(2,103);
    delay(temp);
    setServo(2,99);
    delay(temp);

    setServo(3, 0);
    delay(1000);    
    setServo(3, 180);
    delay(1000);    
    }
    
  




void loop() {

  servo(); 
  delay(50);

}
