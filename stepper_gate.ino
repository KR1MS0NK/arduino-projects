#include <Stepper.h>

#define trigPin 9

#define echoPin 10

const int rasp = 12;

const int stepsPerRevolution = 400;  // number of steps per revolution

long duration, distance;



Stepper myStepper1(stepsPerRevolution, 2, 4, 3, 5);


void setup() {
    pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);


 

  
  // set the speed at 60 rpm:
  myStepper1.setSpeed(40);

  // initialize the serial port:
  pinMode(rasp, INPUT);

  Serial.begin(9600);
}

void loop() {
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;


  
  Serial.print("Distance: ");
  Serial.println(distance);
  
 

 //if(distance <= 30)
  //{
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper1.step(stepsPerRevolution);
  delay(500);

 // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper1.step(-stepsPerRevolution);
  delay(500);
  //}
  

 
}
