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



}

void Body::splitToMaxSize(){



}

int Body::checkSize(){

return 1;
}