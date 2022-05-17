

#include "Zone.h"

uint8_t Zone::compt = 0;

// Constructor
Zone::Zone() : id(compt++),
               varEtat(0),
               occupe(false),
               sensRoulage(HORAIRE),
               signalH(CARRE), // Signal à horaire
               signalA(CARRE), // Signal à anti-horaire
               loco(nullptr),
               zhdr(nullptr), // Zone horaire droite
               zadr(nullptr), // Zone anti-horaire droite
               zhdv(nullptr), // Zone horaire déviée
               zadv(nullptr), // Zone anti-horaire déviée
               ah(nullptr),   // Aiguille à horaire
               aa(nullptr),   // Aiguille à anti-horaire
               ptrSignal(nullptr)
               {};

// Constructor
Zone::Zone(uint8_t id) : Zone()
{
  this->id = id;
};

// Donne un identifiant à la zone
void Zone::setId(uint8_t id)
{
  this->id = id;
}

uint8_t Zone::getId()
{
  return this->id;
}

void Zone::setup(uint8_t x, Zone *zone)
{
  if (x > 0 && x < NB_ZONES)
    this->zadr = &zone[x - 1];
  else // x == 0
    this->zadr = &zone[NB_ZONES - 1];

  if (x < NB_ZONES - 1)
    this->zhdr = &zone[x + 1];
  else // x == NB_ZONES
    this->zhdr = &zone[0];

  Serial.printf("zadr %d : %d\n", x, this->zadr->id);
  Serial.printf("zhdr %d : %d\n", x, this->zhdr->id);

  // Pour tests
  // aiguille : bit4 -> aiguille = 1 sinon = 0
  // aiguille : bit3 -> aiguilleHoraire = 1 sinon = 0
  // aiguille : bit2 -> aiguilleTalon = 1 aiguillePointe = 0
  // aiguille : bit1 -> aiguillePointeDeviee = 1 aiguillePointeDroite = 0
  // aiguille : bit0 -> aiguilleDeviee = 1 aiguilleDroite = 0
  // if (x == 6)
  //   this->aiguille = B11100;
}

void Zone::setZone(uint8_t x, Zone zone)
{
  // Serial.println(zone.id);
  switch (x)
  {
  case (0):
    this->zhdr = &zone; // Zone "Horaire droit"
    break;
  case (1):
    this->zadr = &zone; // Zone "antiHoraire droit"
    break;
  case (2):
    this->zhdv = &zone; // Zone "Horaire dévié"
    break;
  case (3):
    this->zadv = &zone; // Zone "antiHoraire dévié"
    break;
  case (4):
    this->ah = &zone; // Aiguille à horaire
    break;
  case (5):
    this->aa = &zone; // Aiguille à anti-horaire
    break;
  }
}

// Indique le sens de roulage
void Zone::setSens(bool sens)
{
  this->sensRoulage = sens;
  // this->zadr->sensRoulage = sens;
  // this->zadr->zadr->sensRoulage = sens;
  // this->zhdr->sensRoulage = sens;
  // this->zhdr->zhdr->sensRoulage = sens;
}

// Identifie la loco qui occupe dans la zone
void Zone::setLoco(Loco *loco)
{
  this->loco = loco;
}

void Zone::setOccupe(bool occupe)
{
  // Serial.printf("This zone[%d] occupée",this->id);
  this->occupe = occupe;
}

void Zone::setAiguille(Zone *z)
{
  if (this->zhdr == z)
  {
    Serial.println(this->zhdr->id);
    Serial.println("ok aiguille0 zhdr");
  }

  if (this->zadr == z)
  {
    Serial.println(this->zadr->id);
    Serial.println("ok aiguille0 zadr");
  }

  if (this->zhdv == z)
  {
    Serial.println(this->zhdv->id);
    Serial.println("ok aiguille1 zhdv");
  }
  if (this->zadv == z)
  {
    Serial.println(this->zadv->id);
    Serial.println("ok aiguille1 zadv");
  }
}

void Zone::loop()
{
  varEtat = 0;
  // Etat occupation
  varEtat |= (this->occupe << 0);
  // Sens de roulage
  varEtat |= (this->sensRoulage << 8);
  if (varEtat & 0x100)
  { // Sens de roulage anti-horaire
    varEtat |= (this->zadr->occupe << 1);
    varEtat |= (this->zadr->zadr->occupe << 2);
    ptrSignal = &signalA;
    Serial.println("Sens de roulage anti-horaire");
  }
  else
  { // Sens de roulage horaire
    varEtat |= (this->zhdr->occupe << 1);
    varEtat |= (this->zhdr->zhdr->occupe << 2);
    ptrSignal = &signalH;
    Serial.println("Sens de roulage horaire");
  }

  // Il y a une aiguille
  // L'aiguille est à talon

  // Aiguille
  // if (varEtat & B10000000)
  // { // Aiguille bit 7 == 1
  //   if (varEtat & B01000000)
  //   { // Aiguille à position horaire (bit 7 == 1) et sens de roulage horaire
  //     switch (varEtat & B00100000)
  //     {
  //     case 1: // L'aiguille est à talon bit 5 == 1
  //       switch (varEtat & B00001000)
  //       {
  //       case 0: // L'aiguille est droite bit 3 == 0
  //         signal = VOIE_LIBRE;
  //         break;
  //       case 1: // L'aiguille est déviée bit 3 == 1
  //         signal = CARRE;
  //         break;
  //       }
  //     case 0: // L'aiguille est à pointe  bit 5 == 0
  //       switch (varEtat & B00010000)
  //       {
  //       case 0: // L'aiguille est à pointe droite  bit 4 == 0
  //         switch (varEtat & B00001000)
  //         {
  //         case 0: // L'aiguille est droite bit 3 == 0
  //           signal = VOIE_LIBRE;
  //           break;
  //         case 1: // L'aiguille est déviée bit 3 == 1
  //           signal = CARRE;
  //           break;
  //         }
  //         break;
  //       case 1: // L'aiguille est à pointe déviée  bit 4 == 1
  //         switch (varEtat & B00001000)
  //         {
  //         case 0: // L'aiguille est droite bit 3 == 0
  //           signal = CARRE;
  //           break;
  //         case 1: // L'aiguille est déviée bit 3 == 1
  //           signal = VOIE_LIBRE;
  //           break;
  //         }
  //         break;
  //       }
  //     }
  //   } // End if
  // }
  // else
  // { // Il n'y a pas d'aiguille dans la zone
  // Signalisation

  // Serial.println(varEtat, BIN);
  switch (varEtat & B110)
  {
  case B000:
    *ptrSignal = VOIE_LIBRE;
    Serial.printf("Signal zone %d : VOIE_LIBRE \n", id);
    break;
  case B100:
    *ptrSignal = AVERTISSEMENT;
    // Ralentissement
    Serial.printf("Signal %d : AVERTISSEMENT \n", id);
    break;
  default:
    *ptrSignal = SEMAPHORE;
    // Arret
    Serial.printf("Signal %d : SEMAPHORE \n", id);
  }
  //}
}
