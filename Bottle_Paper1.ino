#include <Stepper.h>
#include <Servo.h>
char msg;
const int stepPerRevolution = 200;
int n = 0;
Servo myservo;
int pos = 0;
Stepper myStepper(stepPerRevolution,2,4,3,5);

void setup() {
  // put your setup code here, to run once:
  myStepper.setSpeed(120);
  myservo.attach(12);
  Serial.begin(9600);
}

void Bottle(){
  unsigned long st = millis();
  while(true){
    Serial.println("clockwise");
    myStepper.step(stepPerRevolution); 
    if (millis() - st  > 250){
      break;
      }
  }
}


void Paper(){
  unsigned long st = millis();
  while(true){
    Serial.println("anti-clockwise");
    myStepper.step(-stepPerRevolution); 
    if (millis() - st  > 250){
      break;
      }
  }
}

void OpenClose(){
  for(pos = 0; pos <= 120; pos += 1){
     myservo.write(pos);
     delay(10);
    }

  delay(200);

  for(pos = 120; pos >= 0; pos -= 1){
     myservo.write(pos);
     delay(10);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    msg = Serial.read();

    if (msg == 'b'){
        Bottle();
        
      }

     if (msg == 'p'){
        Paper();
      }

    if (msg == 'o'){
        Serial.println("Open");
        OpenClose();
      }
  }

  if(n == 0){
    myservo.write(0);
    n == 1;
    }
}
