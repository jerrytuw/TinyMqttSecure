# TinyMqttSecure
ESP32/Arduino sketch to combine TinyMqtt broker code with ESP32_HTTPS_Server code for a simple MQTT broker with TLS.

Based on TinyMqtt https://github.com/hsaturn/TinyMqtt and ESP32_HTTPS_Server https://github.com/fhessel/esp32_https_server libraries.

Just for my application needs I modified TinyMqtt code and combined it with (currently) slightly adapted HTTPSServer and HTTPConnection codes from the ESP32_HTTPS_Server library to make use of HTTPSConnection instead of WiFiClient on the transport level. It works, but would need some code beautifying...

   Essential function tested:
    Sketch for simple MQTTS broker allowing communication of several MQTTS clients via e.g. port 8883 with TLS.

## Provided as is.
