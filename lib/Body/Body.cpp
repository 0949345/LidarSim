#include "Body.h"
Body::Body(int beamAmount){
    Serial.println("generating beams dadadadada");
    Serial.println(beamAmount);
    generateBeams(beamAmount);
    this.beamAmount = beamAmount;
    //beamAmount = beamAmount_;
//beamStruct beams[beamAmount];
//setBeamAmount();
}

void Body::setBeam(int distance_, int RSSI_, byte status_, int beamNr){
    beams[beamNr].distance = distance_;
    beams[beamNr].RSSI = RSSI_;
    beams[beamNr].status = status_;
}

void Body::generateBeams(int amount){
for (int i = 0; i < amount; i++)
{
    beams[i].distance = rand() % 99 +1;
    float var = rand() % 99 +1;
    //Serial.println(var);
    beams[i].RSSI = (var/10);
    beams[i].status = rand() % 5 +1;
    Serial.println(beams[i].distance);
    Serial.println(beams[i].RSSI);
    Serial.println(beams[i].status);
}



}

void Body::splitToMaxSize(){



}

int Body::checkSize(){          //sddsdssd

return 1;
}