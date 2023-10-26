#ifndef RFID_H
#define RFID_H

// #if (ARDUINO > 100)
// #include <Arduino.h>
// #else
// #include <WProgram.h>
// #endif
#include <string>
#include <sstream>
#include <iomanip>
#include <HardwareSerial.h>

class Rfid
{
public:
  Rfid(HardwareSerial *serial);
  
  /**
   * read the value from serialdata
   */
  virtual std::string getType() {
    return "Dispenser";
  };

  /**
   * read the value from serialdata
   */
  String getReadData();

  /**
   * serial Event manager
   */
  void serialEvent();

  /**
   * data has been fetched
   */
  bool isReadyToRead();
  HardwareSerial *getSerial();
protected:
  HardwareSerial *rfidSerial;

  String serial_data;
  bool is_ready_to_read = false;
};

#endif
