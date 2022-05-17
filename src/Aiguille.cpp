

#include "Aiguille.h"

uint8_t Aiguille::compt = 0;

Aiguille::Aiguille() : id(compt++),
                       zoneTalon(nullptr),
                       zonePiedDroit(nullptr),
                       zonePiedDevie(nullptr){};

void Aiguille::setId(uint8_t id)
{
  this->id = id;
}

void Aiguille::connexions(Zone *zoneTalon, Zone *zonePiedDroit, Zone *zonePiedDevie)
{
  this->zoneTalon = zoneTalon;
  this->zonePiedDroit = zonePiedDroit;
  this->zonePiedDevie = zonePiedDevie;
}