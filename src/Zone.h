/*


*/

#ifndef __ZONE_H__
#define __ZONE_H__

#include <Arduino.h>
#include "Config.h"
#include "Loco.h"
#include "Signal.h"

class Zone
{
private:
  uint8_t id;
  uint16_t varEtat;
  bool occupe;
  bool sensRoulage;
  uint8_t signalH; // Signal à horaire
  uint8_t signalA; // Signal à anti-horaire
  Loco *loco;
  Zone *zhdr;    // Zone "Horaire droit"
  Zone *zadr;    // Zone "antiHoraire droit"
  Zone *zhdv;    // Zone "Horaire dévié"
  Zone *zadv;    // Zone "antiHoraire dévié"
  Zone *ah;      // Aiguille à horaire
  Zone *aa;      // Aiguille à anti-horaire
  uint8_t *ptrSignal;
public:
  Zone();        // constructor
  Zone(uint8_t); // constructor
  static uint8_t compt;
  void setId(uint8_t);
  uint8_t getId();
  void setZone(uint8_t, Zone);
  void setSens(bool);
  void setup(uint8_t, Zone *);
  void loop();
  void setLoco(Loco *);
  void setOccupe(bool);
  void setAiguille(Zone *);
};

#endif