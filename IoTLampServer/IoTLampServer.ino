#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
ESP8266WebServer server(80);

const int led = 13;

void root() {
  String str = "";

  str += "<!DOCTYPE html>";
  str += "<html lang=\"en\">";
  str += "<head>";
  str += "    <meta charset=\"utf-8\" />";
  str += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable = no\" />";
  str += "    <style type=\"text/css\">";
  str += "        body {";
  str += "            margin: 0;";
  str += "            background-color: #212121;";
  str += "        }";
  str += "        btn {";
  str += "            display: block;";
  str += "            user-select: none;";
  str += "            cursor: pointer;";
  str += "            text-align: center;";
  str += "            width: 3em;";
  str += "            height: 3em;";
  str += "            line-height: 3em;";
  str += "            border-radius: 10em;";
  str += "            background-color: royalblue;";
  str += "            color: white;";
  str += "            font-size: 200%;";
  str += "            margin: 0 auto;";
  str += "        }";
  str += "        btn:nth-child(2) {";
  str += "            background-color: hotpink;";
  str += "        }";
  str += "    </style>";
  str += "</head>";
  str += "<body>";
  str += "  <a href=\"/blue\"><btn>☀</btn><a>";
  str += "  <a href=\"/pink\"><btn>☀</btn><a>";
  str += "</body>";
  str += "</html>";

  server.send(200, "text/html", str);
}

void lamp(int i) {
  int k = digitalRead(i) + 1;
  if (k > 1)k = 0;
  digitalWrite(i, k);
  root();
}

void setup(void) {
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("Navid'sIoTServer", "!oTpa55");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  MDNS.begin("esp8266")

  server.on("/", root);

  server.on("/blue", []() {
    lamp(4);
  });

  server.on("/pink", []() {
    lamp(6);
  });

  server.begin();
  Serial.println("My Lamp Server Started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
