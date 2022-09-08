#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const float  OffSet = 0.439 ;
double rho = 997; //densidad agua aceite 850
double g = 9.8; //gravedad 
double area = 0.56; // m2
double litros = 0.0;


byte nivel[8] = {B11111,B11111,B11111,B11111,B11111,B11111,B11111,B11111,}; //El Siguiente Array dibuja el carcater para visualizar el nivel


void setup()
{
  Serial.begin(9600);        // open serial port, set the baud rate to 9600 bps
  Serial.println("/** Visualizacion de la presion **/");
  lcd.begin(16, 2);
  lcd.print("Iniciando...");
  delay(1000);
  
}

  void MonitoreoSerial(){
  //Connect sensor to Analog 0
  V = analogRead(0) * 5.00 / 1024;     //Sensor output voltage
  P = (V - OffSet) * 400;             //Calculate water pressure

  Serial.print("Voltaje:");
  Serial.print(V, 3);
  Serial.println("V");

  Serial.print(" Presion:");
  Serial.print(P, 1);
  Serial.println(" KPa");
  Serial.println();

  delay(500);
  }

void cal_Nivel(){  

   int sensorValue = analogRead(A0); //La lectura analogica va desde 0 a 1023, si contamos el 0 son 1024. 

   V = ((analogRead(0) * 5.00) / 1024.00); //calculo del voltaje (0.5V - 4.5V)

   int val = analogRead(sensor);
   val = map(val, 0.44, 5, 0.44, 5);

   V = 0;
   for (int i= 0; i<10; i++){
   V = V + (sensorValue*5.0/1024.0);
   delay(50)

   Serial.println(val);
   delay(50);
   
   P = (V-OffSet)*400;   //Calculo de la presion en Kpa
   LT= 20*P ;
   niv = ((P*1000)/(rho*g));  // calculo del nivel en m (multiplicar x 100 parapasar a cm)
   litros = niv*area;
   
   lcd.clear();
   lcd.print("Cap:");
   lcd.print(" ");
   lcd.print(val); //niv
   lcd.print("LT");

   lcd.setCursor(0, 1);   //marca 1 
   lcd.write(byte(1));

  

}

  
void loop(){

   cal_Nivel();     //Se llama a la Funcion
   delay(250);
}