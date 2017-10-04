#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX  

// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 7
//     Pin 2/RXD          Pin 8

void setup() {  
  Serial.begin(9600);
  
  mySerial.begin(9600);
  Serial.print("serial_ok");
}

void loop() {  
  
  char c;
 if (Serial.available()) {

    c = Serial.read();
    mySerial.print(c);
   
  }
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.print(c);    
  }
}

