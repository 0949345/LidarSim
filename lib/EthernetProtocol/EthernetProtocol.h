#include <Arduino.h>
#include "../Header/Header.h"
#include "../GlobalVars/GlobalVars.h"
#include "../Body/Body.h"
#pragma once

class EthernetProtocol
{

private:
  Body b;
  Header h;

  bool isFirstHeader = true;
  bool isDataSplitted = false;
  //b
  //h
protected:
public:
  EthernetProtocol();
  void generate(int amount);

  //Setters && Getters
  beamStruct *getBody();
  headerStruct getHeader();
};
