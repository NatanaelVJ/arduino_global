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

////Variables Para Servo Motores

int Pulgar = 0;
int Indice = 1;
int Dedos = 2;
int Muneca = 3;
int Hombro = 8;


int po1;
int VAR, VAR1, VAR2;
int bluetooth;

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
}


void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}



void ServosInicio()
{
    setServo(Pulgar,180);
    setServo(Dedos,150);
    setServo(Indice,180);
    setServo(Muneca,90);
    setServo(Hombro,0);
}

void ManoClosed()
{
    setServo(Pulgar,0);
    setServo(Dedos,0);
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
    setServo(Hombro,150);    
}


void Lec()
{
    int pot1 = analogRead(A8);
    int pot2 = analogRead(A10);
    int pot3 = analogRead(A12);
    int po1=map(pot1, 0, 1023, 0, 15);
    int po2=map(pot2, 0, 1023, 0, 15);
    int po3=map(pot3, 0, 1023, 0, 15);

    Serial.println(po1);
    Serial.println(po2);
    Serial.println(po3);
       
    delay(50);

    VAR = po1;
    VAR1 = po2;
    VAR2 = po3; 
    return VAR;
    return VAR1;
    return VAR2;
    } 
    
void loop (){

Lec();
delay(10);

/* El Programa Inicia Una Vez que se incie la comunicacion con el Maestro */ 

if(Serial1.available()>0){
bluetooth =Serial1.read();
}

/*Se Guarda La Variable*/
char posicion = bluetooth;



/* Codo - Flexion*/ 
if (posicion=='A' && VAR>=5){
digitalWrite(EN, LOW); 
step(false, X_DIR, X_STP, 600);
digitalWrite(EN, HIGH);

} 

/*Codo - Extension*/ 
else if (posicion=='B'&& VAR<=12){
digitalWrite(EN, LOW);
step(true, X_DIR, X_STP, 600);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Supinacion*/ 
else if (posicion=='C'&& VAR1<=13){
digitalWrite(EN, LOW);
step(false, Y_DIR, Y_STP, 750);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Pronacion*/
else if (posicion=='D'&& VAR1<=6 ) {
digitalWrite(EN, LOW);
step(true, Y_DIR, Y_STP, 500);  
digitalWrite(EN, HIGH); 
}

/////////////////////////////////////////////////////////
else if (posicion!='C'&& posicion!='D' && VAR1>=13 ) {
digitalWrite(EN, LOW);
step(true, Y_DIR, Y_STP, 500);  
digitalWrite(EN, HIGH); 
}

else if (posicion!='D'&& posicion!='C' && VAR1<=6 ) {
digitalWrite(EN, LOW);
step(false, Y_DIR, Y_STP, 500);  
digitalWrite(EN, HIGH); 
}
/////////////////////////////////////////////////////////

/*BRAZO - Flexion Vertical*/
else if (posicion=='E'&& VAR2<=6 ) {
digitalWrite(EN, LOW);
step(false, Z_DIR, Z_STP, 500);  
digitalWrite(EN, HIGH); 
}

/*BRAZO - Extension*/
else if (posicion=='F'&& VAR2<=6 ) {
digitalWrite(EN, LOW);
step(true, Z_DIR, Z_STP, 500);  
digitalWrite(EN, HIGH); 
}

/*Mano - Cerrada*/
else if (posicion=='G') {
   ManoClosed();
}

/*Muñeca - Supino*/
else if (posicion=='H') {
   ManoClosed();
}

/*Muñeca - Prono*/
else if (posicion=='I') {
   ManoClosed();
}


digitalWrite(EN, HIGH); 
}
