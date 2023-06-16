

const int Bell1 = 4;
const int Bell2 = 5;
const int Bell3 = 6; /*this is telling the board we are working with 3 bells button
and also their ports on the board*/

const int buzzer1 = 7;
const int buzzer2 = 8;
const int buzzer3 = 9;/*this is telling the board we are working with 3 buzzers
and also their ports on the board*/
int dper = 5000;/*delay period*/
int bellState1 = 0;
int bellState2 = 0;
int bellState3 = 0;

void setup() {
  pinMode(Bell1, INPUT);
  pinMode(Bell2, INPUT);
  pinMode(Bell3, INPUT); /*bells are inputs*/
  pinMode(buzzer1, OUTPUT); /*buzzers are outputs*/
  digitalWrite(buzzer1, LOW);/*start the program with the buzzer off*/
  pinMode(buzzer2, OUTPUT); 
  digitalWrite(buzzer2, LOW);
  pinMode(buzzer3, OUTPUT); 
  digitalWrite(buzzer3, LOW);
  Serial.begin(9600);

}

void loop() {

  // read the state of the pushbutton value:
  bellState1 = digitalRead(Bell1);
  bellState2 = digitalRead(Bell2);
  bellState3 = digitalRead(Bell3);
  
  if(bellState1 == HIGH)
  {
   digitalWrite(buzzer1, HIGH);
   delay(dper);
   digitalWrite(buzzer1, LOW);
   delay(500);
    }
    
   if(bellState2 == HIGH)
  {
   digitalWrite(buzzer2, HIGH);
   delay(dper);
   digitalWrite(buzzer2, LOW);
   delay(500);
    }

  if(bellState3 == HIGH)
  {
   digitalWrite(buzzer3, HIGH);
   delay(dper);
   digitalWrite(buzzer3, LOW);
   delay(500);
    }

}
