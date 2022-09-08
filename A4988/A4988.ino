#define STEP 4
#define DIR 5 

int num;
String mensaje1="Ingrese un numero: ";
String mensaje2="Numero Ingresado: ";
int pot =A0;
int po,parar;

void setup() {

Serial.begin(9600);
pinMode(STEP, OUTPUT);
pinMode(DIR, OUTPUT);
pinMode(pot, INPUT);

}

void Lec(){
    
    int valor = analogRead(A0);
    int po=map(valor, 0, 1023, 0, 10);
    Serial.println(po);
    delay(1);
    return po;
    } 
  void motor(){

if(po = 5){
  int parar = 0;
  

    digitalWrite(DIR, HIGH);
  for(int i=0; i<parar; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(700);
    digitalWrite(STEP, LOW);
    delayMicroseconds(700);
    digitalWrite(DIR, LOW);
  }
  for(int i=0; i<parar; i++){
    digitalWrite(STEP, HIGH);
    delayMicroseconds(700);
    digitalWrite(STEP, LOW);
    delayMicroseconds(700);
    digitalWrite(DIR, HIGH);  
  
  }

}

else {
  
  }
int parar = 2400;
return parar;
 }


void loop() {

Lec();     
motor();
}


  
  
 
