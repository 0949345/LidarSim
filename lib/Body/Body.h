#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"
#pragma once

class Body
{

private:
  int beamAmount;
  beamStruct beams[10];
  

protected:
public:
  void generateBeams();
  void splitToMaxSize();
  int checkSize();
  void printBeams();
  beamStruct *getBeams();
  //Setters && Getters
  void setBeamAmount(int amount);
  void setBeam(int distance_, int RSSI_, byte status_, int beamNr);
};
