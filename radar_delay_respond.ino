
const int trigPin  = 8;
const int echoPin  = 9;
int sig = 7; 
float duration1, distance1;
// defines variables

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(sig, OUTPUT);
digitalWrite(sig, LOW);
Serial.begin(9600); // Starts the serial communication
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration1 = pulseIn(echoPin, HIGH);
  distance1 = (duration1*.0343)/2;
  
  Serial.print("Distance: ");
  Serial.println(distance1);

  if(distance1 <= 30)
  {
   delay (5000);
   Serial.print("Distance: ");
   Serial.println(distance1);
     if(distance1 <= 30){
      digitalWrite(sig, HIGH);
     }
     else
     {
      digitalWrite(sig,LOW);
     }
  }
  else
  {
  digitalWrite(sig,LOW);
  }
}
