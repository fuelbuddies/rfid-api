#include "Rfid.hpp"

/**
 * abstract class
 */
Rfid::Rfid(HardwareSerial *serial)
{
  rfidSerial = serial;
}

// void Rfid::connectRfid()
// {
//   rfidSerial->begin(baud_rate, SERIAL_8N1, pin_rx, pin_rx);
// }

// bool Rfid::isConnected()
// {
//   return (bool)rfidSerial;
// }

// void Rfid::disconnectRfid()
// {
//   rfidSerial->end();
// }

/*
  SerialEvent occurs whenever a new data comes in the hardware serial RX. This
  routine is run between each time loop() runs, so using delay inside loop can
  delay response. Multiple bytes of data may be available.
*/
void Rfid::serialEvent()
{
  is_ready_to_read = false;
  while (rfidSerial->available()>0)
  {
    String str = String(rfidSerial->read(), HEX);
    if (str.length() == 1) {
      str = "0" + str;
    }
    // add it to the inputString:
    serial_data = String(serial_data) + str;
    is_ready_to_read = true;
  }
}

HardwareSerial *Rfid::getSerial() {
  return rfidSerial;
}

bool Rfid::isReadyToRead()
{
  return is_ready_to_read;
}

String Rfid::getReadData()
{

  String response = String(serial_data);
  serial_data = "";
  is_ready_to_read = false;
  return response;
}

/**
 * flush buffer for fresh data
 */
void Rfid::flushBuffer()
{
  rfidSerial->flush();
}