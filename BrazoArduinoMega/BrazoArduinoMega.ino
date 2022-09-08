#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define EN 8 // stepper motor enable
#define X_DIR 5// x axis direction control
#define Y_DIR 6// y axis direction control
#define Z_DIR 7// z axis direction control
#define X_STP 2// x axis step control
#define Y_STP 3// y axis step control
#define Z_STP 4// z axis step control

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

int Pulgar = 0;
int Indice = 1;
int Dedos = 2;
int Muneca = 3;
int Hombro = 8;


int pot =A8;
int po,parar;

void setup() {

  Serial.begin(9600);
  
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW); 
  
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  
  
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}

void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  delay(50);
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(800);
  }
}

void Lec(){
    
    int valor = analogRead(A8);
    int po=map(valor, 0, 1023, 0, 10);
    Serial.println(po);
    delay(1);
    return po;
    } 

void inicio()

{

setServo(Pulgar,180);
setServo(Dedos,150);
setServo(Indice,180);
setServo(Muneca,90);

}
void loop() {

inicio();

}
