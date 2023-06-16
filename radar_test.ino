

const int trigPin = 9;
const int echoPin = 10;
int LED = 7;
int RELAY = 6;
float duration, distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode (RELAY, OUTPUT); 
  digitalWrite(RELAY, LOW);
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
  
  if(distance <= 30)
  {
   digitalWrite(RELAY, HIGH);
   delay(5000);
   digitalWrite(RELAY, LOW);
   delay(1000);
  }
  else
  {
  digitalWrite(RELAY,LOW);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
  delay(500);
  } 
  }
  
