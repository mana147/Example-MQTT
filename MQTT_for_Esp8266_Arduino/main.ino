

/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.ino
  * @brief          : Main program body
  ******************************************************************************
**/
/* USER CODE END Header */

#include "Include\main_inc.h"

const char* ID = "FPT";
const char*  PASS =  "hpfd23115";

const int mqttPort = 37181;
const char* mqttServer = "m16.cloudmqtt.com";
const char* mqttUser = "otfxknod";
const char* mqttPassword = "nSuUc1dDLygF";


void setup() 
{
  /* Function Config_Wifi */
  Config_Wifi (ID , PASS);
  /*----------------------*/

  
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);
  
  while (!client.connected())  {
    Serial.println("Connecting to MQTT...");
    if (client.connect("ESP8266Client", mqttUser, mqttPassword )) {
      Serial.println("connected");  
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
 
  client.publish("esp/test", "hello"); //Topic name
  client.subscribe("esp/test");
 
}
 
void callback(char* topic, byte* payload, unsigned int length) 
{
 
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
 
  Serial.print("Message:");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  Serial.println("-----------------------");
 
}
 
void loop() 
{
  client.loop();
}
