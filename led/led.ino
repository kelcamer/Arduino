/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 

 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  
}
   int val = 255;

// light turns off at analog value of 127
void loop()
{

  val = 255;
  delay(1);
  analogWrite(13,val);
  val = 0;
  delay(1);
  analogWrite(13,val);
  

  
 // val=val-1;
 // Serial.println(val);
}
 

