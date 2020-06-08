#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#include "../lib/EthernetProtocol/EthernetProtocol.h"
#include "../lib/EthernetConn/EthernetConn.h"
#include "../lib/MicroController/MicroController.h"






void setup()
{
  Serial.begin(115200);
  
  EthernetConn ethernet;
  MicroController microContr;
  //ethernet.printAllData();
  //sends data to controller
  microContr.getData(ethernet.sendData(),ethernet.getCounter());
  microContr.convertHeader();
  microContr.convertBody();
}

void loop()
{

}
