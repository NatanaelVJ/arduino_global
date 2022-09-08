#include <PS2X_lib.h>
#define DIR_PIN 8
#define STEP_PIN 9



PS2X ps2x;

int error = 0;
byte vibrate = 0;
int var, aux = 0;
int blue,red =0;

void setup() {    
      
  pinMode(DIR_PIN, OUTPUT); 
  pinMode(STEP_PIN, OUTPUT); 

  Serial.begin(9600);
  error = ps2x.config_gamepad(13,11,10,12, true, true);  //(clock, command, attention, data. para los True = sensor de presion y  vibracion)

  if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }  
}

 

 void motorB(){

    
           
    digitalWrite(8, HIGH);
    
 }
   
void botones(){  
  if(ps2x.Button(PSB_PAD_UP))
  {
    Serial.println("Presionaste arriba: ");
    var = 0; 
  }

  if(ps2x.Button(PSB_PAD_DOWN))
  {
    Serial.println("Presionaste abajo: ");
    
  }


  if(ps2x.Button(PSB_BLUE))
  {
    Serial.println("Presionaste Blue: ");
    var = 1; 
  
    
    
       
 }
  
  /*if(ps2x.Button(PSB_RED))
  {
    
   Serial.println("Presionaste RED: ");


   
  }*/

  if(ps2x.Button(PSB_TRIANGLE))
  {
    
   Serial.println("Presionaste TRI: ");
   var = 2; 
  
   
  }
 delay(50);
}

void motor(){
    

  
   digitalWrite(9, HIGH);
   for(int x= 0; x<100; x++)        
   digitalWrite(9, LOW);
   for(int i= 0; i<100; i++);
 }

void rotateDeg(float deg, float speed){ 
  //rotate a specific number of degrees (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (deg > 0)? HIGH:LOW;
  digitalWrite(DIR_PIN,dir); 

  int steps = abs(deg)*(1/0.225);
  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(usDelay); 
  } }


void rotate(int steps, float speed){ 
  //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
  //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
  int dir = (steps > 0)? HIGH:LOW;
  steps = abs(steps);

  digitalWrite(DIR_PIN,dir); 

  float usDelay = (1/speed) * 70;

  for(int i=0; i < steps; i++){ 
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(usDelay); 

    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(usDelay); 
  } }
    
void loop() {
 
  ps2x.read_gamepad(false,vibrate);
  
  
  vibrate = ps2x.Analog(PSAB_BLUE);

  botones();
  
 
    

   switch(var){
    case 1: 
    rotate(-35000, 1);
    delay(1000);
    rotate(35000, 1);
    delay(3000); break;
    case 2:
    rotate(-2000, 0.1); break;
    }}

  




       
