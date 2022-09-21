int PIR = 0;

int photo = 0;

int tmp = 0;

int gas = 0;

void setup()
{
  pinMode(A2, INPUT);
  pinMode(2, INPUT);
  pinMode(A1, INPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  photo = analogRead(A2);
  PIR = digitalRead(2);
  tmp = (-40 + 0.488155 * (analogRead(A1) - 20));
  gas = analogRead(A0);
  Serial.println(gas);
  if (PIR == 1) {
    while (PIR == 1) {
      digitalWrite(3, HIGH);
      delay(100); // Wait for 100 millisecond(s)
      digitalWrite(3, LOW);
      delay(100); // Wait for 100 millisecond(s)
      PIR = digitalRead(2);
    }
  }
  if (photo >= 500) {
    digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
  }
  if (500 > gas) {
    noTone(8);
  } else {
    tone(8, 523, 1000); // play tone 60 (C5 = 523 Hz)
    delay(100); // Wait for 100 millisecond(s)
    noTone(8);
    delay(100); // Wait for 100 millisecond(s)
  }
}