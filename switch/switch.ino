/*LED con interruptor
Permite el encendido y apagado del LED conectado a la salida 13
cuando pulsamos sobre el botón interruptor conectaco al pin2 */

int ledPin = 13;    // Pin conectado al LED:
int buttonPin1= 9;   //Pin conectado al botón interruptor
int buttonPind2= 10; // Variable binaria que indica el estado del interruptor
int buttonState1;
int buttonState2;

void setup() { 
Serial.begin(9600);  
pinMode(buttonPin1, INPUT);    // inicialización digital del pin 'led' como salida.
pinMode (buttonPind2, INPUT); //inicialización del botón pin como entrada
}

void loop() { 

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPind2);
  //Serial.println(buttonState1);
  Serial.println(buttonState2);

  
}
