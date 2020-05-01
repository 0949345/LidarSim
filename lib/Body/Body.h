#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"
#pragma once





class Body {

private:
  beamStruct beams[10];  
protected:
public:

Body(int beamAmount);
void setBeam(int distance_, int RSSI_, byte status_, int beamNr);
void generateBeams();
void splitToMaxSize();
int checkSize();
};

