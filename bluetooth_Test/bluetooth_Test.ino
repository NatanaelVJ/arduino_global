int led13=13;

String readString;

void setup() {
Serial.begin(9600);
pinMode(led13, OUTPUT);
}

void loop() {
  while(Serial.available()){
    delay(3);
    char c = Serial.read();
    readString += c;
    }
    if (readString.length() >0){
      Serial.println(readString);
      if (readString == "on")
      {
        digitalWrite(led13, HIGH);
        }
         if (readString == "off"){
         digitalWrite(led13, LOW); 
         }
         readString="";
      }
}
