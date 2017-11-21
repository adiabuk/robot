//www.elegoo.com
//2016.12.08
#include "SR04.h"
#define TRIG_PIN 12
#define ECHO_PIN 11
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;
int buzzer = 7;

void setup() {
   Serial.begin(9600);
   delay(1000);
   pinMode(buzzer, OUTPUT);
}

void noise() {
   unsigned char i;
   unsigned char x;
   
   //output an frequency
   for(i=0;i<80;i++)
   {
    digitalWrite(buzzer,HIGH);
    delay(1);//wait for 1ms
    digitalWrite(buzzer,LOW);
    delay(1);//wait for 1ms
    }
    //output another frequency
     for(i=0;i<100;i++)
      {
        digitalWrite(buzzer,HIGH);
        delay(2);//wait for 2ms
        digitalWrite(buzzer,LOW);
        delay(2);//wait for 2ms
      }
  }


void loop() {
   a=sr04.Distance();
   if (a < 50){
    noise();
   }
   Serial.print(a);
   Serial.println("cm");
   delay(1000);
}
