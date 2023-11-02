#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "ESP32-Wifi";
const char *password = "123456789";

void setup()
{
  Serial.begin(1152000);
  WiFi.softAP(ssid, password);
}

void loop()
{

}
