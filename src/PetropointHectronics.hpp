#ifndef PETROPOINTHECTRONICS_H
#define PETROPOINTHECTRONICS_H

#include "Rfid.hpp"

class PetropointHectronics : public Rfid
{
public:
  PetropointHectronics(HardwareSerial *serial);

  std::string getType();
};


#endif