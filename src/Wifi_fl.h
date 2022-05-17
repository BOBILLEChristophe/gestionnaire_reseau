/*
   Wifi_fl.h

   Part of project for ESP32 Digital Training

*/


#ifndef __WIFI_FL_H__
#define __WIFI_FL_H__

#include <Arduino.h>
#include <WiFi.h>
#include <ESPmDNS.h>
#include "Config.h"


struct Fl_Wifi
{

    static void start();
};

#endif /* defined(__WIFI_FL_H__) */
