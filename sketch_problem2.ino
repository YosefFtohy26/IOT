#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

WebServer server(80);

#define LED1 26
#define LED2 27

void handleRoot() {
  String html = "<!DOCTYPE html><html>";
  html += "<head><meta charset='UTF-8'><title>ESP32 LED Control</title></head>";
  html += "<body style='text-align:center;'>";
  html += "<h1>ESP32 LED Web Server</h1>";
  html += "<p><a href='/led1/on'><button>Turn ON LED 1</button></a>";
  html += "<a href='/led1/off'><button>Turn OFF LED 1</button></a></p>";
  html += "<p><a href='/led2/on'><button>Turn ON LED 2</button></a>";
  html += "<a href='/led2/off'><button>Turn OFF LED 2</button></a></p>";
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void handleLED1On() { digitalWrite(LED1, HIGH); handleRoot(); }
void handleLED1Off() { digitalWrite(LED1, LOW); handleRoot(); }
void handleLED2On() { digitalWrite(LED2, HIGH); handleRoot(); }
void handleLED2Off() { digitalWrite(LED2, LOW); handleRoot(); }

void setup() {
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  server.on("/", handleRoot);
  server.on("/led1/on", handleLED1On);
  server.on("/led1/off", handleLED1Off);
  server.on("/led2/on", handleLED2On);
  server.on("/led2/off", handleLED2Off);
  
  server.begin();
  Serial.println("HTTP server started");
  Serial.print("ESP32 IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  server.handleClient();
}
