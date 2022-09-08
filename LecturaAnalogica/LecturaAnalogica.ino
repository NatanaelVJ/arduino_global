#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°


int PelvisIzquierda1 = 4;
int PelvisIzquierda2 = 8;
int PelvisDerecha1 = 0;
int PelvisDerecha2 = 12;

int FemurIzquierda1 = 5;
int FemurIzquierda2 = 9;
int FemurDerecha1 = 1;
int FemurDerecha2 = 13;

int TibiaIzquierda1 = 6;
int TibiaIzquierda2 = 10;
int TibiaDerecha1 = 2;
int TibiaDerecha2 = 14;

//calibracion posicion inicial

//Derecha1
int  caliD_Pe1 = 140  ;
int caliD_Fe1 = 60;
int caliD_Ti1 = 60; 

//Derecha2
int  caliD_Pe2 =  40;
int caliD_Fe2 = 60;
int caliD_Ti2 = 60;

//Izquierda1
int  caliI_Pe1 = 60  ;
int caliI_Fe1 = 120;
int caliI_Ti1 = 140; 

//Izquierda2
int  caliI_Pe2 =  140;
int caliI_Fe2 = 120;
int caliI_Ti2 = 120;

void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  inicio();
  delay(1000);




}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  

}

void inicio(){

    //Izquierda1  ( Pelvis - Femur - Tibia ) (subir + , disminuir - )     
    setServo(PelvisIzquierda1,caliI_Pe1);  
    setServo(FemurIzquierda1,caliI_Fe1);  
    setServo(TibiaIzquierda1,caliI_Ti1);

   
    //Izquierda2    
    setServo(PelvisIzquierda2,caliI_Pe2); 
    setServo(FemurIzquierda2,caliI_Fe2);
    setServo(TibiaIzquierda2,caliI_Ti2);
    
    //Derecha1
    setServo(PelvisDerecha1,caliD_Pe1);
    setServo(FemurDerecha1,caliD_Fe1); 
    setServo(TibiaDerecha1,caliD_Ti1);  

    //Derecha2    
    setServo(PelvisDerecha2,caliD_Pe2);
    setServo(FemurDerecha2,caliD_Fe2);
    setServo(TibiaDerecha2,caliD_Ti2);
     
    delay (50);

  }


void intermedio(){

    //Izquierda1  ( Pelvis - Femur - Tibia ) (subir + , disminuir - )     
    
    for(int ang=0; ang<=30; ang++){
    setServo(PelvisIzquierda1,caliI_Pe1 + ang);  
    setServo(FemurIzquierda1,caliI_Fe1);  
    setServo(TibiaIzquierda1,caliI_Ti1);

   
    //Izquierda2    
    setServo(PelvisIzquierda2,caliI_Pe2 + ang); 
    setServo(FemurIzquierda2,caliI_Fe2);
    setServo(TibiaIzquierda2,caliI_Ti2);
    
    //Derecha1
    setServo(PelvisDerecha1,caliD_Pe1 - ang);
    setServo(FemurDerecha1,caliD_Fe1); 
    setServo(TibiaDerecha1,caliD_Ti1);  

    //Derecha2    
    setServo(PelvisDerecha2,caliD_Pe2 - ang);
    setServo(FemurDerecha2,caliD_Fe2);
    setServo(TibiaDerecha2,caliD_Ti2);

    }
delay(500);    
  }

void paso1 (){

    //Derecha1
    
    for( int ang=0; ang<=60; ang++){
    setServo(PelvisDerecha1, caliD_Pe1 + ang); 
    setServo(FemurDerecha1,caliD_Fe1 - ang);  
    setServo(TibiaDerecha1, caliD_Ti1 - ang);    
    } int aux = caliD_Fe1 - 60; int aux1 =  caliD_Ti1 - 60;

    for( int ang=0; ang<=60; ang++){
    setServo(TibiaDerecha1, (aux )+ ang); 
    setServo(FemurDerecha1,(aux1) + ang);   
  }
 delay(500); //varia la velocidad del movimiento 
}

void paso2 (){

    //Izquierda2      
    for (int ang=0; ang<=60; ang++){      
    setServo(PelvisIzquierda2,caliI_Pe2 - ang ); 
    setServo(FemurIzquierda2,caliI_Fe2 + ang );
    setServo(TibiaIzquierda2,caliI_Ti2 + ang);
    }int aux =  caliI_Fe2 + 60; int aux1 =  caliI_Ti2 + 60;
    for (int ang=0; ang<=60; ang++){
    setServo(FemurIzquierda2,aux - ang );
    setServo(TibiaIzquierda2,aux1 - ang);
    }
   delay(500); 
  }

void paso3 (){

    //Izquierda1      
    for (int ang=0; ang<=60; ang++){    
    setServo(PelvisIzquierda1,caliI_Pe1 - ang );  
    setServo(FemurIzquierda1,caliI_Fe1 + ang );  
    setServo(TibiaIzquierda1,caliI_Ti1 + ang );
    }int aux =  caliI_Fe1 + 60; int aux1 =  caliI_Ti1 + 60;
    for (int ang=0; ang<=60; ang++){
    setServo(FemurIzquierda1,aux - ang );  
    setServo(TibiaIzquierda1,aux1 - ang );
     }
    delay(500); 
  }

  void paso4 (){
  
    //Derecha2  
    for (int ang=0; ang<=60; ang++){
    setServo(PelvisDerecha2,caliD_Pe2 + ang);
    setServo(FemurDerecha2,caliD_Fe2 - ang);
    setServo(TibiaDerecha2,caliD_Ti2 - ang);
    }int aux =  caliD_Fe2 - 60; int aux1 =  caliD_Ti2 - 60;
    for (int ang=0; ang<=60; ang++){
    setServo(FemurDerecha2,aux + ang);
    setServo(TibiaDerecha2,aux1 + ang);     
    }   
    delay(500);
  }
    
void loop() {
    

    //inicio();
    //delay(500);
    paso4();
    delay(50);
    paso1();
    delay(50);
    intermedio();
    delay(50);
    paso2();
    delay(50);
    paso3();
    delay(50);
    intermedio();
    /*delay(50);        
    paso1();
    delay(250);
    intermedio();
    delay(250);
    paso2();
    delay(250);
    paso3();
    delay(250);
    intermedio();
    delay(250);
*/
}
