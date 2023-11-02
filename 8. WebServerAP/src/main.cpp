#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char *ssid = "ESP32-WebServer";
const char *pass = "123456789";
WebServer myserver(80);                   // Mac dinh cong default la 80 (HTTP port)

void handle_connect();
void handle_hello();

void setup()
{
  Serial.begin(1152000);
  WiFi.softAP(ssid, pass);
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  myserver.on("/", handle_connect);       // "/" và "/hello" đại diện cho đương link khi client gõ 
  myserver.on("/hello", handle_hello);
  myserver.begin();

}

void loop()
{
  myserver.handleClient();
}

String html = "<h1 style=\"text-align: center;\">ESP32 WEBSERVER</h1> <p style=\"text-align: center;\">Nguyen Do Hong Phuong</p> <p style=\"text-align: center;\">Learn ESP32</p>";

void handle_connect()
{
  Serial.println("HTTP Request");
  myserver.send(200, "text/html", html);    // 200 = OK 
                                            // 404 = Not Found
                                            // 500 = Internal Server Error
}

void handle_hello()
{
  Serial.println("HTTP Request");
  myserver.send(200, "text/plain", "Hello Phuong");
                                            //"text/html": Định dạng HTML cho nội dung là mã HTML.
                                            //"text/plain": Định dạng văn bản thô cho nội dung là chuỗi văn bản.
                                            //"image/jpeg": Định dạng JPEG cho nội dung là một hình ảnh.
}
