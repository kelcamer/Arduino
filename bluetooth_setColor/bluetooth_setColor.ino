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
    pinMode(11,OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(9,OUTPUT);

}

void loop() {  

  
  char c;
  String str = "";

  str = getCommand();

   if((str.equals("set")) || (str.equals("set "))){
    analogWrite(11, 0);
    analogWrite(10, 0);
    analogWrite(9, 0);  
    Serial.println("hi");
    String firstStr = getCommand();
    String secStr = getCommand();
    String thirdStr = getCommand();
    int one = firstStr.toInt();
    int two = secStr.toInt();
    int three = thirdStr.toInt();
  
    analogWrite(11, one);
    analogWrite(10, two);
    analogWrite(9, three);  
    delay(300);

  }
  
 


  
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




