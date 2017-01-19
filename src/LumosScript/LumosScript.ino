//BRAIN LABS 9/01/2017
//Projeto LUMOS

#include<string.h>

const int TouchPin = 6;
const int ledPin = 3;
const int relayPin = 8;
bool ledstate = false;
bool flag = false;
int serialData; 

void setup(){ 
  pinMode(TouchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensorValue = digitalRead(TouchPin);
  if(sensorValue == 1){
    if (flag == false) {
      ledstate = !ledstate;
      digitalWrite(relayPin, ledstate);
      digitalWrite(ledPin, ledstate);
      flag = true;
      return (1);
    }
  }
  else {
    flag = false;
  }
  if(Serial.available() > 0){
    serialData = Serial.read();
    
    if(serialData == 101){
      ledstate = !ledstate;
      digitalWrite(relayPin, ledstate);
      digitalWrite(ledPin, ledstate);
      Serial.println(serialData);
    }
   }
    delay(100);
 }
