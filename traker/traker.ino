int ldr1 = A0; //TOP LEFT
int ldr2 = A1; //TOP RIGHT
int ldr3 = A2; //BOTTOM LEFT
int ldr4 = A3; //BOTTO RIGH


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

//Serial.println(analogRead(ldr1));
//Serial.println(analogRead(ldr2));
//Serial.println(analogRead(ldr3));
Serial.println(analogRead(ldr4));

}
