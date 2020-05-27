const int buttonPin = 2;
const int ledPin13 = 13;
const int ledPin10 = 10;

int buttonState = 0;
int lastButtonState = 0;
int randVal = 0;
int upLed;

const int trigPin = 6;
const int echoPin = 7;
const int ledPin = 9;

long duration;
int distance;
int safetyDistance;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT);
  pinMode(ledPin13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin10, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int Rotary = analogRead(1);
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
    } else {

      Serial.println(1);
    }
    delay(50);
  }
  Serial.println(Rotary);
  //  Serial.println(pot);
  lastButtonState = buttonState;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  safetyDistance = distance;
  if (safetyDistance <= 50) {

    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
  // Serial.print("Distance: ");
  Serial.println(distance);
  if(Serial.available()){
    upLed = Serial.read();

    digitalWrite(ledPin10,HIGH);
    delay(100);
  }    else {
    digitalWrite(ledPin10,LOW);
  }
}
