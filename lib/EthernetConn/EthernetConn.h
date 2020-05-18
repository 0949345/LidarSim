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

  int beamAmount = 10;    //aantal beams dat gegenereerd wordt
  char bodyArray[256];
  int arrayCounterBody = 0;
  // boolean rawBodyData[1023];
  EthernetProtocol Ep;

protected:
public:
  void convertHeader();
  void convertBody();
  boolean *sendData();
  //void byteToBit();
  //void fillBit();
  EthernetConn();
  void reserveByte(int numOfBytes);
  void printRawData();
  void printAllData();
  int getCounter();
  // Convert functions
  void convertToBinary16Bit(long int n);
  void convertToBinary8Bit( int n);
  void convertToBinary32Bit(unsigned long int n);
  void convertToStatus(int);
};
