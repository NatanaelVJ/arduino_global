// rotary encoders
int LeftOutApin = 3;
int LeftOutBpin = 2;
int LeftCounter = 0;
int LeftState;
int LeftLastState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(LeftOutApin, INPUT);
  pinMode(LeftOutBpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
LeftRotaryEncoder();

Serial.print("Left: ");
Serial.println(LeftCounter); 
}


void LeftRotaryEncoder() {
  LeftState = digitalRead(LeftOutApin);
  if (LeftState != LeftLastState) {
    if (digitalRead(LeftOutBpin) != LeftState) {
      LeftCounter ++;
    } else {
      LeftCounter --;
    }
  }
  LeftLastState = LeftState;
}
