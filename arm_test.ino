/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo1;  // create servo object to control a servo

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo1.attach(7);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 60; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
  delay(1000);
  
  for (pos = 60; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
  delay(5000);
  
}
