/*
    tinymqtt sketch with httpsserver lib(modified)
*/
#include "TinyMqtt.h"   // https://github.com/hsaturn/TinyMqtt
// Include certificate data (see note above)
#include "cert.h"
#include "private_key.h"


// We will use wifi
#include <WiFi.h>

// Includes for the server
// Note: We include HTTPServer and HTTPSServer
#include <SSLCert.hpp>

// The HTTPS Server comes in a separate namespace. For easier use, include it here.
using namespace httpsserver;

// Create an SSL certificate object from the files included above
SSLCert cert = SSLCert(
                 example_crt_DER, example_crt_DER_len,
                 example_key_DER, example_key_DER_len
               );

// First, we create the HTTPSServer with the certificate created above
//HTTPServer secureServer = HTTPServer();

#define PORT 8883
MqttBroker broker(&cert, PORT);

/** Basic Mqtt Broker with TLS

     +-----------------------------+
     | ESP                         |
     |       +--------+            |
     |       | broker |            | 8883 <--- External client/s
     |       +--------+            |
     |                             |
     +-----------------------------+

     Your ESP will become a MqttBroker.
     You can test it with any client such as mqtt-spy for example

*/

const char* ssid = "";
const char* password = "";


void setup()
{
  Serial.begin(115200);

  if (strlen(ssid) == 0)
    Serial << "****** PLEASE MODIFY ssid/password *************" << endl;

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    Serial << '.';
    delay(500);
  }
  Serial << "Connected to " << ssid << "IP address: " << WiFi.localIP() << endl;

  broker.begin();
  Serial << "Broker ready : " << WiFi.localIP() << " on port " << PORT << endl;
}

void loop()
{
  broker.loop();
}
