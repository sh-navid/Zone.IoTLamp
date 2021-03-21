#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
ESP8266WebServer server(80);

const int led = 13;
int lamps[2]={0,0};

void root() {
  String str = "";

  str += "<!DOCTYPE html>";
  str += "<html lang=\"en\">";
  str += "<head>";
  str += "    <meta charset=\"utf-8\" />";
  str += "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable = no\" />";
  str += "    <meta name=\"apple-mobile-web-app-capable\" content=\"yes\" />";
  str += "    <meta name=\"apple-mobile-web-app-status-bar-style\" content=\"black\" />";
  str += "    <meta name=\"format-detection\" content=\"telephone=no\" />";
  str += "    <meta name=\"theme-color\" content=\"#212121\">";
  str += "    <meta name=\"HandheldFriendly\" content=\"true\">";
  str += "    <meta name=\"msapplication-TileColor\" content=\"#212121\">";
  str += "    <style type=\"text/css\">";
  str += "        body {";
  str += "            margin: 0;";
  str += "            background-color: #212121;";
  str += "        }";
  str += "        #l1,#l2 {";
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
  str += "            text-decoration:none";
  str += "        }";
  str += "        #l2 {";
  str += "            background-color: hotpink;";
  str += "        }";
  str += "    </style>";
  str += "</head>";
  str += "<body>";
  str += "    <br/><br/><br/><br/><br/><br/>";
  str += "    <a id=\"l1\" href=\"/blue\"><a>";
  str += "    <br/><br/><br/>";
  str += "    <a id=\"l2\" href=\"/pink\"><a>";
  str += "</body>";
  str += "</html>";

  server.send(200, "text/html", str);
}

void lamp(int idx, int gpio) {
  lamps[idx] += 1;
  if (lamps[idx >= 2])
    lamps[idx] = 0;
  digitalWrite(gpio, lamps[idx]);
  root();
}

void setup(void) {
  pinMode(led, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D6, OUTPUT);
  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("NSH-Router", "!oTpa55!");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(WiFi.localIP());
  MDNS.begin("esp8266");

  server.on("/", root);

  server.on("/blue", []() {
    lamp(0, D4);
  });

  server.on("/pink", []() {
    lamp(1, D6);
  });

  server.begin();
  Serial.println("My Lamp Server Started");
}

void loop(void) {
  server.handleClient();
  MDNS.update();
}
