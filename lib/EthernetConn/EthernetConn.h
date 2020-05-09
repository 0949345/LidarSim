#include <Arduino.h>
#include "../Header/Header.h"
#include "../GlobalVars/GlobalVars.h"
#include "../Body/Body.h"
#include "../EthernetProtocol/EthernetProtocol.h"
#include <math.h>       /* pow */
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
  boolean convertToBinary16BitBigEnd(long int n);
  boolean convertToBinary8BitBigEnd( int n);
};
