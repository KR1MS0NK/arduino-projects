 #include <Servo.h>
 Servo myservoG; 
Servo myservoD;


const int trigPin  = 8;
const int echoPin  = 9;
int servoPinG = 6;
int servoPinD = 7;
int pos = 0;
int pos1 = 0;

float durationG, distanceG; 

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT);
    myservoG.attach(servoPinG);    //Attach Servo
    myservoD.attach(servoPinD);
    Serial.begin(9600); // Starts the serial communication
}

void loop(){

    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

    durationG = pulseIn(echoPin, HIGH);
  distanceG = (durationG*.0343)/2;
 
 if(distanceG <= 60)
  {
    for (pos1 = 0; pos1 <= 90; pos1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservoD.write(pos1);
    }
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    myservoG.write(pos);              // tell servo to go to position in variable 'pos'
    delay(5000);                       // waits 15 ms for the servo to reach the position
    }
  }
  else
  {
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservoG.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
    }
     for (pos1 = 90; pos1 >= 0; pos1 -= 1) { // goes from 180 degrees to 0 degrees
    myservoD.write(pos1);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
  }
  }
}
