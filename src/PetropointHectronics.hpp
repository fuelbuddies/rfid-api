#ifndef PETROPOINTHECTRONICS_H
#define PETROPOINTHECTRONICS_H

#include "Rfid.hpp"

class PetropointHectronics : public Rfid
{
public:
  PetropointHectronics(HardwareSerial *serial);

  std::string getType();

  void serialEvent();
  String getReadData();
};


#endif