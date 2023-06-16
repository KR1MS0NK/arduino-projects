#include <Servo.h>
Servo servo1;
Servo servo2;
Servo claw;
int x_key = A1;                                               
int y_key = A0;                                               
int x_pos;
int y_pos;
int servo1_pin = 3;
int servo2_pin = 4;  
int initial_position = 90;
int initial_position1 = 90;


int pos = 0;

int buttn = 5;
int buttnState = 0;
 int clawc = 0;

void setup ( ) {
Serial.begin (9600) ;
servo1.attach (servo1_pin ) ; 
servo2.attach (servo2_pin ) ; 
servo1.write (initial_position);
servo2.write (initial_position1);
pinMode (x_key, INPUT) ;                     
pinMode (y_key, INPUT) ;   

pinMode(buttn, INPUT);
claw.attach(2);

}

void loop ( ) {
//x_pos = analogRead (x_key) ;  
//y_pos = analogRead (y_key) ;                      
//
//if (x_pos < 300){
//if (initial_position < 10) { } else{ initial_position = initial_position - 20; servo1.write ( initial_position ) ; delay (100) ; } } if (x_pos > 700){
//if (initial_position > 180)
//{  
//}  
//else{
//initial_position = initial_position + 20;
//servo1.write ( initial_position ) ;
//delay (100) ;
//}
//}
//
//if (y_pos < 300){
//if (initial_position1 < 10) { } else{ initial_position1 = initial_position1 - 20; servo2.write ( initial_position1 ) ; delay (100) ; } } if (y_pos > 700){
//if (initial_position1 > 180)
//{  
//}        
//else{
//initial_position1 = initial_position1 + 20;
//servo2.write ( initial_position1 ) ;
//delay (100) ;
//}
//}

buttnState = digitalRead(buttn);
if (buttnState == HIGH, clawc == 0) {
    // open claw:
     for (pos = 0; pos <= 59; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
    }
    clawc = 1;
    } 
else if(buttnState == HIGH, clawc == 1) {
    // close claw:
    for (pos = 59; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    claw.write(pos);              // tell servo to go to position in variable 'pos'
    delay(10);                       // waits 15 ms for the servo to reach the position
    }
  }
}
