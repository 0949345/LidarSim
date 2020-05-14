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
  void generateHeader(int device, int config, int measurement, int fieldInterruption, int application);
  void splitData();

  void printHeader();
  void printAllData();
  //Setters && Getters
  beamStruct *getBody();
  headerStruct getHeader();
};
