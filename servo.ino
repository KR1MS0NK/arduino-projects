#include <Servo.h>

const int servopin1 = 2;
const int servopin2 = 6;

Servo myservo1;
Servo myservo2;

void setup() {
  // put your setup code here, to run once:
  myservo1.attach(servopin1);
  myservo2.attach(servopin2);
}

void loop() {
  // put your main code here, to run repeatedly:
  myservo1.write(90);
  myservo2.write(90);

  delay(1000);

  myservo1.write(0);
  myservo2.write(0);

}
