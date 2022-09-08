int contador;
int pausa;

void setup() {               
  pinMode(8, OUTPUT);    
  pinMode(9, OUTPUT);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  contador = 0;
  pausa = 0.5;
}

void loop() {
  //Contamos cada paso que damos
  contador = contador+1;
 
  //Si el motor ha dado dos vueltas reiniciamos el contador de pasos
  //y ponemos la nueva velocidad
  if (contador == 3200)
  {
    contador=0;
    pausa = pausa-100;
  } 
 
  //Si la pausa sigue siendo mayor que 100 mandamos impulso
  //Sino termina el programa
  if (pausa >= 100)
  {
    digitalWrite(9, HIGH);         
    delayMicroseconds(500);
    digitalWrite(9, LOW); 
   delayMicroseconds(500);  
  }
}
