

int LED = 13;
char posicion;
bool R_state=0;
void setup() {

     pinMode(LED, OUTPUT);
     Serial1.begin(9600);

}



void loop() {


    while(Serial1.available()>0){
    posicion=Serial1.read(); 
    //Decision de accion a realizar
    if(posicion=='R')
    {
      R_state=!R_state; 
      digitalWrite(LED, HIGH);
      delay(500);
      digitalWrite(LED, LOW);
      delay(500);
     }
     

     }
     }

     
