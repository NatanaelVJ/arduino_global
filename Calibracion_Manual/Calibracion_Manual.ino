 
// only x axis is used for dolly
#define EN 8 // stepper motor enable
#define X_DIR 5// x axis direction control
#define Y_DIR 6// y axis direction control
#define Z_DIR 7// z axis direction control
#define X_STP 2// x axis step control
#define Y_STP 3// y axis step control
#define Z_STP 4// z axis step control


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
  // setup stepper motor I/O pin to output
  pinMode(X_DIR, OUTPUT); pinMode(X_STP, OUTPUT);
  pinMode(Y_DIR, OUTPUT); pinMode(Y_STP, OUTPUT);
  pinMode(Z_DIR, OUTPUT); pinMode(Z_STP, OUTPUT);
  pinMode(EN, OUTPUT);
  digitalWrite(EN, HIGH);
  Serial.begin(9600);
  Serial1.begin(9600);
}


void Lec(){
    
    int pot1 = analogRead(A8);
    int pot2 = analogRead(A10);
    int pot3 = analogRead(A12);
    int po1=map(pot1, 0, 1023, 0, 5);
    int po2=map(pot2, 0, 1023, 0, 5);
    int po3=map(pot3, 0, 1023, 0, 5);

    Serial.println(po1);
    Serial.println(po2);
    Serial.println(po3);
    Serial.println("******");     
    delay(50);

    VAR = po1;
    VAR1 = po2;
    VAR2 = po3; 
    return VAR;
    return VAR1;
    } 
    
void loop (){

Lec();

//Serial.println(VAR);
delay(10);
if(Serial1.available()>0){
bluetooth =Serial1.read();
}
char posicion = bluetooth;



///////codo/////

if (posicion=='1'){
digitalWrite(EN, LOW); 
step(false, X_DIR, X_STP, 100);
digitalWrite(EN, HIGH);

} 
else if (posicion=='A'){
digitalWrite(EN, LOW);
step(true, X_DIR, X_STP, 100);  
digitalWrite(EN, HIGH); 
}

else if (posicion=='2'){
digitalWrite(EN, LOW);
step(false, Y_DIR, Y_STP, 100);  
digitalWrite(EN, HIGH); 
}

else if (posicion=='B'){
digitalWrite(EN, LOW);
step(true, Y_DIR, Y_STP, 100);  
digitalWrite(EN, HIGH); 
}

else if (posicion=='3') {
digitalWrite(EN, LOW);
step(false, Z_DIR, Z_STP, 100);  
digitalWrite(EN, HIGH); 
}

else if (posicion=='C') {
digitalWrite(EN, LOW);
step(true, Z_DIR, Z_STP, 100);  
digitalWrite(EN, HIGH); 

}

digitalWrite(EN, HIGH); 


}
