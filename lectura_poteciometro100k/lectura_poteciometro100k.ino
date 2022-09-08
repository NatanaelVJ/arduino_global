
const int analogPin = A1;
int value;      //variable que almacena la lectura analógica raw
int position;   //posicion del potenciometro en tanto por ciento
 
void setup() {
    Serial.begin(9600);
    Serial.println("Inicio");
}


 
void loop() {
   value = analogRead(analogPin);          // realizar la lectura analógica raw
   position = map(value, 0, 1023, 0, 100);  // convertir a porcentaje
   
   Serial.println(position);
 
   //...hacer lo que se quiera, con el valor de posición medido
 
   delay(1000);
}
