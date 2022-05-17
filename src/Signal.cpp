



#include "Signal.h"



uint8_t Signal::compt = 0;

Signal::Signal():
  id(compt++),
  etat(0)
{};


void Signal::setId(uint8_t id) {
  this->id = id;
}

void Signal::setEtat(uint8_t etat) {
  this->etat = etat;
}