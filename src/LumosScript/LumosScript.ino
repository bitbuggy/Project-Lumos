//Bit Buggy 01/09/2017
//Project LUMOS


#include <SoftwareSerial.h>
#include<string.h>

const int TouchPin = 6;
const int ledPin = 3;
const int relayPin = 8;
bool ledstate = false;
bool flag = false;
int serialData;
int serialDatab; 

void controlRele(int control){
  if(control == 101){
     ledstate = !ledstate;
     digitalWrite(relayPin, ledstate);
     digitalWrite(ledPin, ledstate);
     Serial.println(serialData);
   }
}


void setup(){ 
  pinMode(TouchPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(38400);
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
    controlRele(serialData);
  }

  if(Serial1.available() > 0){
    serialDatab = Serial1.read();
    controlRele(serialDatab);
  }
    delay(100);
 }
