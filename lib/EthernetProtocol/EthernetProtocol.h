#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"
#include "../Body/Body.h"
#pragma once

class EthernetProtocol
{

private:
Body b;
Header h;
  //b
  //h
protected:
public:
  EthernetProtocol();
  void generate(int amount);

  //Setters && Getters
  beamStruct getBody();
  void getHeader();
};
