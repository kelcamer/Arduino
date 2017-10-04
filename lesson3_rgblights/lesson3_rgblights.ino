/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int delaytime = 35;
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
}
 
void loop()
{

  analogWrite(redPin, 255);
  analogWrite(bluePin, 255);
  analogWrite(greenPin, 255);
  delay(delaytime);
  analogWrite(redPin, 0);
  analogWrite(bluePin, 0);
  analogWrite(greenPin, 0);
  delay(delaytime);

 // delaytime--;
}
 
void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
