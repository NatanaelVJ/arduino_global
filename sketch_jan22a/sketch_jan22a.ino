void setup() {               
  pinMode(8, OUTPUT);    
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
}

void loop() {
  digitalWrite(9, HIGH);
 delayMicroseconds(100);       
  digitalWrite(9, LOW);
  delayMicroseconds(100);        
}
