

#include "Settings.h"

void Settings::begin()
{
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  else
    Serial.println("Ok mounting SPIFFS");
}

void Settings::init(Zone *zone)
{
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  File file = SPIFFS.open("/settings.jso", "r");
  if (!file)
  {
#ifdef DEBUG // File not found | le fichier settings.jso n'existe pas
    Serial.println("Failed to open settings.jso");
#endif
    return;
  }
  else
  {
#ifdef DEBUG
    Serial.printf("Informations du fichier \"settings.jso\" : \n");
#endif
    StaticJsonDocument<2048> doc;
    DeserializationError error = deserializeJson(doc, file);
    if (error)
      Serial.println(F("Failed to read file, using default configuration"));
    else
      Serial.println(F("OK to read file, using default configuration"));

    JsonArray array = doc.as<JsonArray>();
    for (uint8_t i = 0; i < NB_ZONES; i++)
    {
      zone[i].setZone(0, zone[(int)array[i]["zhdr"]]);
      zone[i].setZone(1, zone[(int)array[i]["zadr"]]);
      zone[i].setZone(2, zone[(int)array[i]["zhdv"]]);
      zone[i].setZone(3, zone[(int)array[i]["zadv"]]);
      zone[i].setZone(4, zone[(int)array[i]["ah"]]);
      zone[i].setZone(5, zone[(int)array[i]["aa"]]);
      zone[i].setSens((bool)array[i]["sens"]);
    }

#ifdef DEBUG
    Serial.printf("file.close()\n");
#endif
    file.close();
  }
}

void Settings::writeFile()
{
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  File file = SPIFFS.open("/param.jso", "w");
  if (!file)
  {
    // File not found | le fichier n'existe pas
    Serial.println("Failed to open param.jso");
    return;
  }
  else
  {
    //    #ifdef DEBUG
    //        Serial.printf("Numéro de série :   %s\n", Param::numSerie);
    //        Serial.printf("Client :            %s\n", Param::client);
    //        Serial.printf("Date de validité :  %s\n", Param::dateValidite);
    //        Serial.printf("Numéro de version : %s\n", Param::numVersion);
    //        Serial.printf("varEtatMachine 2 :    0x%x\n", Param::etatMachine);
    //    #endif
    // file.print("{");
    // file.print("\"numSerie\":\"");       file.print(Settings::numSerie);       file.print("\",");
    // file.print("\"client\":\"");         file.print(Settings::client);         file.print("\",");
    // file.print("\"dateValidite\":\"");   file.print(Settings::dateValidite);   file.print("\",");
    // file.print("\"numVersion\":\"");     file.print(Settings::numVersion);     file.print("\",");
    // file.print("\"varEtatMachine\":");   file.print(Settings::etatMachine);
    // file.print("}");

    file.close();
  }
}
