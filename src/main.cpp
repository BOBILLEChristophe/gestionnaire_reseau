

// varEtat : bit8 -> sens de roulage horaire = 1 / anti-horaire 0
// varEtat : bit7 -> aiguille = 1 sinon = 0
// varEtat : bit6 -> aiguilleHoraire = 1 sinon = 0
// varEtat : bit5 -> aiguilleTalon = 1 aiguillePointe = 0
// varEtat : bit4 -> aiguillePointeDeviee = 1 aiguillePointeDroite = 0
// varEtat : bit3 -> aiguilleDeviee = 1 aiguilleDroite = 0
// varEtat : bit2 -> z+2 occupe = 1 / libre = 0
// varEtat : bit1 -> z+1 occupe = 1 / libre = 0
// varEtat : bit0 -> occupe = 1 / libre = 0

#include <Arduino.h>
#include "Aiguille.h"
#include "Can.h"
#include "Config.h"
#include "Loco.h"
#include "Settings.h"
#include "Signal.h"
#include "WebHandler.h"
#include "Wifi_fl.h"
#include "Zone.h"

Aiguille aig[2];
Zone zone[NB_ZONES]; // Tableau des zones créées
Signal sign[NB_ZONES * 2];
Loco loco[NB_LOCOS]; // Tableau des locomotives
CanMsg canMsg;

/*----Lecture et écriture des paramètres sur SPIFFS ----*/
// Settings settings;

/*---- Wifi, serveurs web et web sockets ----*/
// Instances de Wifi et serveurs
Fl_Wifi wifi;
WebHandler webHandler;

void setup()
{

  Serial.begin(115200);
  delay(1000);

  //  byte compt;
  //  compt = 0;
  //  for (auto el : aig) {
  //    el.setId(compt);
  //    compt++;
  //  }
  //  compt = 0;
  //  for (auto el : sign) {
  //    el.setId(compt);
  //    compt++;
  //  }
  //
  // Un id pour chaque objet
  for (byte i = 0; i < NB_ZONES; i++)
  {
    // zone[i].setId(i);
    Serial.println(zone[i].getId());
  }

  //
  // for (byte i = 0; i < NB_ZONES; i++)
  //   zone[i].setup(i, zone);

  // aig[0].connexions(&zone[1], &zone[5], &zone[4]);

  // for (byte i = 0; i < NB_ZONES; i++)
  //   zone[i].setAiguille(&zone[4]);

  // for (auto el : loco)
  //   Serial.printf("ID %d adresse : %d\n", el.getId(), el.getAdresse());

  CanBus::setup(CAN_BITRATE);

  /*-----------------------------------------------------
  WiFi, serveurs, OTA et timer
  ----------------------------------------------------- */

  wifi.start();
  webHandler.init(80);
  // OTA::begin();

  /*-----------------------------------------------------
     Lecture et écriture des settings
   ----------------------------------------------------- */

  // settings.begin();

  /*-----------------------------------------------------
  Lecture du fichier json externe pour charger les paramètres
  ----------------------------------------------------- */

  Settings::init(zone);
  for (byte i = 0; i < NB_ZONES; i++)
    zone[i].setup(i, zone);
  // varEtatMachine = param.etatMachine;
}

void loop()
{

  webHandler.loop();

  // canMsg.receive();
  // canMsg.send();

  for (auto el : zone)
    el.loop();

  // Message zone 3 occupée
  // Message type envoyé par le capteur d'occupation de la zone

  zone[3].setSens(ANTI_HORAIRE);
  zone[3].setOccupe(true);
  // zone[4].setOccupe(true);
  //  Message zone 3 occupée par la locomotive id = 22
  //  Il y a 2 possibilités :
  //  1° - Un seul capteur d'occupation est actif et la lecture DCC renvoie une adresse

  // Exemple, zone[3] occupée par la loco id = 23
  // zone[3].setLoco(&loco[23]);

  delay(1000);
}