

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.ino
  * @brief          : Main program body
  ******************************************************************************
**/
/* USER CODE END Header */

#include "Include\main_inc.h"

/************************* WiFi Access Point *********************************/

#define WLAN_SSID       "FPT"

#define WLAN_PASS       "hpfd23115"

/************************* SERVER Broker config *********************************/

const char *MQTT_SERVER = "tailor.cloudmqtt.com" ;

const uint16_t MQTT_SERVERPORT = 28989 ;

const char *USERNAME = "jwactjqv";

const char *PASSWORD = "zM6h5Iiaa2bI";

const char * CID = "ESP8266-client-id-12345";

#define fingerprint  "39 DF B6 55 54 1D A4 53 12 70 65 DC 43 11 53 DA 3B A3 6E A8"

#define DEST_TOPIC    "ESP8266/test"

#define FLESPI_TOKEN  "FlespiToken REPLACE_WITH_YOUR_FLESPI_TOKEN"

/*********************** Client config  ******************/

// WiFiFlientSecure for SSL/TLS support
WiFiClientSecure client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt ( &client , MQTT_SERVER , MQTT_SERVERPORT , CID , USERNAME,  PASSWORD );

/****************************** Feeds ***************************************/

// Setup a feed called 'test' for publishing.

// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname>

Adafruit_MQTT_Publish test = Adafruit_MQTT_Publish( &mqtt, USERNAME , 0 );

/****************************** Function ***************************************/

void MQTT_connect() 
{
   mqtt.connected() ? 
    Serial.println ("/ MQTT connected ") : 
    Serial.println ("/ MQTT not connected ") ;

  unsigned char ret;
  unsigned char retries = 3;

  while ((ret = mqtt.connect()) != 0) 
  { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) 
    {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }

}

/****************************** SETUP ***************************************/

void setup()  
{
  /* Function Config_Wifi */

  Config_Wifi (WLAN_SSID , WLAN_PASS);

  /*----------------------*/

  client.setFingerprint(fingerprint) ? 
    Serial.println("/ Finger ok") : 
    Serial.println("/ Finger not ok") ;
}
/****************************** LOOP ***************************************/

uint32_t x = 0;

void loop() 
{
  MQTT_connect();

  // Now we can publish stuff!

  Serial.print(x);

  Serial.print(" to test feed...");

  if (! test.publish(x++))  {
    Serial.println(" > Failed");
  } else {
    Serial.println(" > OK!");
  }
 
  // wait a couple seconds to avoid rate limit
  delay(2000);

}

/****************************** END ***************************************/
