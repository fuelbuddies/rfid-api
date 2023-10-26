#include "PetropointHectronics.hpp"

PetropointHectronics::PetropointHectronics(HardwareSerial *serial) : Rfid(serial)
{
}

std::string PetropointHectronics::getType()
{
  return "PETROPOINTHECTRONICS";
}