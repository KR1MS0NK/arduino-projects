int threshold=1000;
int digitalRead(leadPin, LOW);


void setup() {
  Serial.begin(9600);
  pinMode(leadPin,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  if (  digitalRead(leadPin, LOW))
    
  
    {
      delay(50);
      digitalWrite(leadPin,HIGH);
    }
  
  // put your main code here, to run repeatedly:

}
