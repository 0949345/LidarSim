#include "MicroController.h"

void MicroController::getData(boolean data[], int counter)
{
    Serial.println();
    for (int i = 0; i < counter; i++)
    {
        incomingRawData[i] = data[i];
        Serial.print(data[i]);
    }
    converter8Bit(data, 0);
}

void MicroController::convertBody(int num, int beamNum)
{
    //incomingRawData[n]
    //16    convert van 16 naar distance
    //
    //8     convert van 8 naar rssi
    //8     gewoon de status uitlezen
    //dit in de struct zetten
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

void MicroController::converter8Bit(boolean data[], int byteNum)
{
    int num = byteNum * 8;
    boolean dataToBeConverted[32];
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 0; i < 8; i++)
    {
        if (data[num + i] == 1)
        {
            result += pow(2, i);
        }
    }

    Serial.println("\nresult: ");
    Serial.println(result);
}

void MicroController::converter16Bit(boolean data[], int num)
{
    // for (int i = 0; i < 16; i++)
    // {
    //     dataToBeConverted[i] = data[num+i];
    // }
}

void MicroController::converter32Bit(boolean data[], int num)
{
    // for (int i = 0; i < 32; i++)
    // {
    //     dataToBeConverted[i] = data[num+i];
    // }
}