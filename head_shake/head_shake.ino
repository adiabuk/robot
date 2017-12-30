//www.elegoo.com
//2016.12.08

//Uno Pins:
// black = ground
// red = 5v
// yellow = dig9


#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(90);
  delay(10000);
}



void loop() {
  for (int seq = 0; seq <= 3; seq +=1){
    for (pos = 45; pos <= 135; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(1);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 135; pos >= 45; pos -= 1) { // goes from 180 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(1);                       // waits 15ms for the servo to reach the position
    }
  }
  myservo.write(90);
  delay(2000);
}
