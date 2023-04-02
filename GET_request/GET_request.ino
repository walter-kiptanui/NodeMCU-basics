/*Sending GET request to server
Example */

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include<ESP8266HTTPClient.h>
const char* wifiPass = "Wi-Fi-password";
const char* wifiName = "Wi-Fi-name";

const char *host = "http://httpbin.org/get";   //web server address to read/write from

void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(wifiName);
  WiFi.begin(wifiName, wifiPass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("."); 
    }
  Serial.println("");
  Serial.println("Wi-Fi connected");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP()); //You can get IP address assigned to ESP
}

void loop() {
HTTPClient http; //Declare object of class HTTPClient
String ADCData = String(analogRead(A0));
String getData, Link; //GET Data //Note "?" added at front and "&" is used after each new parameter as per GET format 
getData = "?data=" + ADCData + "&sensor=temperature";
Link = host + getData;
Serial.print("Request Link:");
Serial.println(Link);
http.begin(WiFiClient, Link); //Specify request destination
int httpCode = http.GET(); //Send the request 
String payload = http.getString(); //Get the response payload from server 
Serial.print("Response Code:"); //200 is OK
Serial.println(httpCode); //Print HTTP return code 
Serial.print("Returned data from Server:");
Serial.println(payload); //Print request response payload
http.end(); //Close connection
delay(5000); //GET Data at every 5 seconds }


  }
