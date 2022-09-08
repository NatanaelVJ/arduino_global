
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <VarSpeedServo.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

void setup() {
  
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
}
 
void loop() {
   // pocision inicia
    
    setServo(1, 105); //cadera, si el aumenta la pierna ira hacia adelante
    setServo(2, 130);//rodilla, si el grado aumenta se flexiona hacia atras 
    setServo(3, 105);//tobillo, si aumenta el grado el pie va hacia adelante

    setServo(13,150);//cadera, si el aumenta el grado la pierna ira hacia atras
    setServo(14,165);////rodilla, si el grado aumenta se flexiona hacia adelante 
    setServo(15,55); //tobillo, si aumenta el grado el pie va hacia atras
    
    delay(1000);
     
      // primer Movimiento 

     setServo(1, 130); setServo(13,160); //caderaR caderaL
     setServo(2, 150); setServo(14,170);  //RodillaR RodillaL
     setServo(3, 110); setServo(15,35); // tobilloR tobilloL 
     delay(300);
     setServo(1, 105);
     setServo(2, 130);
     setServo(3, 95);
     delay(300);
     setServo(13,150);
     setServo(14,165);
     setServo(15,65);
     delay(500);
     

    // Segundo Movimiento 

     setServo(1, 75); setServo(13,115); //caderaR caderaL
     setServo(2, 130); setServo(14,145);  //RodillaR RodillaL
     setServo(3, 130); setServo(15,50); // tobilloR tobilloL 
     delay(300);
     setServo(13,150);
     setServo(14,165);
     setServo(15,65);
     delay(300);
      setServo(1, 105);
     setServo(2, 130);
     setServo(3, 95);
     delay(500);
     
      

    
      
   }
