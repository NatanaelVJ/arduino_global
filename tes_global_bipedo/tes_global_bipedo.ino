#include <Servo.h>

#include<Wire.h>
#include<MPU6050.h>

#define DIR_PIN_I 7
#define STEP_PIN_I 6

#define DIR_PIN_D 10
#define STEP_PIN_D 9

MPU6050 mpu;

double accelX = 0, accelY = 0, accelZ = 0;

double gyroX = 0, gyroY = 0, gyroZ = 0;

unsigned long lastTime = 0, sampleTime = 100;

Servo servoMotor;

int LED = 13;
char estado;

void setup() {

     pinMode(LED, OUTPUT);
     Serial.begin(9600);
     servoMotor.attach(3);

     pinMode(DIR_PIN_I, OUTPUT); 
     pinMode(STEP_PIN_I, OUTPUT);
     pinMode(DIR_PIN_D, OUTPUT); 
     pinMode(STEP_PIN_D, OUTPUT);

     while (!mpu.begin(MPU6050_SCALE_2000DPS,MPU6050_RANGE_2G))
  {
     delay(500);
  }

}

void giroscopio(){
  if ( millis()-lastTime>=sampleTime)
  {
    lastTime = millis();

    Vector normAccel = mpu.readNormalizeAccel();
    Vector normGyro = mpu.readNormalizeGyro();

    accelX = normAccel.XAxis;
    accelY = normAccel.YAxis;
    accelZ = normAccel.ZAxis;
    gyroX = normGyro.XAxis;
    gyroY = normGyro.YAxis;
    gyroZ = normGyro.ZAxis;

    Serial.println(accelX);
    Serial.println(accelY);
    Serial.println(accelZ);
    Serial.println(gyroX);
    Serial.println(gyroY);
    Serial.println(gyroZ);   
   }  
}

void Myoware(){
    int sensorValue = analogRead(A0);
    Serial.println(sensorValue);
    delay(1);
  
  }

  void rotate(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN_I,dir);
  digitalWrite(DIR_PIN_D,dir); 

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN_I, HIGH);
    digitalWrite(STEP_PIN_D, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN_I, LOW);
    digitalWrite(STEP_PIN_D, LOW); 
    delayMicroseconds(usDelay); 
  } 
} 

void rotateDeg(float deg, float speed){ 
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0)? HIGH:LOW;
  digitalWrite(DIR_PIN_I,dir);
  digitalWrite(DIR_PIN_D,dir); 

  int steps = abs(deg)*(1/0.225);
  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN_I, HIGH);
    digitalWrite(STEP_PIN_D, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN_I, LOW);
    digitalWrite(STEP_PIN_D, LOW);
    delayMicroseconds(usDelay); 
  } 
}


void loop() {

    Myoware();
    giroscopio(); 

    while(Serial.available()>0){
    estado=Serial.read();

    switch (estado){
      
      case '1':
        servoMotor.write(0);
        delay(1000);
        servoMotor.write(90);
        delay(1000);
        break;

      case '2':
        break;
      
      case '3':
        rotateDeg(360, 25); 
        delay(1000);
        break;
      
     case '4':
        rotateDeg(-360, .25);  //reverse
        delay(1000);
        break;
      
      case '5':
      digitalWrite(LED, HIGH);
      break;   
      
      case '6':
      digitalWrite(LED, LOW);
      break;

}


      
    

    
 
     }
     }

     
