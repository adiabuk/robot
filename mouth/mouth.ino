//www.elegoo.com
//2016.12.9 

int tDelay = 50;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

byte leds = 0;

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void lights(int pin){

int first_pin=pin;
leds=0;
int last_pin = 7-first_pin;
for (int i = first_pin; i < last_pin +1; i++){
bitSet(leds, i);
}
  
}

void loop() 
{
  leds = 0;
  updateShiftRegister();
  delay(tDelay);
  for (int i = 5; i >= 0; i--)
  {
    //bitSet(leds, i);
    lights(i);
    updateShiftRegister();
    delay(tDelay);
  }
}





