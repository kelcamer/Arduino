#include <SoftwareSerial.h>

SoftwareSerial mySerial(6, 7); // RX, TX  

// Connect HM10      Arduino Uno
//     Pin 1/TXD          Pin 7
//     Pin 2/RXD          Pin 8
int state = 0;
int light = 0;
void setup() {  
  Serial.begin(9600);
  
  mySerial.begin(9600);
  Serial.print("serial_ok");
  state = 1;
    pinMode(9,OUTPUT);

}

void loop() {  

  if(light == 0){
     digitalWrite(9, LOW);
     delay(300);
  }
  else{
     digitalWrite(9, HIGH);
     delay(300);
  }
  
  char c;
  String str = "";

 for(int x = 0; x < 15; x++){
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
  else{
    break;
  }
 }

  if((str.equals("on")) || (str.equals("on ")) || (str.equals("ON")) || (str.equals("ON "))){
    
    light = 1;
  

    
  }
  else if((str.equals("off")) || (str.equals("off "))){
   
    
    light = 0;
    
  }
  else if((str.equals("set")) || (str.equals("set "))){
    Serial.println("hi");
    String firstStr = getCommand();
    String secStr = getCommand();
    String thirdStr = getCommand();
    int one = firstStr.toInt();
    int two = secStr.toInt();
    int three = thirdStr.toInt();
    Serial.println(two);
    Serial.println(three);
        Serial.println(one);

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





String getCommand(void){
String str = "";
char c = 8;


    while(((c != 0) && (c!=' ') && (c!= ','))){
      Serial.println("get command");

    if (mySerial.available()) {
     c = mySerial.read();
         str+=c;

    }
    Serial.print(c);    
    }
    
    
  
  
    return str;

}




