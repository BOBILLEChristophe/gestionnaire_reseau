/*
 * 
 * 
 */

#ifndef __LOCO_H__
#define __LOCO_H__

#include <Arduino.h>


class Loco {
  private :
    uint8_t   id;
    uint16_t  adresse;
    bool      sensRoulage;
  public:
    Loco();             // constructor
    static uint8_t compt;
    uint16_t getId() const;
    uint16_t getAdresse() const;
};


#endif