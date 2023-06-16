#include <Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 400;  // number of steps per revolution

Stepper myStepper1(stepsPerRevolution, 2, 4, 3, 5);
Servo myservoG; 
Servo myservoD;

int servoPinG = 6;
int servoPinD = 7;
const int trigPin  = 8;
const int echoPinG  = 9;
const int echoPinPa = 10;
const int echoPinPl = 11;
const int echoPinUn = 12;
int pos = 0;
int pos1 = 0;
float durationG, distanceG;
float durationPa, distancePa;
float durationPl, distancePl;
float durationUn, distanceUn;
// defines variables

void gate();
void dropper();
void segregate();
void full();
//DECLARE FUNCTIOS


void setup() {
    myservoG.attach(servoPinG);    //Attach Servo
    myservoD.attach(servoPinD);
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPinG, INPUT); // Sets the echoPin as an Input
    pinMode(echoPinPa, INPUT);
    pinMode(echoPinPl, INPUT);
    pinMode(echoPinUn, INPUT);
    Serial.begin(9600); // Starts the serial communication
  
}

void loop() {
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  durationG = pulseIn(echoPinG, HIGH);
  distanceG = (durationG*.0343)/2;
  durationPa = pulseIn(echoPinPa, HIGH);
  distancePa = (durationPa*.0343)/2;
  durationPl = pulseIn(echoPinPl, HIGH);
  distancePl = (durationPl*.0343)/2;
  durationUn = pulseIn(echoPinUn, HIGH);
  distanceUn = (durationUn*.0343)/2;
  
  Serial.print("DistanceG: ");
  Serial.println(distanceG);
  Serial.print("DistancePa: ");
  Serial.println(distancePa);
  Serial.print("DistancePl: ");
  Serial.println(distancePl);
  Serial.print("DistanceUn: ");
  Serial.println(distanceUn);
  gate();    
             
}

void gate(){
  if(distanceG <= 60)
  {
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservoG.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
    }
  }
  else
  {
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservoG.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
    }
  }
}

void dropper(){
  for (pos1 = 0; pos1 <= 90; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoD.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
  delay(2000);
  for (pos1 = 90; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservoD.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
}

void segregate(){
    
}
