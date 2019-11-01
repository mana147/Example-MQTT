

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.ino
  * @brief          : Main program body
  ******************************************************************************
**/
/* USER CODE END Header */

#include "Include\main_inc.h"

/*----------------------------------------------------------------------------*/

#define MQTT_SERVER      "mqtt.flespi.io"
#define MQTT_SERVERPORT  8883
#define FLESPI_CERT_FINGERPRINT "3B BC 95 33 E5 AB C1 1C C8 FC 37 57 F2 94 2C 43 8E 3B 66 F3"
#define DEST_TOPIC       "ESP8266/test"
#define FLESPI_TOKEN    "FlespiToken REPLACE_WITH_YOUR_FLESPI_TOKEN"

const char* ID = "FPT";
const char*  PASS =  "hpfd23115";

/********************* Global connection instances **************************/
// WiFiFlientSecure for SSL/TLS support
WiFiClientSecure client;
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_SERVERPORT, FLESPI_TOKEN, "");
// Setup a feed 'flespi' to publish messages to flespi MQTT broker.
Adafruit_MQTT_Publish flespi = Adafruit_MQTT_Publish(&mqtt, DEST_TOPIC);


void setup()  
{
  /* Function Config_Wifi */
  Config_Wifi (ID , PASS);
  /*----------------------*/

  // connect to server check the fingerprint of flespi.io's SSL cert (from Adafruit MQTTS example)
  verify_fingerprint(client);
}

void loop() 
{
  // code
}
