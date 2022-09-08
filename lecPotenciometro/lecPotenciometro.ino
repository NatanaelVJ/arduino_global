
int pot0;
int pot1;
int pot2;
int pot3;



void setup (){
  Serial.begin(9600);
  
  
}

void Lec(){
    int pot0 = analogRead(A10); 
    int pot1 = analogRead(A15); 
    int pot2 = analogRead(A8);
    int pot3 = analogRead(A9);
    
    int po1=map(pot1, 0, 1023, 0, 5);
    int po2=map(pot2, 0, 1023, 0, 5);
    int po3=map(pot3, 0, 1023, 0, 10);
    int po0=map(pot0, 0, 1023, 0, 10);
    
    Serial.println(po1);
    Serial.println(po2);
    Serial.println(po3);
    Serial.println(po0);
    
    delay(50);
    return po1;
    return po2;
    return po3;
    return po0;
    } 

void loop (){

 Lec();
 Serial.println("...");
 
}
