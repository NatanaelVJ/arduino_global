

int LED = 13;
char estado;
bool R_state=0;
void setup() {

     pinMode(LED, OUTPUT);
     Serial.begin(9600);

}



void loop() {


    while(Serial.available()>0){
    estado=Serial.read(); 
    //Decision de accion a realizar
    if(estado=='d')
    {
      
      digitalWrite(LED, HIGH);
      delay(50);
      
     }

     if(estado=='e')
    {
      
     
      digitalWrite(LED, LOW);
      delay(50);
     }
     
     

     }
     }

     
