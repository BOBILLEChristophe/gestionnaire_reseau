/*
   WiFi.cpp

   Part of project for ESP32 Digital Training

   Ce code sert à creer la connexion avec la box et donner une adresse DNS à la carte sur le reseau

*/

#include "Wifi_fl.h"

void Fl_Wifi::start()
{

#ifdef WIFI_AP_MODE
    WiFi.softAP(WIFI_SSID, WIFI_PSW);

#ifdef DEBUG
    Serial.print("\n");
    Serial.print("\nConnected to : ");
    Serial.print(WIFI_SSID);
    Serial.print("\nIP address :   ");
    Serial.print(WiFi.softAPIP());
    Serial.print("\n\n");
#endif

#else
    WiFi.begin(WIFI_SSID, WIFI_PSW);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

//#ifdef DEBUG
    Serial.print("\n");
    Serial.print("\nConnected to : ");
    Serial.print(WIFI_SSID);
    Serial.print("\nIP address :   ");
    Serial.print(WiFi.localIP());
    Serial.print("\n\n");
//#endif
#endif

    if (!MDNS.begin(MDNS_NAME))
    {
        Serial.print("Error setting up MDNS responder!\n");
        while (1)
            delay(1000);
    }

//#ifdef DEBUG
    Serial.print("MDNS responder started @ http://");
    Serial.print(MDNS_NAME);
    Serial.print(".local");
    Serial.print("\n\n");
//#endif
}
