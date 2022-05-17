/*
   CanMsg.h

*/

#ifndef __CAN_MSG_H__
#define __CAN_MSG_H__

#include <Arduino.h>
#include <ACAN_ESP32.h>

class CanMsg : public CANMessage {
  private :
    //    uint32_t id;      // Frame identifier
    //    bool     ext = false; // false -> standard frame, true -> extended frame
    //    bool     rtr = false; // false -> data frame, true -> remote frame
    //    uint8_t  idx = 0;     // This field is used by the driver
    //    uint8_t  len = 0;     // Length of data (0 ... 8)
    //    union {
    //      uint64_t data64        ; // Caution: subject to endianness
    //      int64_t  data_s64      ; // Caution: subject to endianness
    //      uint32_t data32    [2] ; // Caution: subject to endianness
    //      int32_t  data_s32  [2] ; // Caution: subject to endianness
    //      float    dataFloat [2] ; // Caution: subject to endianness
    //      uint16_t data16    [4] ; // Caution: subject to endianness
    //      int16_t  data_s16  [4] ; // Caution: subject to endianness
    //      int8_t   data_s8   [8] ;
    //      uint8_t  data      [8] = {0, 0, 0, 0, 0, 0, 0, 0} ;
    //    };
    //
  public:
    //    CanMsg();
    void receive();
    void send();
};


class CanBus {
  private :


  public:
    static void setup(uint32_t);
    //    static void receive();
    //    static void send();

};


#endif