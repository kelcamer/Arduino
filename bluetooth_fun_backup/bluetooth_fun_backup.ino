#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX  

// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 7
//     Pin 2/RXD          Pin 8
int state = 0;
void setup() {  
  Serial.begin(9600);
  
  mySerial.begin(9600);
  Serial.print("serial_ok");
  state = 1;
}

void loop() {  
  
  char c;
  String str = "";

 for(int x = 0; x < 10; x++){
 if (Serial.available()) {

    c = Serial.read();
    mySerial.print(c);
   
  }
  if (mySerial.available()) {
    c = mySerial.read();
    Serial.print(c);    
  }

  if(c != ' '){
  str+=c;
  }


  if(str == "321"){
    digitalWrite(9, HIGH);
    Serial.println("str " + str);

    
  }
 
 }


 /* switch(c){
   case 'r':
      Serial.println("Red!");
      break;
   case 'o':
      Serial.println("Orange!");
      break;
   
   case 'y':
      Serial.println("Yellow!");
      break;
   case 'g':
      Serial.println("Green!");
      break;
   
   case 'b':
      Serial.println("Blue!");
      break;
   case 'p':
      Serial.println("Purple!");
      break;
   
    
  }*/
 


  
}

