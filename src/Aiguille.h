/*


*/

#ifndef __AIGUILLE_H__
#define __AIGUILLE_H__

#include <Arduino.h>
#include "Zone.h"


class Aiguille {
  public:
    Aiguille();             // constructor
    static uint8_t compt;
    void setId(uint8_t);
    void setOccupe(bool);
    void connexions(Zone*, Zone*, Zone*);
    
  private :
    uint8_t  id;
    bool     droite;
    Zone     *zoneTalon;
    Zone     *zonePiedDroit;
    Zone     *zonePiedDevie;
};


#endif