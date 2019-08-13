#include <Ultrasonic.h>
#define pino_trigger 3
#define pino_echo 4
const int motorA = 5;
const int motorB = 6;
const int dirA = 7;
const int dirB = 8;
const int PWM = 140;
int valorSensor1 = 0;
int valorSensor2 = 0;
int distancia = 0;
Ultrasonic ultrasonic(3, 4);

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(dirA, OUTPUT);
  pinMode(dirB, OUTPUT);
  Serial.begin(9600);
  delay(3300);

}

void loop() {   
  valorSensor1 = analogRead(A0);
  valorSensor2 = analogRead(A1); 
  distancia = ultrasonic.read();
  frente();
  if(distancia < 14){     
     atacar();
  }
  //refletancia - quando for colocar no Dojô, inverter sinais
  if(valorSensor1 > 500 || valorSensor2 > 500){
  tras();  
  viradireita();
  }
}
void tras(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, LOW);
  analogWrite(motorA, 40);
  analogWrite(motorB, 40);
  delay(500);
}

void frente(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 40);
  analogWrite(motorB, 40);
  delay(10);
}

void viradireita(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, LOW); 
  analogWrite(motorA, 60);
  analogWrite(motorB, 60);
  delay(250);
}

void viraesquerda(){
  digitalWrite(dirA, LOW);
  digitalWrite(dirB, HIGH); 
  analogWrite(motorA, 0);
  analogWrite(motorB, 40);
  delay(50);
}
void atacar(){
  digitalWrite(dirA, HIGH);
  digitalWrite(dirB, HIGH);
  analogWrite(motorA, 160);
  analogWrite(motorB, 160);
  delay(10);
}
