int CLK = A4; //PIN A
int DT = A5; //PIN B

int contador = 0;
int estadoActual;
int estadoAntes;

void setup() {
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(13,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(4,INPUT_PULLUP);  //para el pulsador
  Serial.begin(9600);
  estadoAntes = digitalRead(CLK);
}

void loop() {


//para usar el pulsador
if(digitalRead(4) == LOW)//si se presiona el boton 
{                         //contador sera igual a 0
  contador = 0;
}
//fin del uso del contador

  digitalWrite(13, digitalRead(2));
  digitalWrite(11, digitalRead(3));
  estadoActual = digitalRead(CLK);

  if(estadoActual != estadoAntes && estadoActual ==1)
  {
    if(digitalRead(DT) != estadoActual)
    {
      contador++;
      Serial.println("contador: "+ String(contador));
    }
    else
    {
      contador--;
      Serial.println("contador: "+ String(contador));
    } 
  }
    estadoAntes = estadoActual;
    delay(3);
}
