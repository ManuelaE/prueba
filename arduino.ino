
#include <Servo.h>


const int c = 261;
const int e = 329;

Servo servo1;
Servo servo2;
Servo servo3;
int buzzerPin = 8;
int numero = 0;
int numeroff=0;
String valor;
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  servo1.attach(9);
  servo2.attach(5);
  servo3.attach(6);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(buzzerPin, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  
  for ( int i = 0 ; i <=2 ;i ++){
    digitalWrite(numero,HIGH);
     
  } 
  if(numero == 100){
    noTone(buzzerPin);
  }

  if(numero == 2){
  tone(buzzerPin,e, 500);

  
  }
  if(numero == 3){
  tone(buzzerPin,c, 500);

  
  }
  if(numero == 4){
  tone(buzzerPin,150, 500);
  
  
  }
  if(numero == 2){

      
   for( int i = 0; i<180;i++){
    servo1.write(i);
    delay(2);
   }
    for( int i = 180; i>0;i--){
    servo1.write(i);
    delay(2);
   }
   
  }

  if(numero == 3){
      
   for( int i = 0; i<180;i++){
    servo2.write(i);
    delay(2);
   }
    for( int i = 180; i>0;i--){
    servo2.write(i);
    delay(2);
   }
   
  }

 if(numero == 4){
      
   for( int i = 0; i<180;i++){
    servo3.write(i);
    delay(2);
   }
    for( int i = 180; i>0;i--){
    servo3.write(i);
    delay(2);
   }
   
  }
   

if(numero == 100){
  
  for ( int i = 0 ; i < 3 ;i ++){
     digitalWrite(i+2,LOW);
  
    }
  
  }

}


void serialEvent() {

  int mensaje = Serial.read();
  numero = mensaje;
  

}

