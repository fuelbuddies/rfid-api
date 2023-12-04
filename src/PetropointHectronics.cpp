#include "PetropointHectronics.hpp"

PetropointHectronics::PetropointHectronics(HardwareSerial *serial) : Rfid(serial)
{
}

std::string PetropointHectronics::getType()
{
  return "PETROPOINTHECTRONICS";
}

/**
 * Override serialEvent() from Rfid class
 */
void PetropointHectronics::serialEvent()
{
  // not doing anything here for PetropointHectronics.
  is_ready_to_read = true;
}

/**
 * Override getReadData() from Rfid class
 */
String PetropointHectronics::getReadData()
{
  while (rfidSerial->available() > 0)
  {
    String str = String(rfidSerial->read(), HEX);
    if (str.length() == 1) {
      str = "0" + str;
    }

    std::transform(str.begin(), str.end(), str.begin(), std::ptr_fun<int, int>(std::toupper));
    // add it to the inputString:
    serial_data = String(serial_data) + str;
    if(str == "0A") {
      break;
    }
  }

  String response = String(serial_data);
  serial_data = "";
  is_ready_to_read = (bool) rfidSerial->available() > 0;
  return response;
}