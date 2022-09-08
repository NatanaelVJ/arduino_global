  
int infrarojo = 11;   
int valorInfrarojo = 1;  
int Ratras = 4;    
int Latras = 7;
int Radelante = 3;    
int Ladelante = 6;   
int PIR = 2;
int ESTADO = 1; 
int LED = 13;  
  
void setup() { 
  delay(20000);
  Serial.begin(9600); // Comenzamos comunicacion serial.
  pinMode(PIR, INPUT);
  pinMode(infrarojo, INPUT);     
  pinMode (Ladelante, OUTPUT);     
  pinMode (Radelante, OUTPUT);     
  pinMode (Latras, OUTPUT); 
  pinMode (Ratras, OUTPUT);
  pinMode (LED, OUTPUT);

  } 
void loop() { 
  
  ESTADO = digitalRead(PIR);
  Serial.print("PIR");       
  Serial.println(ESTADO);
  if (ESTADO == 1)
  {digitalWrite (LED, HIGH);}
  else { digitalWrite (LED, LOW);}
  valorInfrarojo = digitalRead(infrarojo);    
  Serial.print("SENSOR");       
  Serial.println(valorInfrarojo);    
  
  if(valorInfrarojo==1)  // no se detecta obstaculo el auto avanza 
  {  
  digitalWrite(Ladelante,1);
  digitalWrite(Radelante,1);
  digitalWrite(Latras,0);
  digitalWrite(Ratras,0); 
  
  }
  else // se detecta obstaculo el auto se detiene  
  {
  digitalWrite(Ladelante,0);
  digitalWrite(Radelante,0);
  digitalWrite(Latras,0);
  digitalWrite(Ratras,0); }

  
  }
 
