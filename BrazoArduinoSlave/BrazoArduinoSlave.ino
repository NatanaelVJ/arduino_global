
#include <Adafruit_PWMServoDriver.h> 
#include <SoftwareSerial.h>


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

////Variables Para Servo Motores

int Pulgar = 0;
int Indice = 1;
int Dedos = 2;
int Muneca = 3;
int Hombro = 8;


/* Variables para los potenciometros y Monitor Serial */

char posicion, bt;
int VAR, VAR1, VAR2;
int bluetooth;
int count,count1 = 0;

/*Funcion Control Motores PAP*/
void step(boolean dir, byte dirPin, byte stepperPin, int steps)
{
  digitalWrite(dirPin, dir);
  
  count1++;
  delay(5);
  if (count1 = 100 ){
  
  for (int i = 0; i < steps; i++) {
    digitalWrite(stepperPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(stepperPin, LOW);
    delayMicroseconds(800);
  count1=0;
  }
  }
}


void setup (){

  Serial.begin(9600);
  Serial1.begin(9600);
  
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  

  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
//  AutoHome();
}

/*Funcion Control Servos*/

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}

void ServosInicio()
{
    setServo(Pulgar,180);
    setServo(Dedos,0);
    setServo(Indice,180);
    setServo(Muneca,90);
    setServo(Hombro,40);
}

void ManoInicio()
{
    setServo(Pulgar,180);
    setServo(Dedos,0);
    setServo(Indice,180);
    setServo(Muneca,90); 
}

void ManoClosed()
{
    setServo(Pulgar,0);
    setServo(Dedos,180);
    setServo(Indice,0);
   
}

void MunecaInicio()
{
    setServo(Muneca,90);    
}

void MunecaSupino()
{
    setServo(Muneca,0);    
}

void MunecaProno()
{
    setServo(Muneca,180);    
}

void HombroAbduccion()
{
    setServo(Hombro,120);    
}

void HombroInicio()
{
    setServo(Hombro,0);    
}




void Lec()
{  
    int pot1 = analogRead(A8);
    int pot2 = analogRead(A10);
    int pot3 = analogRead(A12);
    int po1=map(pot1, 0, 1023, 0, 15);
    int po2=map(pot2, 0, 1023, 0, 15);
    int po3=map(pot3, 0, 1023, 0, 15);
    
    //Serial.println(po1);
    //Serial.println(po2);
    //Serial.println(po3);
     
    VAR = po1;
    VAR1 = po2;
    VAR2 = po3; 
    return VAR;
    return VAR1;
    return VAR2;
} 

void AutoHome()
{
  ///////////////////////AUTO HOME CODO (14 ES LA POSICION DE INICIO)////////////////////////  
    if (VAR<=13){
    digitalWrite(EN, LOW); 
    step(true, X_DIR, X_STP, 200);
    digitalWrite(EN, HIGH);
    } 
  ///////////////////////AUTO HOME (7 ES LA POSICION DE INICIO)///////////////////////////                                                                                                                                                                                                                                                                                                                        INICIO)////////////////////////  
    if (VAR2<=6 ) {
    digitalWrite(EN, LOW);
    step(false, Y_DIR, Y_STP, 200);  
    digitalWrite(EN, HIGH); 
}

    if (VAR2>=8 ) {
    digitalWrite(EN, LOW);
    step(true, Y_DIR, Y_STP, 200);  
    digitalWrite(EN, HIGH); 
}

 
  ///////////////////////AUTO HOME (12 ES LA POSICION DE INICIO)///////////////////////////  
   
    else if (VAR1<=11 ) {
    digitalWrite(EN, LOW);
    step(true, Z_DIR, Z_STP, 200);  
    digitalWrite(EN, HIGH); 
}
    ManoInicio();
    
  }

void loop (){
Lec();

/* El Programa Inicia Una Vez que se incie la comunicacion con el Maestro */ 

while(Serial1.available()>0){
posicion =Serial1.read();

}

/* Codo - Flexion*/ 
if (posicion=='A' && VAR>=7){
digitalWrite(EN, LOW); 
step(false, X_DIR, X_STP, 100);
digitalWrite(EN, HIGH);
} 

/*Codo - Extension*/ 
else if (posicion=='B'&& VAR<=13){
digitalWrite(EN, LOW);
step(true, X_DIR, X_STP, 100);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Pronacion*/
else if (posicion=='C'&& VAR2>=3 ) {
digitalWrite(EN, LOW);
step(true, Y_DIR, Y_STP, 100);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Supinacion*/ 
else if (posicion=='D'&& VAR2<=10){
digitalWrite(EN, LOW);
step(false, Y_DIR, Y_STP, 100);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Flexion Vertical*/
else if (posicion=='E'&& VAR1>=1 ) {
digitalWrite(EN, LOW);
step(false, Z_DIR, Z_STP, 100);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Extension*/
else if (posicion=='F'&& VAR1<=11 ) {
digitalWrite(EN, LOW);
step(true, Z_DIR, Z_STP, 100);  
digitalWrite(EN, HIGH); 
}

/*AUTO-HOME*/
else if (posicion=='Z'){
  AutoHome();
  }

else {
digitalWrite(EN, HIGH); 
}


switch (posicion){ 

  case 'G':
  ManoClosed();
  break;
  

  case 'H':
  MunecaSupino();
  break;

  case 'I':
  MunecaProno();
  break;

  case 'P':
  HombroAbduccion();
  break;

  case 'Z':
  ServosInicio();
  delay(500);
  break;
   
}

}  
