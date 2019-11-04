/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.ino file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H_
#define __MAIN_H_

#include <ESP8266WiFi.h>
#include <Adafruit_MQTT_Client.h>
#include <Adafruit_MQTT.h>
#include <stdint.h>

/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------*/


void Config_Wifi (const char *ID , const char *PASS )
{
  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ID, PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.'); delay(500);
  }

  Serial.print("Connected! IP address: \n");
  Serial.println(WiFi.localIP());

}

#endif

/****END OF FILE****/
