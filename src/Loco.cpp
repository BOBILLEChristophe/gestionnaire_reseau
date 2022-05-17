#include "Loco.h"

uint8_t Loco::compt = 0;

// Constructor
Loco::Loco() :
  id(compt++),
  adresse(0)
{};

uint16_t Loco::getId() const {
  return id;
}

uint16_t Loco::getAdresse() const {
  return adresse;
}