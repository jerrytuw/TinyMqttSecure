# TinyMqttSecure
ESP32/Arduino sketch to combine TinyMqtt broker code with ESPHTTPSServer code for a simple MQTT broker with TLS.

Modified TinyMqtt code to make use of HTTPSConnection instead of WiFiClient.
   Essential function:
    Sketch for simple MQTTS broker allowing connection of several clients via e.e. port 8883 with TLS.
Provided as is.
