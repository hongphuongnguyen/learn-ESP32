#include <Arduino.h>

const int pinPWM = 2;
const int freq = 5000;  // Khoi tao tan so 5000 Hz doi voi led
const int channel = 0;
const int resolution = 8;   // Khoi tao do phan giai 8 bit (0 <= duty cycle <= 255)

void setup()
{
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(pinPWM, channel);
}

void loop()
{
  // Led sang dan
  for(int dutycycle = 0; dutycycle <= 255; dutycycle++)
  {
    ledcWrite(channel, dutycycle);
    delay(100);
  }

  // Led tat dan
  for(int dutycycle = 255; dutycycle >=0; dutycycle--)
  {
    ledcWrite(channel, dutycycle);
    delay(100);
  }
}