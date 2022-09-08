#include<Wire.h>
#include<MPU6050.h>

MPU6050 mpu;

double accelX = 0, accelY = 0, accelZ = 0;

double gyroX = 0, gyroY = 0, gyroZ = 0;

unsigned long lastTime = 0, sampleTime = 100;

  

void setup() {

  Serial.begin(9600);

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


void loop() {

  Myoware();
  giroscopio();
  
}
