#include <Arduino.h>

#define button 0
int numPress = 0;
bool isPress = false;

void IRAM_ATTR ISR()
{
  numPress++;
  isPress = true;
}
void setup()
{
  Serial.begin(115200);
  pinMode(button, INPUT_PULLUP);
  attachInterrupt(button, ISR, FALLING);
}

void loop()
{
  if(isPress)
  {
    Serial.printf("Nut nhan duoc nhan %d lan\n", numPress);
    isPress = false;
  }
}