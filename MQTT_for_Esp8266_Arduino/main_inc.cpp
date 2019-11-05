#include "main_inc.h"

void Function_Config_Wifi(const char *ID ,const char *PASS)
{
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ID, PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".\n") ; delay(500);
  }

  Serial.print("Connected! IP address: \n");
  Serial.println(WiFi.localIP());
}