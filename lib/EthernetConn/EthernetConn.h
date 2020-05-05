#include <Arduino.h>
#include "../Header/Header.h"
#include "../GlobalVars/GlobalVars.h"
#include "../Body/Body.h"
#include "../EthernetProtocol/EthernetProtocol.h"
#pragma once

class EthernetConn
{

private:
  int headerLength = 0;
  int arrayCounterHeeader;
  char intArray[12];
  char headerArray[256];

  int beamAmount = 6;
  char bodyArray[256];
  int arrayCounterBody = 0;
  boolean rawBodyData[1024];
  EthernetProtocol Ep;

protected:
public:
  void convertHeader();
  void convertBody();
  void sendData();
  //void byteToBit();
  //void fillBit();
  EthernetConn();
  long convertToBinary16Byte(long int n);
};
