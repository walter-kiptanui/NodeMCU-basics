#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h> 
const char* wifiName = "AndroidAP_9613w";
const char* wifiPass = "00000000"; 

//Web Server address to read/write from 
const char* host = "http://httpbin.org/post";

void setup() {
Serial.begin(115200);
delay(10);
Serial.println();
Serial.print("Connecting to");
Serial.println(wifiName);
WiFi.begin(wifiName, wifiPass);
while(WiFi.status() != WL_CONNECTED) 
{
  delay(500);
}
Serial.print(".");
Serial.println("");
Serial.println("Wi-Fi connected");
Serial.println("IP address:");
Serial.println(WiFi.localIP()); //You can get IP address assigned to ESP
}


void loop() {
WiFiClient client;
HTTPClient http; //Declare object of class HTTPClient 
String ADCData = String(analogRead(A0));
String postData; //POST Data
postData = "data=" + ADCData + "&sensor=temperature";
Serial.print("Post Data:");
Serial.println(postData);
http.begin(client,host); //Specify request destination 
http.addHeader("Content-Type", "application/x-www-formurlencoded"); //Specify content-type header 
int httpCode = http.POST(postData); //Send the request 
String payload = http.getString();//Get the response payload 
Serial.print("Response Code:"); //200 is OK
Serial.println(httpCode); //Print HTTP return code
Serial.print("Returned datafrom Server:");
Serial.println(payload); //Print request response payload
http.end(); //Close connection 
delay(5000); //POST Data at every 5 seconds
}
