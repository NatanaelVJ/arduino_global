


//Mapeo de pines
#define STBY 5//  
#define AIN1  8//   8
#define AIN2  7// 
#define PWMB  3// 3
#define PWMA  6// 6 
#define BIN1  4//    
#define BIN2  2//  2
 





void setup()
{
// Declaramos como salida los pines utilizados

  pinMode(BIN2  ,OUTPUT);
  pinMode(STBY  ,OUTPUT);
  pinMode(BIN1  ,OUTPUT);
  pinMode(PWMB  ,OUTPUT);
  pinMode(AIN1  ,OUTPUT);
  pinMode(AIN2  ,OUTPUT);
  pinMode(PWMA  ,OUTPUT);


}

void loop()
{   
    digitalWrite(STBY,HIGH);
    delay(50);
    analogWrite (PWMB, 255);
    analogWrite (PWMA, 255);
    digitalWrite(AIN1,LOW);
    digitalWrite(AIN2,HIGH);
    digitalWrite(BIN1,LOW);
    digitalWrite(BIN2,HIGH);
}
