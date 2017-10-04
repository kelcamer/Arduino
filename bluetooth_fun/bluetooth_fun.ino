void setup()
{
Serial.begin(9600);
Serial.begin(9600);
}

void loop()
{
if(Serial.available())
{
byte a=Serial.read();
Serial.write(a);
}
}
