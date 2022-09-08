#include <Stepper.h>

//Conexiones EasyDriver
#define step_pin 9  //Pin 9 conectado al Pin Steps
#define dir_pin 8   //Pin 8 conectado al Pin Direction
#define MS1 10      //Pin 10 conectado al Pin MS1
#define MS2 11      //Pin 11 conectado al Pin MS2
#define SLEEP 12    //Pin 12 conectado al Pin SLEEP

volatile boolean VueltaDetectada;   //Se necesita volatile para interrupciones
volatile boolean DireccionRotacion; //Rotación Derecha (sentido horario) o Izquierda (sentido anti-horario)

//Conexiones Encoder
const int PinCLK = 3; //Generación de interrupciones utilizando la Señal CLK
const int PinDT = 2;  //Lectura para Señal DT
const int PinSW;  //Lectura para el Botón

int PosicionMpp = 0;    //Almacena la Posición del MPP
int PasosRecorrido = 4; //Controla la velocidad del MPP por Rotación

int Direccion;  //Variable para setear la Rotación (Derecha o Izquierda) del MPP

//Rutina de Interrupción se ejecuta si CLK va desde HIGH a LOW
void DeteccionRotacion()
{
  delay(4); //Retardo para Rebote
  if(digitalRead(PinCLK))
    DireccionRotacion = digitalRead(PinDT);
  else
    DireccionRotacion = !digitalRead(PinDT);
  VueltaDetectada = true;
}

void setup()
{
  pinMode(MS1, OUTPUT);
  pinMode(MS2, OUTPUT);
  pinMode(dir_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
  pinMode(SLEEP, OUTPUT);
  digitalWrite(SLEEP, HIGH);  //Despierta al EasyDriver
  delay(5); //Espera para que el EasyDriver se despierte

  
  
/*
 *Tipos de Configuración de los Pasos en el EasyDriver:
 *MS1-MS2
 *LOW-LOW = Paso Completo
 *HIGH-LOW = 1/2 Paso
 *LOW-HIGH = 1/4 Paso
 *HIGH-HIGH = 1/8 Paso
 */
  digitalWrite(MS1, LOW); //Configuración para Pasos Completos
  digitalWrite(MS2, LOW); //Configuración para Pasos Completos

  pinMode(PinCLK, INPUT); //Setea Pin a Entrada
  pinMode(PinDT, INPUT);
  pinMode(PinSW, INPUT);
  digitalWrite(PinSW, HIGH);  //Resistor Pull-Up para Interruptor
  attachInterrupt(0, DeteccionRotacion, FALLING); //Interrupción 0 siempre conectado al Pin 2 en Arduino UNO
  Serial.begin(9600);
  Serial.println("listo");
  Serial.println(PosicionMpp);


}

void loop()
{
  if(!(digitalRead(PinSW))) //Revisa si el botón es presionado
  {
    if(PosicionMpp != 0)    //Revisa si el botón ya fue presionado
    {
      if(PosicionMpp > 0) //MPP fue movido a la derecha
      {
        while(PosicionMpp != 0) //Hacer hasta que la posición del Motor regresa a cero
        {
          digitalWrite(dir_pin, HIGH); // (HIGH = sentido anti-horario / LOW = sentido horario)
          for(int x = 1; x < PasosRecorrido; x++)
          {
            digitalWrite(step_pin, HIGH);
            delay(1);
            digitalWrite(step_pin, LOW);
            delay(1);
          }
          PosicionMpp = PosicionMpp - PasosRecorrido;
        }
      }
      else
      {
        while(PosicionMpp != 0)
        {
          digitalWrite(dir_pin, LOW); // (HIGH = sentido anti-horario / LOW = sentido horario)
          for(int x = 1; x < PasosRecorrido; x++)
          {
            digitalWrite(step_pin, HIGH);
            delay(1);
            digitalWrite(step_pin, LOW);
            delay(1);
          }
          PosicionMpp = PosicionMpp + PasosRecorrido;
        }
      }
      PosicionMpp = 0;  //Resetea la Posición a cero después de mover hacia atrás
    }
  }

  //Funciona si la rotación fue detectada
  if(VueltaDetectada)
  {
    VueltaDetectada = false; //No se repite hasta una nueva rotación detectada
 
    if(DireccionRotacion) //Mover el Motor en sentido anti-horario
    {
      digitalWrite(dir_pin, HIGH); // (HIGH = sentido anti-horario / LOW = sentido horario)
      for(int x = 1; x < PasosRecorrido; x++)
      {
        digitalWrite(step_pin, HIGH);
        delay(1);
        digitalWrite(step_pin, LOW);
        delay(1);
      }
      PosicionMpp = PosicionMpp - PasosRecorrido;
    }

    if(!DireccionRotacion)  //Mover el Motor en sentido horario
    {
      digitalWrite(dir_pin, LOW); // (HIGH = sentido anti-horario / LOW = sentido horario)
      for(int x = 1; x < PasosRecorrido; x++)
      {
        digitalWrite(step_pin, HIGH);
        delay(1);
        digitalWrite(step_pin, LOW);
        delay(1);
      }
      PosicionMpp = PosicionMpp + PasosRecorrido;
    }
  }
}
