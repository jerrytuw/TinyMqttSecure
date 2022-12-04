# TinyMqttSecure
ESP32/Arduino sketch to combine TinyMqtt broker code with ESP32_HTTPS_Server code for a simple MQTT broker with TLS.

Based on 
- TinyMqtt https://github.com/hsaturn/TinyMqtt and 
- ESP32_HTTPS_Server https://github.com/fhessel/esp32_https_server libraries.

Just for my application needs I modified TinyMqtt code and combined it with slightly adapted HTTPSServer and HTTPConnection codes from the ESP32_HTTPS_Server library to make use of HTTPSConnection instead of WiFiServer on the transport level. It works for me, but would need some code beautifying... TinyMqtt uses single byte chunks so the sketch is not speed optimised, also there may be hidden bugs.

   Essential function tested:
    Simple MQTTS broker allowing communication of several MQTTS clients via e.g. port 8883 with TLS. Clients used were MQTT Explorer, MQTT.fx and own sketches with PubSubClient+WiFiServerSecure.

Note for ESP32 Arduino core versions:
- 1.0.6: ESP32_HTTPS_Server library compiles as is
- 2.0.x: in HTTPConnection.hpp  after #include <mbedtls/base64.h>
 change to
 ```
#if ESP_IDF_VERSION >= ESP_IDF_VERSION_VAL (4, 4, 0)
  #include <sha/sha_parallel_engine.h>  
#else
  #include <hwcrypto/sha.h>
#endif
```
## Provided as is.
