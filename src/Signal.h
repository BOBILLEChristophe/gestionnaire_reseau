/*


*/

#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include <Arduino.h>


class Signal {
  private :
    uint8_t   id;
    uint8_t   etat;
  public:
    Signal();             // constructor
    static uint8_t compt;
    void setId(uint8_t);
    void setEtat(uint8_t);
};



#endif