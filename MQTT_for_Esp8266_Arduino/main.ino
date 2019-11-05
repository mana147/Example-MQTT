/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.ino
  * @brief          : Main program body
  ******************************************************************************
**/
/* USER CODE END Header */
#include "main_inc.h"
/************************* WiFi Access Point ************************************/
#define WLAN_SSID             "FPT"
#define WLAN_PASS             "hpfd23115"
/************************* SERVER Broker config ********************************/
#define fingerprint           "39 DF B6 55 54 1D A4 53 12 70 65 DC 43 11 53 DA 3B A3 6E A8"
#define TOPIC                 "ESP8266/channel/1"
#define MQTT_SERVER           "tailor.cloudmqtt.com" 
#define USERNAME              "jwactjqv"
#define PASSWORD              "hICbkWqn0P5k"
#define CLIENT_ID             "ESP8266-client-id-12345"
#define MQTT_SERVERPORT        28989 
/************************** Config Function ************************************/
// WiFiFlientSecure for SSL/TLS support
WiFiClientSecure Client_SSL;
// Setup the MQTT client 
Adafruit_MQTT_Client MQTT_Client ( &Client_SSL , MQTT_SERVER ,  MQTT_SERVERPORT , CLIENT_ID , USERNAME,  PASSWORD );
// Setup for publishing.
Adafruit_MQTT_Publish MQTT_Publish (&MQTT_Client, TOPIC , 0x1 );
// Setup for subscribe
Adafruit_MQTT_Subscribe MQTT_Subscribe (&MQTT_Client, TOPIC , 0x1 );

Adafruit_MQTT_Subscribe *subscription;  

int numb = 0 ;

/**********************************************************************
***************************** SETUP ***********************************
***********************************************************************/

void setup()  
{
  Function_Config_Wifi (WLAN_SSID , WLAN_PASS );

  Client_SSL.setFingerprint(fingerprint) ? s_pln ("/ Finger ok") : s_pln ("/ Finger not ok") ;
  
  MQTT_Client.subscribe (&MQTT_Subscribe);
  
  MQTT_Client.connect() == 0 ? s_pln ("/ MQTT_Client connected ") : s_pln ("Error");
}

/***************************** LOOP *********************************/

void loop() 
{
  MQTT_Publish.publish(numb++);
  
  MQTT_Client.readSubscription(1000) ? Serial.println((char *)MQTT_Subscribe.lastread) : 0x01;

   // ping đến server để giữ cho kết nối luôn hoạt động 
   // nếu mất kết nối từ server sẽ tự động disconnect
  //if(! MQTT_Client.ping()) { MQTT_Client.disconnect(); }
}

/****************************** END ***************************************/
