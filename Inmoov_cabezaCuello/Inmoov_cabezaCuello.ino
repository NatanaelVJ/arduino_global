
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°

//calibracion


int pistonCentro = 0;
int pistonDer = 1;
int pistonIz = 2;

int pistonCentro_pos = 90; //AUMENTA SUBE
int pistonDer_pos =80; //si se DISMINUYE el angulo sube 
int pistonIz_pos = 90; //si se aumenta el anguo baja 


int hombroIz = 8;
int hombroIz_pos=30;

int ojos = 5; //boca

int ojosB = 6;


int i=0;




void setup() {
  
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  inicio();
  delay(3000);
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}
 
void loop() {
 int temp = 250;
 
 abajo();
 delay(5000);
 inicio();
 delay(300000);

 

} 

void inicio()

{

setServo(pistonCentro,pistonCentro_pos);
setServo(pistonDer,pistonDer_pos);
setServo(pistonIz,pistonIz_pos);

}

void ojosA()

{

setServo(ojos,150);
delay(250);
setServo(ojos,0);
delay(250);
}

void ojosBB (){
  
setServo(ojosB,160);
delay(250);
setServo(ojosB,30);
delay(250);
 
  }



void lateralDerecha()
{

int angulo_correccion = 70; 
  
setServo(pistonCentro,pistonCentro_pos + angulo_correccion);
setServo(pistonDer,pistonDer_pos + angulo_correccion);
setServo(pistonIz,pistonIz_pos - angulo_correccion);
  
  }

void lateralIzquierda()
{

int angulo_correccion = 70; 
  
setServo(pistonCentro,pistonCentro_pos + angulo_correccion);
setServo(pistonDer,pistonDer_pos - angulo_correccion+40);
setServo(pistonIz,pistonIz_pos + angulo_correccion);
  
  }        
    
void superiorIzquierda()
{

int angulo_correccion = 50; 
  
setServo(pistonCentro,pistonCentro_pos - angulo_correccion);
setServo(pistonDer,pistonDer_pos - angulo_correccion);
setServo(pistonIz,pistonIz_pos + angulo_correccion);
  
 }

void superiorDerecha()
{

int angulo_correccion = 50; 
  
setServo(pistonCentro,pistonCentro_pos - angulo_correccion);
setServo(pistonDer,pistonDer_pos + angulo_correccion);
setServo(pistonIz,pistonIz_pos - angulo_correccion);
  
 } 

void arriba()

{

int angulo_correccion = 70; 
int angulo_correccion2 = 40;
  
setServo(pistonCentro,pistonCentro_pos - angulo_correccion);
setServo(pistonDer,pistonDer_pos + (angulo_correccion2-30) );
setServo(pistonIz,pistonIz_pos + angulo_correccion2);
  
 }

void abajo()

{

int angulo_correccion = 90; 
int angulo_correccion2 = 40;
  
setServo(pistonCentro,pistonCentro_pos + angulo_correccion);
setServo(pistonDer,pistonDer_pos - angulo_correccion2 );
setServo(pistonIz,pistonIz_pos - angulo_correccion2);
  
 }

void hombroIzq()
{
  setServo(hombroIz,hombroIz_pos); 
  }
           
   
