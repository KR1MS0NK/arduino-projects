int red = 2;
int yelow = 3;
int green = 4;
void setup() {
  pinMode(red, OUTPUT);
  digitalWrite(red, LOW);
  pinMode(yelow, OUTPUT);
  digitalWrite(yelow, LOW);
  pinMode(green, OUTPUT);
  digitalWrite(green, LOW);
  Serial.begin(9600);
}

void loop() {
  delay(500);
  digitalWrite(yelow, HIGH);
  delay(500);
  digitalWrite(yelow, LOW);
  delay(500);
  digitalWrite(yelow, HIGH);
  delay(500);
  digitalWrite(yelow, LOW);
  delay(500);
  digitalWrite(green, HIGH);
  delay(10000);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(green, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(10000);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
  digitalWrite(red, LOW);
  delay(500);

}
