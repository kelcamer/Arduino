/*
Adafruit Arduino - Lesson 13. DC Motor
*/
 
// Note that if uploading the program fails, make sure  the correct port is selected.
int motorPin = 3;
 
void setup() 
{ 
    pinMode(13, OUTPUT);    
  pinMode(motorPin, OUTPUT);    // sets motor pin as output 
  Serial.begin(9600);           // opens up the uart input with a baud rate of 9600
  while (! Serial);             // while serial has no value, prompt the user.
  Serial.println("Speed 0 to 255");     // wow this is exactly like java and I love it.
} 
 
 
void loop() 
{ 
   
  if (Serial.available())           // if the data from the GUI is not blank
  {
    int speed = Serial.parseInt();      // parse data as int
    if (speed >= 0 && speed <= 255)     // sets speed to motor pin.
    {
    
      analogWrite(motorPin, speed);
    }
  }
} 
