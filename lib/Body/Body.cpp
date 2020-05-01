#include "Body.h"
Body::Body(int beamAmount){
//beamStruct beams[beamAmount];
//setBeamAmount();
}

void Body::setBeam(int distance_, int RSSI_, byte status_, int beamNr){
    beams[beamNr].distance = distance_;
    beams[beamNr].RSSI = RSSI_;
    beams[beamNr].status = status_;
}

void Body::generateBeams(){
for (int i = 0; i < 9; i++)
{
    beams[i].distance = rand() % 99 +1;
    beams[i].RSSI = (rand() % 99 +1)/100;
    beams[i].status = rand() % 5 +1;
}



}

void Body::splitToMaxSize(){



}

int Body::checkSize(){

return 1;
}