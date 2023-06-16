#include<SoftwareSerial.h>

#define trigPin 9

#define echoPin 10

#define piezoPin 8

SoftwareSerial mySerial(2, 3);

int normalDistance;

boolean triggered = false;

long duration, distance;

void setup()

{

mySerial.begin(9600);

Serial.begin (9600);

delay(100);

pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

pinMode(piezoPin, OUTPUT);

digitalWrite(piezoPin, HIGH);




digitalWrite(piezoPin, HIGH);

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

normalDistance = distance;

Serial.print("Distance: ");

Serial.println(distance);

digitalWrite(piezoPin, LOW);

}

void loop()

{

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");

Serial.println(distance);

if (distance < normalDistance-5)

{

triggered = true;

}

else

{

triggered = false;

}

if (triggered)

{

tone(piezoPin, 635);

delay(500);

tone(piezoPin, 912);

delay(250);

mySerial.println("AT+CMGF=1");

//Sets the GSM Module in Text Mode

delay(1000);

// Delay of 1000 milli seconds or 1 second mySerial.println("AT+CMGS=\"+233594248172\"\r");

// Replace x with mobile number

delay(1000);

mySerial.println("The bin is full... Come and take out your rubbish");

// The SMS text you want to send delay(100);

mySerial.println((char)26);

// ASCII code of CTRL+Z

delay(1000);

} }
