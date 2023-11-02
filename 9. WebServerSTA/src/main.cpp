#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "Phuong Huyen";
const char *pass = "123456789";

WebServer myserver(80);
String html = "<h1 style=\"text-align: center;\">ESP32 WEBSERVER</h1> <p style=\"text-align: center;\">Nguyen Do Hong Phuong</p> <p style=\"text-align: center;\">Learn ESP32</p>";

void handle_connect()
{
  Serial.println("HTTP Request!");
  myserver.send(200, "text/html", html);
}
void handle_hello()
{
  Serial.println("HTTP Request!");
  myserver.send(200, "text/plain", "Hello I'm Phuong");
}

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while(WiFi.status() == WL_CONNECTED);
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  myserver.on("/", handle_connect);
  myserver.on("/hello", handle_hello);
  myserver.begin();
}

void loop()
{
  myserver.handleClient();
}