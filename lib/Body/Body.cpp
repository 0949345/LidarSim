#include "Body.h"

void Body::generateBeams()
{
    for (int i = 0; i < beamAmount; i++)
    {
        beams[i].distance = rand() % 65535;
        //Serial.println(var);
        beams[i].RSSI = (rand() % 256) - 128;
        beams[i].status = rand() % 5 + 1;
    }
}

void Body::splitTo(beamStruct *beamArray)
{
}

void Body::splitToMaxSize()
{
}

int Body::checkSize()
{
    return 1;
}
void Body::printBeams()
{

    Serial.println(F("Generated beams:"));
    for (int i = 0; i < beamAmount; i++)
    {
        Serial.print(F("Beam: "));
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
int Body::getBeamAmount()
{
    return this->beamAmount;
}

void Body::setBeam(int distance_, int RSSI_, byte status_, int beamNr)
{
    beams[beamNr].distance = distance_;
    beams[beamNr].RSSI = RSSI_;
    beams[beamNr].status = status_;
}

beamStruct *Body::getBeams()
{
    return beams;
}
