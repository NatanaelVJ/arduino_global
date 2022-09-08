int estado=0;
int retardo=100;
int analogo=0;


void setup(){
    pinMode(11,OUTPUT);
  pinMode(10,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(8,OUTPUT);
    Serial.begin(9600);
}

void loop(){

  
if(Serial.available()>0){           //Si el puerto serie esta habilitadp 
        estado = Serial.read();       //Lee lo que llega por el puerto Serie
        
  }
{     
  if(estado== '1' ){
       digitalWrite(11,HIGH);
       digitalWrite(8,HIGH);
 } 
   }
 if(estado== '2' ){
       digitalWrite(11,HIGH);
       digitalWrite(8,HIGH);
 }
 if(estado== '3'){ 
       digitalWrite(11,HIGH);
       digitalWrite(10,HIGH);
 }
 if(estado== '4' ){
       digitalWrite(9,HIGH);
       digitalWrite(8,HIGH);
 }
 if(estado== '5' ){
       digitalWrite(11,LOW);
       digitalWrite(10,LOW);
       digitalWrite(9,LOW);
       digitalWrite(8,LOW);
 }
}
 
