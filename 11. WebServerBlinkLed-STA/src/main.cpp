#include "WiFi.h"
#include "WebServer.h"

const char *ssid = "13traicatang1";
const char *pass = "13traicat1";

int led1 = 2;
bool led1Status = LOW;
int led2 = 3;
bool led2Status = LOW;

WebServer server(80);

String sendHTML(bool led1Status, bool led2Status);
void handle_OnConnect();
void handle_led1on();
void handle_led1off();
void handle_led2on();
void handle_led2off();
void handle_onnotfound();

void setup()
{
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(2000);
    Serial.print(".");
  }
  Serial.println("\nWifi is connected!");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  server.on("/", handle_OnConnect);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.onNotFound(handle_onnotfound);
  server.begin();
  Serial.println("HTTP is connected!");
  delay(100);
}
void loop()
{
  server.handleClient();
  if(led1Status)  digitalWrite(led1, HIGH);
  if(!led1Status) digitalWrite(led1, LOW);
  if(led2Status)  digitalWrite(led2, HIGH);
  if(!led2Status) digitalWrite(led2, LOW);
}

void handle_OnConnect()
{
  led1Status = LOW;
  led2Status = LOW;
  Serial.println("LED 1 Status: OFF | LED 2 Status: OFF");
  server.send(200, "text/html", sendHTML(led1Status, led2Status));
}

void handle_led1on()
{
  led1Status = HIGH;
  Serial.println("LED 1 Status: ON");
  server.send(200, "text/html", sendHTML(true, led2Status));
}
void handle_led1off()
{
  led1Status = LOW;
  Serial.println("LED 1 Status: OFF");
  server.send(200, "text/html", sendHTML(false, led2Status));
}
void handle_led2on()
{
  led2Status = HIGH;
  Serial.println("LED 2 Status: ON");
  server.send(200, "text/html", sendHTML(led1Status, true));
}
void handle_led2off()
{
  led2Status = LOW;
  Serial.println("LED 2 Status: OFF");
  server.send(200, "text/html", sendHTML(led1Status, false));
}
void handle_onnotfound()
{
  server.send(404, "text/plain", "Server On Not Found");
}
String sendHTML(bool led1Status, bool led2Status)
{
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>LED Control</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr +=".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr +=".button-on {background-color: #3498db;}\n";
  ptr +=".button-on:active {background-color: #2980b9;}\n";
  ptr +=".button-off {background-color: #34495e;}\n";
  ptr +=".button-off:active {background-color: #2c3e50;}\n";
  ptr +="p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<h1>ESP32 Web Server</h1>\n";
  ptr +="<h3>AP Mode</h3>\n";
  if(led1Status)  ptr +="<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  else          ptr +="<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
  if(led2Status)  ptr +="<p>LED2 Status: ON</p><a class=\"button button-off\" href=\"/led2off\">OFF</a>\n";
  else          ptr +="<p>LED2 Status: OFF</p><a class=\"button button-on\" href=\"/led2on\">ON</a>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}