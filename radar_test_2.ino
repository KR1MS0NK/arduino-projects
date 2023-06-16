

const int trigPin1 = 3;
const int echoPin1 = 4;
const int trigPin2 = 5;
const int echoPin2 = 6;
const int trigPin3 = 7;
const int echoPin3 = 8;
const int trigPin4 = 9;
const int echoPin4 = 10;
int LED = 1;
int RELAY3 = 2;
int RELAY1 = 11;
int RELAY2 = 12;
int RELAY4 = 13;
float duration1,duration2,duration3,duration4,distance1,distance2,distance3,distance4;

void setup() {
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(trigPin4, OUTPUT);
  pinMode(echoPin4, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(RELAY3, OUTPUT);
  digitalWrite(RELAY3, LOW);
  pinMode (RELAY1, OUTPUT); 
  digitalWrite(RELAY1, LOW);
  pinMode (RELAY2, OUTPUT); 
  digitalWrite(RELAY2, LOW);
  pinMode (RELAY4, OUTPUT); 
  digitalWrite(RELAY4, LOW);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  digitalWrite(trigPin4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  digitalWrite(trigPin3, HIGH);
  digitalWrite(trigPin4, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);
  digitalWrite(trigPin4, LOW);

  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1*.0343)/2;
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2*.0343)/2;
  duration3 = pulseIn(echoPin3, HIGH);
  distance3 = (duration3*.0343)/2;
  duration4 = pulseIn(echoPin4, HIGH);
  distance4 = (duration4*.0343)/2;
  
  Serial.print("Distance1: ");
  Serial.println(distance4);

  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  
  if(distance1 <= 30)
  {
   digitalWrite(LED,HIGH);
   digitalWrite(RELAY1, HIGH);
   delay(5000);
   digitalWrite(RELAY1, LOW);
   delay(1000);
  }

   if(distance2 <= 30)
  {
   digitalWrite(LED,HIGH);
   digitalWrite(RELAY2, HIGH);
   delay(5000);
   digitalWrite(RELAY2, LOW);
   delay(1000);
  }

   if(distance3 <= 30)
  {
   digitalWrite(LED,HIGH);
   digitalWrite(RELAY3, HIGH);
   delay(5000);
   digitalWrite(RELAY3, LOW);
   delay(1000);
  }

   if(distance4 <= 30)
  {
   digitalWrite(LED,HIGH);
   digitalWrite(RELAY4, HIGH);
   delay(5000);
   digitalWrite(RELAY4, LOW);
   delay(1000);
  }

  
}
