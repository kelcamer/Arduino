/*
Adafruit Arduino - Lesson 3. RGB LED
*/
#include "TimerOne.h"

 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  //Serial.begin(9600);
  Timer1.initialize(1); // 1 microsecond trigger
  Timer1.attachInterrupt(funct);
  
}
   int val = 255;

// light turns off at analog value of 127
void loop()
{

 
}
void funct(){
  PORTB ^= _BV(PB5);
  // we might be able to use analog write for giving it the voltage value. Otherwise
  // we can grab the analogWrite source code and delete all the extra timers that we are not using.


}


void analogWrite2(uint8_t pin, int val)
{
        // We need to make sure the PWM output is enabled for those pins
        // that support it, as we turn it off when digitally reading or
        // writing with them.  Also, make sure the pin is in output mode
        // for consistenty with Wiring, which doesn't require a pinMode
        // call for the analog output pins.
        pinMode(pin, OUTPUT);
        if (val == 0)
        {
                digitalWrite(pin, LOW);
        }
        else if (val == 255)
        {
                digitalWrite(pin, HIGH);
        }
        else
        {
                switch(digitalPinToTimer(pin))
                {
                        case TIMER0A:
                                // connect pwm to pin on timer 0, channel A
                                // COM0A1 is the bit location that is set to one. 
                                sbi(TCCR0A, COM0A1);
                                OCR0A = val; // set pwm duty. This is the number it counts to
                                break;

                        case TIMER0B:
                                // connect pwm to pin on timer 0, channel B
                                sbi(TCCR0A, COM0B1);
                                OCR0B = val; // set pwm duty
                                break;

                        case TIMER1A:
                                // connect pwm to pin on timer 1, channel A
                                sbi(TCCR1A, COM1A1);
                                OCR1A = val; // set pwm duty
                                break;

                        case TIMER1B:
                                // connect pwm to pin on timer 1, channel B
                                sbi(TCCR1A, COM1B1);
                                OCR1B = val; // set pwm duty
                                break;

                        case TIMER2A:
                                // connect pwm to pin on timer 2, channel A
                                sbi(TCCR2A, COM2A1);
                                OCR2A = val; // set pwm duty
                                break;

                        case TIMER2B:
                                // connect pwm to pin on timer 2, channel B
                                sbi(TCCR2A, COM2B1);
                                OCR2B = val; // set pwm duty
                                break;


                        case NOT_ON_TIMER:
                        default:
                                if (val < 128) {
                                        digitalWrite(pin, LOW);
                                } else {
                                        digitalWrite(pin, HIGH);
                                }
                }
        }
}

