//www.elegoo.com
//2016.12.9 


//Uno Pins:
// black = ground
// red = 5v
// blue = dig9
// white = dig11
//orange = dig12

int tDelay = 500;
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
  Serial.begin(9600);
}

void lights(int first_pin){

  leds=0;
  int last_pin = 4-first_pin;  //calculate last pin from last pin
  for (int i = first_pin; i < last_pin +1; i++){
    //light up everything between first and last pin
    Serial.println(i);
    bitSet(leds, i);
  }
}


void loop()
{

// 0-4 (Lights)
// 5 (servo)
  
  leds = 0;
  updateShiftRegister(); delay(500);

  for (int i = 4; i >=0; i--){
    lights(i);
    updateShiftRegister(); 
    delay(500);
  }
}







