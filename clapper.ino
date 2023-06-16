int ledPin = 4;
int soundPin = A0; 
int clapCount = 0;  

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:
  int soundState = analogRead(soundPin); 
  if (soundState > 500){
    clapCount++; 
    delay(500); 
  }
  if (clapCount ==4){
    digitalWrite(ledPin, LOW); 
    clapCount = clapCount % 2; 
  }
  if (clapCount == 2){
    digitalWrite(ledPin, HIGH); 
  }
}
