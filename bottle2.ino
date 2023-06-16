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
  myStepper.setSpeed(60);
  myservo.attach(12);
  Serial.begin(9600);
}

void clockwise(){
    unsigned long st = millis();
    while(true){
    Serial.println("clockwise");
    myStepper.step(stepPerRevolution); 
    if (millis() - st  > 2000){
      break;
      }
  }
}

void anticlockwise(){
  unsigned long st = millis();
  while(true){
    Serial.println("anti-clockwise");
    myStepper.step(-stepPerRevolution); 
    if (millis() - st  > 2000){
      break;
      }
  }
}

void Bottle(){
  clockwise();
  delay(1000);
  anticlockwise();
}


void Paper(){
  anticlockwise();
  delay(1000);
  clockwise();
}

void OpenClose(){
  for(pos = 0; pos <= 90; pos += 1){
     myservo.write(pos);
     delay(10);
    }

  delay(200);

  for(pos = 90; pos >= 0; pos -= 1){
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
    }

  if(n == 0){
    myservo.write(0);
    n == 1;
    }
}
