int j = 0;
int dt = 500;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
while(j>1023){
Serial.println(j);
j++;
delay(dt);  
}
}
