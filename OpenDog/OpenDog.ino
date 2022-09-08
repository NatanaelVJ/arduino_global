#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver(0x40);

unsigned int pos0=172; // ancho de pulso en cuentas para pocicion 0°
unsigned int pos180=565; // ancho de pulso en cuentas para la pocicion 180°


//**************************************MAPEO GDL***************************

int PED1 = 0;
int FD1 = 1;
int TD1 = 2;

int PI1 = 4;
int FI1 = 5;
int TI1 = 6; 

int PED2 = 9;
int FD2 = 10;
int TD2 = 11;

int PI2 = 12;
int FI2 = 13;
int TI2 = 14;

//**************************************Calibracion***************************
int a = 10;
int b = 0;
int PED1_pos = 90 + b;
int FD1_pos = 100 + a;
int TD1_pos = 90 - a;

int PED2_pos = 100 - b;
int FD2_pos = 110 + a;
int TD2_pos = 70 - a;

int PI1_pos = 110 -b;
int FI1_pos = 80 - a;
int TI1_pos = 90 + a;

int PI2_pos = 100 +b;
int FI2_pos = 70 - a;
int TI2_pos = 95 + a;
 


void setup() {
  servos.begin();  
  servos.setPWMFreq(60); //Frecuecia PWM de 60Hz o T=16,66ms
  inicio();
}

void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);  
  
}

  
  

void inicio(){

         
    setServo(PED1, PED1_pos);
    setServo(FD1, FD1_pos);
    setServo(TD1, TD1_pos); 

    setServo(PI1, PI1_pos);
    setServo(FI1, FI1_pos);
    setServo(TI1, TI1_pos);
    
    delay(500);
    
    setServo(PED2, PED2_pos);
    setServo(FD2, FD2_pos);
    setServo(TD2, TD2_pos);
     
    setServo(PI2, PI2_pos);
    setServo(FI2, FI2_pos);
    setServo(TI2, TI2_pos);
    
}

void abajo(){

    int angulo = 20;
    int j = angulo;
    

    //for( int j = 0; j= angulo; j++){   
    setServo(PED2, PED2_pos);
    setServo(FD2, FD2_pos - j);
    setServo(TD2, TD2_pos + j);

    setServo(PI2, PI2_pos);
    setServo(FI2, FI2_pos + j);
    setServo(TI2, TI2_pos - j);

    delay(500);
        
    setServo(PED1, PED1_pos);
    setServo(FD1, FD1_pos - j);
    setServo(TD1, TD1_pos + j);

    setServo(PI1, PI1_pos);
    setServo(FI1, FI1_pos + j);
    setServo(TI1, TI1_pos - j);
  
    //} 
    
    }

void caminar(){

    int angulo = 50;
    int j = angulo;
    int tem = 200;
    int tem2 = 400;

     
    setServo(PED1, PED1_pos);
    setServo(FD1, FD1_pos -j);
    setServo(TD1, TD1_pos -j);

/*
    setServo(PI2, PI2_pos);
    setServo(FI2, FI2_pos + j );
    setServo(TI2, TI2_pos + j);
    
    delay(tem);    
    setServo(TD1, TD1_pos +(j+j));
    setServo(TI2, TI2_pos -(j+j));
    
    delay(tem2);   
    setServo(FD1, FD1_pos +j);
    setServo(TD1, TD1_pos -j);

    setServo(FI2, FI2_pos -j );
    setServo(TI2, TI2_pos +j);
    
    delay(tem2);
    setServo(FD1, FD1_pos);
    setServo(TD1, TD1_pos);

    setServo(FI2, FI2_pos);
    setServo(TI2, TI2_pos);

    
   //Espejo

      
    setServo(PED2, PED2_pos);
    setServo(FD2, FD2_pos -j);
    setServo(TD2, TD2_pos -j);
       
    setServo(PI1, PI1_pos);
    setServo(FI1, FI1_pos +j);
    setServo(TI1, TI1_pos +j);

    delay(tem);
    setServo(TD2, TD2_pos +(j+j));
    setServo(TI1, TI1_pos -(j+j));

    delay(tem2);     
    setServo(FD2, FD2_pos +j);
    setServo(TD2, TD2_pos -j);

    setServo(FI1, FI1_pos -j);
    setServo(TI1, TI1_pos +j);

    delay(tem2);
    setServo(FD2, FD2_pos);
    setServo(TD2, TD2_pos);
       
    
    setServo(FI1, FI1_pos);
    setServo(TI1, TI1_pos);
  */  
  }    

  void caminar2(){

    int angulo = 20;
    int j = angulo;
    int tem = 150;
    int tem2 = 250;

     
    setServo(PED1, PED1_pos);
    setServo(FD1, FD1_pos -j);
    setServo(TD1, TD1_pos -j*2);

    setServo(PI2, PI2_pos);
    setServo(FI2, FI2_pos + j );
    setServo(TI2, TI2_pos + j*2);
  
    delay(tem);    
    setServo(TD1, TD1_pos +(j+j)*2);
    setServo(TI2, TI2_pos -(j+j)*2);
    
    delay(tem2);   
    setServo(FD1, FD1_pos +j);
    setServo(TD1, TD1_pos -j*2);

    setServo(FI2, FI2_pos -j );
    setServo(TI2, TI2_pos +j*2);
   
    delay(tem2);
    setServo(FD1, FD1_pos);
    setServo(TD1, TD1_pos);

    setServo(FI2, FI2_pos);
    setServo(TI2, TI2_pos);

    
   //Espejo

      
    setServo(PED2, PED2_pos);
    setServo(FD2, FD2_pos -j);
    setServo(TD2, TD2_pos -j*2);
       
    setServo(PI1, PI1_pos);
    setServo(FI1, FI1_pos +j);
    setServo(TI1, TI1_pos +j*2);

    delay(tem);
    setServo(TD2, TD2_pos +(j+j));
    setServo(TI1, TI1_pos -(j+j)*2);

    delay(tem2);     
    setServo(FD2, FD2_pos +j);
    setServo(TD2, TD2_pos -j*2);

    setServo(FI1, FI1_pos -j);
    setServo(TI1, TI1_pos +j*2);

    delay(tem2);
    setServo(FD2, FD2_pos);
    setServo(TD2, TD2_pos);
       
    
    setServo(FI1, FI1_pos);
    setServo(TI1, TI1_pos);
   
  }    




void loop() {

    caminar2();
    delay(150);
   
   
 
}
