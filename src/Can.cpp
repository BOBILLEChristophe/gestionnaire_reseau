

#include "Can.h"

//CanMsg::CanMsg() :
//  id(0),      // Frame identifier
//  ext(false), // false -> standard frame, true -> extended frame
//  rtr(false), // false -> data frame, true -> remote frame
//  idx(0),     // This field is used by the driver
//  len(0)      // Length of data (0 ... 8)
//{};

void CanBus::setup(uint32_t CAN_BITRATE)
{
  ACAN_ESP32_Settings settings (CAN_BITRATE) ;
  settings.mRxPin = GPIO_NUM_22 ;    // Optional, default Tx pin is GPIO_NUM_4
  settings.mTxPin = GPIO_NUM_23 ;    // Optional, default Rx pin is GPIO_NUM_5
  const uint32_t errorCode = ACAN_ESP32::can.begin (settings);
  if (0 == errorCode) {
    Serial.println ("Configuration OK!");
  } else {
    Serial.print ("Configuration error 0x") ;
    Serial.println (errorCode, HEX) ;
  }
}

void CanMsg::send()
{
  CANMessage frame;
  const bool ok = ACAN_ESP32::can.tryToSend (frame);
  // if (!ok) {
  //   Serial.printf("Erreur envoi message");
  // }
}

void CanMsg::receive()
{
  CANMessage frame;
  const bool ok = ACAN_ESP32::can.receive (frame);
  // if (!ok) {
  //   Serial.printf("Erreur reception message");
  // }
}