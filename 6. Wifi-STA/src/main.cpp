#include <Arduino.h>
#include <WiFi.h>

const char *ssid = "Phuong Huyen";
const char *password = "123456789";

void setup()
{
  Serial.begin(115200);
  Serial.println("Connect to Wifi...");
  WiFi.begin(ssid, password);
  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Wifi is connected!");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  }
}

void loop()
{
  
}