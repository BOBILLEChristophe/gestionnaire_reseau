/*
 * 
 * 
 */

#ifndef __CONFIG_H__
#define __CONFIG_H__

#define DEBUG


#define NB_ZONES 5
#define NB_LOCOS 24

enum { VOIE_LIBRE, AVERTISSEMENT, SEMAPHORE, CARRE, CARRE_RAPPEL_RALENTISSEMENT, SEMAPHORE_RALENTISSEMENT };
enum { HORAIRE, ANTI_HORAIRE };

// CAN
//#define CAN_BITRATE 1000UL * 1000UL // 1 Mb/s
const uint32_t CAN_BITRATE = 1000UL * 1000UL;



/* ----- Wifi --------------------*/

#define CONFIG 2 // Selection du mode

#if CONFIG == 0 // WiFi en mode point d’accès
#define WIFI_AP_MODE
#define WIFI_SSID "digital"
#define WIFI_PSW "digital" // Password facultatif

#elif CONFIG == 1
#define WIFI_SSID "xxxxxxxxxx"
#define WIFI_PSW  "xxxxxxxxxx"

#elif CONFIG == 2
#define WIFI_SSID "Olivier's"
#define WIFI_PSW  "songbird.enjoy.bedside.made"

//const char ssid[] = "Olivier's"; // your SSID
//const char pass[] = "songbird.enjoy.bedside.made"; // your SSID Password

#endif

#define MDNS_NAME              "gestionnaire"


#define OTAName                "gestionnaire"
#define OTAPassword            "gestionnaire"


#endif