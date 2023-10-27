#include <Arduino.h>

const int pinADC = 34;  // Dinh nghia chan ket noi ADC
int value = 0;          // Dinh nghia gia tri do duoc

void setup()
{
  Serial.begin(115200); // Khoi tao serial de hien len monitor
  delay(1000);          // Dam bao serial duoc khoi tao
}

void loop()
{
  // Doc gia tri analog
  value = analogRead(pinADC);
  Serial.println(value);
  delay(500);
}
