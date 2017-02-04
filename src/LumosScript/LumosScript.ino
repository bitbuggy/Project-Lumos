/*
 * This project was recive a signal 
 * to turn On/Off an relay module.
 * You can send a command through Bluetooth (Here is utilizated an HC-05)
 * with the command 'e'(101) or send a sinal with serial comunication with the same command
 * or you can use a touch sensor.
 * 
 * Relay - Arduino pin 8
 * Touch Sensor - Arduino pin 6
 * Bluetooth Module RX<- - Arduino pin TX->
 * Bluetooth Module TX-> - Arduino pin RX<-
 * 
 * Version 0.9 January | 2017
 * Copyrigt Bit Buggy© and Denis Almeida
 */


#include <SoftwareSerial.h>
#include<string.h>

const int TouchPin = 6;
const int relayPin = 8;
bool state = false;
bool flag = false;
int serialData;
int serialDatab; 

void controlRelay(int control){
  if(control == 101){
     state = !state;
     digitalWrite(relayPin, state);
     Serial.println(serialData);
   }
}


void setup(){ 
  pinMode(TouchPin, INPUT);
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  Serial1.begin(38400);
}

void loop() {
  int sensorValue = digitalRead(TouchPin);
  
  if(sensorValue == 1){
    if (flag == false) {
      state = !state;
      digitalWrite(relayPin, state);
      flag = true;
      return (1);
    }
  }
  else {
    flag = false;
  }
  
  if(Serial.available() > 0){
    serialData = Serial.read();
    controlRelay(serialData);
  }

  if(Serial1.available() > 0){
    serialDatab = Serial1.read();
    controlRelay(serialDatab);
  }
    delay(100);
 }
