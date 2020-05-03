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

  EthernetProtocol Ep;
   int beamAmount = 6;
   char bodyArray[256];
   char headerArray[256];
protected:
public:

void convertHeader();
void convertData();
void sendData();
EthernetConn();
};
