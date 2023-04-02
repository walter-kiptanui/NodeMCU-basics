#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include<ESP8266mDNS.h>
const char* wifiName = "AndroidAP_9613w";
const char*wifiPass = "00000000";


ESP8266WebServer server(80); //Define server object

const char htmlPage[] PROGMEM = R"=====(
<HTML> <HEAD> <TITLE>POST Request Demo</TITLE> </HEAD>
<BODY> <CENTER> <B>LED Status=@@LEDState@@</B> </CENTER>
<FORM method="POST" action="/"> <BUTTON name="LED"
value="1">ON</BUTTON> <BUTTON name="LED"
value="0">OFF</BUTTON> </FORM> <marquee
behavior="alternate">NodeMCU ESP8266 Communication Methods and
Protocols</marquee> </BODY> </HTML> )=====";                     //Handles http request


void handleRoot() {
String LEDstate, webPage;
webPage = htmlPage;
LEDstate = server.arg("LED"); //Using this we can read arguments passed in a link
Serial.print("Argument Received:");
Serial.println(LEDstate);
if(LEDstate=="1") {
digitalWrite(2, 0); //Turn on LED
webPage.replace("@@LEDState@@","ON"); //Replace string in web page to show current status }
if(LEDstate=="0") {
digitalWrite(2, 1); //Turn off LED
webPage.replace("@@LEDState@@","OFF"); //Replace string in web page to show current status }
server.send(200, "text/html", webPage); 
}
}
}


// the setup function runs once when you press reset or power the board void
void setup() {
Serial.begin(115200);
delay(10);
pinMode(2,OUTPUT);
Serial.println();
Serial.print("Connecting");
WiFi.begin(wifiName, wifiPass); //Connect to WiFi
while (WiFi.status() != WL_CONNECTED)
{
  delay(500);
}
Serial.print("."); 
Serial.println("");
Serial.println("Wi-Fi connected");
Serial.println("IP address:"); 
Serial.println(WiFi.localIP()); //You can get IP address assigned to ESP
server.on("/", handleRoot); //Associate handler function to web requests
server.begin(); //Start web server
Serial.println("HTTP server started");
}

void loop() {
//Handle Clinet requests server.handleClient();
}
