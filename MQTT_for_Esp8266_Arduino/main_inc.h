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
#include <stdint.h>

#include <Adafruit_MQTT_Client.h>
#include <Adafruit_MQTT.h>

#define s Serial
#define s_p	Serial.print
#define s_pf Serial.printf
#define s_pln Serial.println

void Function_Config_Wifi(const char *ID ,const char *PASS);

#endif
/****END OF FILE****/
