#include <PS2X_lib.h>
#include<Servo.h>

Servo Servo_X;
Servo Servo_Y;
PS2X ps2x;


int error = 0;
byte vibrate = 0;
int ServoX;
int ServoY;

int LED = 13;
int in1 = 8;  // Pin que controla el sentido de giro Motor A
int in2 = 9;  // Pin que controla el sentido de giro Motor A
int inB1 = 10;  // Pin que controla el sentido de giro Motor A
int inB2 = 11;  // Pin que controla el sentido de giro Motor A

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(in1, OUTPUT);    // Configura  los pines como salida
  pinMode(in2, OUTPUT);
        
  pinMode(inB1, OUTPUT);    // Configura  los pines como salida
  pinMode(inB2, OUTPUT);

  Servo_X.attach(3);
  Servo_Y.attach(4);
  
  Serial.begin(9600);
  error = ps2x.config_gamepad(07,12,A0,13, true, true);  //(clock, command, attention, data. para los True = sensor de presion y  vibracion)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
}

void loop() 
{
   int temp; 
   inicio();
   camara();


  




    if(ps2x.Button(PSB_PAD_UP))
  {
   
    
    temp = ps2x.Analog(PSAB_PAD_UP);
    Serial.print("Presionaste arriba: ");
    Serial.println(temp);
    digitalWrite(LED, LOW);

    digitalWrite(in1, HIGH);  
    digitalWrite(in2, LOW);
    digitalWrite(inB1, HIGH);  
    digitalWrite(inB2, LOW);
    }
  
  
  else if(ps2x.Button(PSB_PAD_DOWN))
  {
    temp = ps2x.Analog(PSAB_PAD_DOWN);
    Serial.print("Presionaste abajo: ");
    Serial.println(temp);
    
    digitalWrite(in1, LOW); 
    digitalWrite(in2, HIGH);
    digitalWrite(inB1, LOW);  
    digitalWrite(inB2, HIGH);

  } 
 
  else if(ps2x.Button(PSB_PAD_RIGHT))
  {
    temp = ps2x.Analog(PSAB_PAD_RIGHT);
    Serial.println("Presionaste izquierda: ");
    Serial.print(temp);
  
    digitalWrite(in1, HIGH);  // GIRO DERECHA
    digitalWrite(in2, LOW);
    digitalWrite(inB1, LOW);  // GIRO DERECHA
    digitalWrite(inB2, HIGH);
  }

  else if(ps2x.Button(PSB_PAD_LEFT))
  {
    temp = ps2x.Analog(PSAB_PAD_LEFT);
    Serial.println("Presionaste derecha: ");
    Serial.print(temp);
    
    digitalWrite(in1, LOW);  // GIRO DERECHA
    digitalWrite(in2, HIGH);
    digitalWrite(inB1, HIGH);  // GIRO DERECHA
    digitalWrite(inB2, LOW);
  
  }


///////////////////////////////////////////////////////////////////////

  else if(! ps2x.Button(PSB_PAD_DOWN) && ! ps2x.Button(PSB_PAD_UP) && ! ps2x.Button(PSB_PAD_LEFT) && ! ps2x.Button(PSB_PAD_RIGHT)){
    
   
    digitalWrite(in1, LOW);  
    digitalWrite(in2, LOW);
    digitalWrite(inB1, LOW);  
    digitalWrite(inB2, LOW);
  
  }
//////////////////////////////////////////////////////////////////////

  delay(50);
}

void inicio()
{
    digitalWrite(in1, LOW);  
    digitalWrite(in2, LOW);
    digitalWrite(inB1, LOW);  
    digitalWrite(inB2, LOW);
  }
  
void camara()
{
   int Ry;
   int Rx;
    

   ps2x.read_gamepad(false, vibrate);
   vibrate = ps2x.Analog(PSAB_BLUE);
  
   Ry = ps2x.Analog(PSS_RY), DEC;
   Rx = ps2x.Analog(PSS_RX), DEC;


   ServoX = map(Rx, 0, 255, 0, 180);
   ServoY = map(Ry, 0, 255, 0, 180);
    
   Servo_Y.write(ServoY);
   Servo_X.write(ServoX);
      
   Serial.print("RY =");
   Serial.println(Ry);
   Serial.print("Rx =");
   Serial.println(Rx);
   delay(50);
  }
    
  









/*
  if(ps2x.Button(PSB_BLUE))
  {
    Serial.println("Presionaste X: ");
  }
  if(ps2x.Button(PSB_PINK))
  {
    Serial.println("Presionaste cuadrado: ");
  }
  if(ps2x.Button(PSB_RED))
  {
    Serial.println("Presionaste redondo: ");
  }
  if(ps2x.Button(PSB_GREEN))
  {
    Serial.println("Presionaste triangulo: ");
  }
  if(ps2x.Button(PSB_L1))
  {
    Serial.println("Presionaste L1: ");
  }
  if(ps2x.Button(PSB_L2))
  {
    Serial.println("Presionaste L2: ");
  }
  if(ps2x.Button(PSB_R1))
  {
    Serial.println("Presionaste R1: ");
  }
  if(ps2x.Button(PSB_R2))
  {
    Serial.println("Presionaste R2: ");
  }

  
  if(ps2x.Button(PSB_SELECT))
  {
    Serial.println("Presionaste seleccionar: ");
  }
 
 

  
  delay(50);
}*/
