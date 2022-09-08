#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);


/************ Valores utilizados para realizar la calibracion del sensor **************/
const float  OffSet = 0.44922 ; //normalizacion de la señal en V
/*************************************************************************************/


/************ Constantes para el calculo de litros  **************/

const float rho = 997; //densidad agua aceite 850
const float g = 9.8; //gravedad 
const float area = 12.19; // area en m2

float litros = 0.0;
/*************************************************************************************/

/************ Variables para mapear **************/
int porcentaje;
float V, P, val;

int  lecMin = 90;  //lectura minima del sensor 
int  lecMax = 91;  //lectura maxima del sensor
/*************************************************************************************/

void setup()
{
  Serial.begin(9600);        
  Serial.println("/** Visualizacion de la presion **/");
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(250);  
}
/*************************************************************************************/



/**************************Funcion para calibracion**********************************/  
void MonitoreoSerial(){ 

 float sensorValue = analogRead(A0); //lectura analogica del sensor
     
   V = 0;
   for (int i= 0; i<20; i++){         
   V = V + (sensorValue*5.0/1024.0);
   delay(5);
   }
   
   float Vout = V/20;           //****Muestreon y calculo del promedio para obtener una lectura fiable
   P = (Vout - OffSet) * 400;   //Calculo de la presion en Kpa           


  Serial.println();
  Serial.print(" Voltaje:");
  Serial.print(Vout, 5);
  Serial.println("V");

  Serial.print(" Presion:");
  Serial.print(P, 5);
  Serial.println(" KPa");

  Serial.print(" Lectura Analog:");
  Serial.print(sensorValue);
  Serial.println();

  delay(500);
  }
/*********************************************************************************************************/  


/***************Mapeo y linealizacion de la lectura del sensor ************************************/ 
void cal_Nivel(){  

   float sensorValue = analogRead(A0); //La lectura analogica va desde 0 a 1023, si contamos el 0 son 1024.  
   porcentaje = map(sensorValue, lecMin , lecMax, 0, 100);

   V = 0;
   for (int i= 0; i<10; i++){
   V = V + (sensorValue*5.0/1024.0);
   delay(50);
   }

   const float Vout = V/10;      //Muestreon y calculo del promedio para obtener una lectura fiable
   P = ((Vout - OffSet) * 400); //Calculo de la presion en Kpa  
  
   const float  niv = ((P*1000)/(rho*g));  // calculo del nivel en m (multiplicar "p" x 100 parapasar a cm)   
   litros = niv*area;                     // calculo del nivel

   
   lcd.clear();
   lcd.print("Cap:");
   lcd.print(" ");
   lcd.print(litros,1); 
   lcd.print("Lts.");

   lcd.setCursor(0, 1);
   lcd.print("Llenado: ");
   lcd.print(porcentaje);
   lcd.print("%");
   
} 
   



/***************Mapeo y linealizacion de la lectura del sensor ************************************/   
void loop(){

   MonitoreoSerial(); //Desactivar funcion una vez calibrado los valores: lecMin, lecMax y OffSet
   cal_Nivel();      //Funcion visible en LCD 16X2
   delay(50);
}
