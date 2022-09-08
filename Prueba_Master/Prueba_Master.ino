const int pinStart = 3;
boolean flag = false;
unsigned long debounce = 0; 

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);    //Iniciando puerto serial
pinMode(LED_BUILTIN, OUTPUT);
pinMode(pinStart,INPUT_PULLUP);
digitalWrite(LED_BUILTIN,LOW);
pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

   Serial.print("*");
   
   
   if(!digitalRead(pinStart))
  {
    pulse();
    noInterrupts();
    Serial.print("R"); 
    interrupts(); 
  }
  
  if(flag){
    digitalWrite(LED_BUILTIN, HIGH);

    flag = false;
  };  
}

void pulse(){
  
  if(!digitalRead(pinStart) && (millis()-debounce > 500))
  {
    debounce = millis();
    flag = true;
   } 
   
  } 
