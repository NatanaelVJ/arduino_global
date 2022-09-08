int A_DEL = 10;
int A_AT  = 9;


void setup() {
  // put your setup code here, to run once:
pinMode(A_DEL, OUTPUT);
  pinMode(A_AT, OUTPUT);
  

  delay(250);
}

void loop() {
  // put your main code here, to run repeatedly:
    
    digitalWrite(A_DEL,LOW);
    digitalWrite(A_AT,HIGH);
    delay(2000);
    digitalWrite(A_DEL,LOW);
    digitalWrite(A_AT,LOW);
    delay(2000);
    digitalWrite(A_DEL,HIGH);
    digitalWrite(A_AT,LOW);
    delay(2000);
    
      // put your main code here, to run repeatedly:

}
