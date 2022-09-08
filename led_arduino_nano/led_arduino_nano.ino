const int pinStart = 13;
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
   if(!digitalRead(pinStart))
  {
    pulse();
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
