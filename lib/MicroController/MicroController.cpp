#include "MicroController.h"

void MicroController::getData(boolean data[], int counter)
{
    Serial.println();
    for (int i = 0; i < counter; i++)
    {
        incomingRawData[i] = data[i];
        Serial.print(data[i]);
    }
}

void MicroController::convert()
{
    
}

void MicroController::convertHeader()
{
    //sequence nummer converten+uitlezen
    //scan nummer converten+uitlezen

    //measurment data offset converten+uitlezen
    //measurment data size converten+uitlezen

}


void MicroController::printData()
{
}