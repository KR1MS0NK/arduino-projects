

const int trigPin = 9;
const int echoPin = 8;
int RELAY = 6;
unsigned long pulseTime = 0;  // variable for reading the pulse
unsigned long distance = 0;   // variable for storing distance

void setup() {
  // put your setup code here, to run once:

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(3, OUTPUT);
 pinMode (RELAY, OUTPUT); 
 digitalWrite(RELAY, LOW);
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
pulseTime = pulseIn(echoPin, HIGH);
// Calculating the distance
 distance = pulseTime/2;

// Prints the distance on the Serial Monitor
if(distance < 50)
{
digitalWrite(RELAY, HIGH);
delay(5000);
digitalWrite(RELAY, LOW);
}
else
{
 digitalWrite(RELAY,LOW);
  digitalWrite(3,HIGH);
  delay(100);
  digitalWrite(3,LOW);
} 
}
