#ifndef __SETTINGS__
#define __SETTINGS__

#include <Arduino.h>
#include <ArduinoJson.h>
#include <SPIFFS.h>
#include <FS.h>
#include "Config.h"
#include "Zone.h"

struct Settings {
  static void begin();
  static void init(Zone*);
  static void writeFile();
};

#endif
