#include "UbidotsEsp32Mqtt.h"
//#include <ESP8266WiFi.h>

int digital = 0;


#define TOKEN "BBFF-HBxFRtojL1FEay48h25B0IIlfyQ3RV"
#define WIFISSID ""
#define PASSWORD ""

const char *UBIDOTS_TOKEN = "BBFF-HBxFRtojL1FEay48h25B0IIlfyQ3RV";  // Put here your Ubidots TOKEN
const char *WIFI_SSID = "ONEPLUS";      // Put here your Wi-Fi SSID
const char *WIFI_PASS = "ONEPLUS123";      // Put here your Wi-Fi password
const char *DEVICE_LABEL = "ESP32";   // Put here your Device label to which data  will be published
const char *VARIABLE_LABEL = "gas";// Put here your Variable label to which data  will be published


unsigned long timer;
uint8_t Sensor_input = 12;
const int PUBLISH_FREQUENCY = 1000; // Update rate in milliseconds


Ubidots ubidots(UBIDOTS_TOKEN);

void callback(char *topic, byte *payload, unsigned int length){
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}




void setup(){
  // put your setup code here, to run once:
  Serial.begin(115200);
  // ubidots.setDebug(true);  // uncomment this to make debug messages available
  ubidots.connectToWifi(WIFI_SSID, WIFI_PASS);
  ubidots.setCallback(callback);
  ubidots.setup();
  ubidots.reconnect();

  timer = millis();
}

void loop(){
  // put your main code here, to run repeatedly:
  if (!ubidots.connected())
  {
    ubidots.reconnect();
  }
  if ((millis() - timer) > PUBLISH_FREQUENCY) // triggers the routine every 5 seconds
  {
    float sensor_Aout = analogRead(Sensor_input);
    ubidots.add(VARIABLE_LABEL, sensor_Aout);// Insert your variable Labels and the value to be sent
    ubidots.publish(DEVICE_LABEL);

    timer = millis();
    
  Serial.print(sensor_Aout);

  }


  ubidots.loop();

}
