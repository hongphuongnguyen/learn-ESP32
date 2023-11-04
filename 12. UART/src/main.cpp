#include <Arduino.h>

void setup()
{
  Serial2.begin(9600);      // UART2 with baudrate = 9600
}
void loop()
{
  while(Serial2.available())
  {
    Serial2.write(char(Serial2.read()));    // Serial2.read(): Doc data tu terminal luu vao bo nho dem 
                                            // Serial2.write(): Ghi data tu bo nho dem ra terminal
  }
}