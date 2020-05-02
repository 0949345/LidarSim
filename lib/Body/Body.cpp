#include "Body.h"


void Body::generateBeams()
{
    for (int i = 0; i < beamAmount; i++)
    {
        beams[i].distance = rand() % 4000;
        float var = rand() % 99 + 1;
        //Serial.println(var);
        beams[i].RSSI = (var / 10);
        beams[i].status = rand() % 5 + 1;
    }
}

void Body::splitToMaxSize()
{
}

int Body::checkSize()
{ //sddsdssd

    return 1;
}
void Body::printBeams()
{
    Serial.println("Generated beams:");
    for (int i = 0; i < beamAmount; i++)
    {
        Serial.print("Beam: ");
        Serial.println(i);
        Serial.println(beams[i].distance);
        Serial.println(beams[i].RSSI);
        Serial.println(beams[i].status);
    }
}

// Setters && getters

void Body::setBeamAmount(int amount)
{
    this->beamAmount = amount;
}

void Body::setBeam(int distance_, int RSSI_, byte status_, int beamNr)
{
    beams[beamNr].distance = distance_;
    beams[beamNr].RSSI = RSSI_;
    beams[beamNr].status = status_;
}

beamStruct * Body::getBeams()
{
    return beams;
}
