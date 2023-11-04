#include <Arduino.h>

const int led = 2;
int valueTouch = 0;

void setup()
{
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
}
void loop()
{
  valueTouch = touchRead(T0); // T0: GPIO4
  //Serial.println(valueTouch);
  if(valueTouch < 30)
  {
    digitalWrite(led, LOW);
  }
  else digitalWrite(led, HIGH);
  delay(100);
}