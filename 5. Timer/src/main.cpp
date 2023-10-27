#include <Arduino.h>

const int button = 0;
const int led = 2;
bool startTimer = false;
unsigned long now = millis();
unsigned long lastPress = 0;

void IRAM_ATTR detectsPress()
{
  Serial.printf("Press detected!\n");
  lastPress = millis();
  digitalWrite(led, HIGH);
  startTimer = true;
}

void setup()
{
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  pinMode(led, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(button), detectsPress, FALLING);
}

void loop()
{
  if(startTimer && (now - lastPress) > 5000)
  {
    Serial.printf("Timer is stopped!\n");
    digitalWrite(led, LOW);
    startTimer = false;
  }
}