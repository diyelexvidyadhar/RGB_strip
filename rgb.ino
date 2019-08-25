/*
              Author:DIYelex
              date: 3/8/2019
*/

#include <SoftwareSerial.h> // TX RX software library for bluetooth
SoftwareSerial myserial(2, 3);  // Connect the TXD pin of BT module to pin 2 of the Arduino and the RXD pin of BT module to pin 3 of Arduino.
/////////Defining pins ////
int Red=9; 
int Green=10;
int Blue=11;
String readString;

void setup() {
 pinMode(Red,OUTPUT);
 pinMode(Green,OUTPUT);
  pinMode(Blue,OUTPUT);
 
  Serial.begin(9600); //serial communication 
  myserial.begin(9600); //Bluetooth serial communication with android//
}

void loop() 
{
  while(myserial.available()){
    delay(50);
    char data = myserial.read();
    readString+=data;
  }
  if(readString.length() > 0)
  {
    Serial.println(readString);
    if(readString=="red")
    {
      analogWrite(Red,255);  
      analogWrite(Green,0);
      analogWrite(Blue,0);    
    }
if(readString=="green")
    {
       analogWrite(Red,0);  
      analogWrite(Green,255);
      analogWrite(Blue,0);     
    }
if(readString=="blue")
    {
      analogWrite(Red,0);  
      analogWrite(Green,248);
      analogWrite(Blue,252);      
    }
if(readString=="pink")
    {
       analogWrite(Red,252);  
      analogWrite(Green,0);
      analogWrite(Blue,227);    
    }
if(readString=="yellow")
    {
     analogWrite(Red,227);  
      analogWrite(Green,255);
      analogWrite(Blue,0);     
    }
if(readString=="purple")
    {
       analogWrite(Red,123);  
      analogWrite(Green,0);
      analogWrite(Blue,255);    
    }
if(readString=="navyblue")
    {
       analogWrite(Red,3);  
      analogWrite(Green,23);
      analogWrite(Blue,252);   
    }
if(readString=="white")
    {
       analogWrite(Red,255);  
      analogWrite(Green,255);
      analogWrite(Blue,255);   
    }
   


    readString="";
  }
}
