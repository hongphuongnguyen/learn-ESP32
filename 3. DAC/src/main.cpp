#include <Arduino.h>

const int pinDAC = 25;


void setup()
{
  Serial.begin(115200);
}
void loop()
{
  int value = 255;
  for(; value >= 0; value--)
  {
    dacWrite(pinDAC, value);
    delay(1);
  }
}