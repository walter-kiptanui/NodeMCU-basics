#include <ESP8266WiFi.h>
const char* ssid = "AndroidAP_9613w";
const char* password = "00000000";

//int ledPin = 2;

void setup() {
pinMode(LED_BUILTIN, OUTPUT);
digitalWrite(LED_BUILTIN, HIGH);

Serial.begin(115200);
Serial.println();
Serial.print("WiFi connecting to:");
Serial.println(ssid);

WiFi.begin(ssid, password);

Serial.println();
Serial.print("Connecting:");

while(WiFi.status() != WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}

digitalWrite(LED_BUILTIN, HIGH);
Serial.println();

Serial.println("Wifi connecting success!");
Serial.print("NodeMCU IP ADDRESS: ");
Serial.println(WiFi.localIP());


}

void loop() {
  // put your main code here, to run repeatedly:

}
