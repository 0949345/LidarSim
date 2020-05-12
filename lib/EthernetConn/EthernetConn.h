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
  char intArray[12];
  char headerArray[256];

  int beamAmount = 10;
  char bodyArray[256];
  int arrayCounterBody = 0;
  boolean rawBodyData[1023];
  EthernetProtocol Ep;

protected:
public:
  void convertHeader();
  void convertBody();
  void sendData();
  //void byteToBit();
  //void fillBit();
  EthernetConn();
  void reserveByte(int numOfBytes);
  void printRawData();

  // Convert functions
  void convertToBinary16BitBigEnd(long int n);
  void convertToBinary8BitBigEnd( int n);
  void convertToStatus(int);
  void convertToBinary32BitBigEnd(unsigned long int n);
};
