#define rele 6
#define rele2 7 



void setup() {
  // put your setup code here, to run once:

pinMode(rele, OUTPUT);
pinMode(rele2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

digitalWrite(rele, HIGH);
digitalWrite(rele2, LOW);
delay(5000);
digitalWrite(rele2, HIGH);
digitalWrite(rele, LOW);
delay(5000);
digitalWrite(rele, LOW);
digitalWrite(rele2, LOW);
delay(5000);

}
