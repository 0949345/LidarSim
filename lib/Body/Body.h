#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"
#pragma once

class Body
{

private:
  int beamAmount;
  beamStruct beams[500];
  beamStruct beams2[100];
  beamStruct beams3[100];
  beamStruct beams4[100];
  beamStruct beams5[100];
  
  
  

protected:
public:
  void generateBeams();
  void splitTo(beamStruct *beamArray);
  void splitToMaxSize();
  int checkSize();
  void printBeams();
  //Setters && Getters
  void setBeamAmount(int amount);
  int getBeamAmount();
  beamStruct *getBeams();
  void setBeam(int distance_, int RSSI_, byte status_, int beamNr);
};
