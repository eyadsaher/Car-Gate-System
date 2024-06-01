#include <Servo.h>

Servo servo;

const int trigPin = 10;
const int echoPin = 11;
const int buttonPin = 2; 

long duration;
int distance;
bool gateOpen = false; 

void setup() 
{
  servo.attach(13);
  servo.write(90); 
  delay(2000);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance <= 25) 
  {
    servo.write(180);
    gateOpen = true; 
    delay(3000);
  } 
  else 
  {
    servo.write(90);
    gateOpen = false; 
  }

  if (digitalRead(buttonPin) == LOW)
  {
    servo.write(180);
    delay(2000);
    servo.write(90); 
    gateOpen = false;
    delay(500); 
  }

  delay(100); 
}
