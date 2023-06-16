#include <Stepper.h>

const int rasp = 12;
const int berry = 11;
const int stepsPerRevolution = 400;  // number of steps per revolution
int caller1 = 0;
int caller2 = 0;



Stepper myStepper1(stepsPerRevolution, 2, 4, 3, 5);
//Stepper myStepper2(stepsPerRevolution, 6, 8, 7, 9);

void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
//  myStepper2.setSpeed(60);
  // initialize the serial port:
  pinMode(rasp, INPUT);
  pinMode(berry, INPUT);
  Serial.begin(9600);
}

void loop() {

  caller1 = digitalRead(rasp);
  caller2 = digitalRead(berry);

  if (caller1 == HIGH)
  {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper1.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper1.step(-stepsPerRevolution);
  delay(500);
  }
  

// if (caller2 == HIGH)
//  {
//  // step one revolution  in one direction:
//  Serial.println("clockwise");
//  myStepper2.step(stepsPerRevolution);
//  delay(500);
//
//  // step one revolution in the other direction:
//  Serial.println("counterclockwise");
//  myStepper2.step(-stepsPerRevolution);
//  delay(500);
//  }

}
