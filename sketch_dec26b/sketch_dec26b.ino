
#include <PS2X_lib.h>  //for v1.6

PS2X ps2x; // create PS2 Controller Class

//right now, the library does NOT support hot pluggable controllers, meaning 
//you must always either restart your Arduino after you conect the controller, 
//or call config_gamepad(pins) again after connecting the controller.
int error = 0; 
byte type = 0;
byte vibrate = 0;


int in1 = 9;  // Pin que controla el sentido de giro Motor A
int in2 = 8;  // Pin que controla el sentido de giro Motor A
int inB1 = 7;  // Pin que controla el sentido de giro Motor A
int inB2 = 6;  // Pin que controla el sentido de giro Motor A

int estado = 'c';
 
void setup ()
{
 Serial.begin(9600); 
  error = ps2x.config_gamepad(13,11,10,12, true, true); //GamePad(clock, command, attention)
   
    if(error == 0)
  {
    Serial.println("Controlador encontrado y configurado");
  }
  else
  {
    Serial.println("Error, mando no encontrado");
  }
  
  
  pinMode(in1, OUTPUT);    // Configura  los pines como salida
  pinMode(in2, OUTPUT);
    
    
  pinMode(inB1, OUTPUT);    // Configura  los pines como salida
  pinMode(inB2, OUTPUT);
}
void loop()
{

   //if(Serial.available()>0){        // lee el bluetooth y almacena en estado
    //estado = Serial.read();
  //}
  
  int temp;
  ps2x.read_gamepad(false,vibrate);
  
  
  
  if(ps2x.Button(PSB_START)){           // Boton desplazar al Frente
  Serial.println("Controller refusing to enter Pressures mode, may not support it. ");      
 
  digitalWrite(in1, HIGH);  // GIRO DERECHA
  digitalWrite(in2, LOW);
  digitalWrite(inB1, HIGH);  // GIRO DERECHA
  digitalWrite(inB2, LOW);
 } 
  if(ps2x.Button(PSB_PAD_UP)){           //Reversa
        
 
  digitalWrite(in1, LOW);  
  digitalWrite(in2, HIGH);
  digitalWrite(inB1, LOW); 
  digitalWrite(inB2, HIGH);

 
  }

  if(estado=='c'){         // Boton Parar

  digitalWrite(in1, LOW);  // PARA
  digitalWrite(in2, LOW);
  digitalWrite(inB1, LOW);  // PARA
  digitalWrite(inB2, LOW);
 
   } 

  if(estado=='b'){         // Boton Parar

  digitalWrite(in1, HIGH);  // PARA
  digitalWrite(in2, LOW);
  digitalWrite(inB1, LOW);  // PARA
  digitalWrite(inB2, HIGH
  );
 
   } 
  if(estado=='d'){         // Boton Parar

  digitalWrite(in1, LOW);  // PARA
  digitalWrite(in2, HIGH);
  digitalWrite(inB1, HIGH);  // PARA
  digitalWrite(inB2, LOW);
 
   } 

}
