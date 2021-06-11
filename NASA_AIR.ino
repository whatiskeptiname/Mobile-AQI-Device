#include <ESP8266WiFi.h> //library file for node mcu ESP8266
#include "7-seg.h"
#include "pollution.h"
#include "reg.h"

static const uint8_t D0   = 16; //pin decleration in node mcu
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D10  = 1;

const char* ssid = "Vision";      // ssid and password for conncetion to wifi
const char* password = "spaceapps";

WiFiServer server(80);


String prepareHtmlPage()   //html to display on browser
{
  String htmlPage =
    String("HTTP/1.1 200 OK\r\n") +
    "Content-Type: text/html\r\n" +
    "Connection: close\r\n" +  // the connection will be closed after completion of the response
    "Refresh: 1\r\n" +  // refresh the page automatically every 1 sec
    "\r\n" +
    "<!DOCTYPE HTML>" +
    "<html>" +
    "<body>" +
    String(dustDensity) +
    "</body>" +
    "</html>" +
    "\r\n";
  return htmlPage;
}

void setup()
{
  Serial.begin(115200);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, OUTPUT);
  define_segment_pins(D7, D6, D5, D4, D3, D2, D1, D0);
  int i = 0;

  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" connected");

  server.begin();
  Serial.printf("Web server started, open %s in a web browser\n", WiFi.localIP().toString().c_str());


}
void loop()
{
  WiFiClient client = server.available();
  // wait for a client (web browser) to connect
  if (client)
  {
    Serial.println("\n[Client connected]");
    while (client.connected())
    {
      // read line by line what the client (web browser) is requesting
      if (client.available())
      {
        String line = client.readStringUntil('\r');
        Serial.print(line);
        // wait for end of client's request, that is marked with an empty line
        if (line.length() == 1 && line[0] == '\n')
        {
          client.println(prepareHtmlPage());
          break;
        }
      }
    }
    delay(1); // give the web browser time to receive the data

    // close the connection:
    client.stop();
    Serial.println("[Client disonnected]");
  }
  s_read();
  s_calculate();
  next_data(dustDensity);
  s_print();
  dangerCheck();
  s_disp(num, 0);
  delay(1500);
  s_disp(n_num, 1);
  delay(1500);
}
