#include "MicroController.h"

void MicroController::getData(boolean data[], int counter)
{
    Serial.println();
    for (int i = 0; i < counter; i++)
    {
        incomingRawData[i] = data[i];
        Serial.print(incomingRawData[i]);
    }

    // Serial.print("\nresult: ");
    //convertBody(1,1);
}

void MicroController::convertBody(int num, int beamNum)
{
    Serial.println(converter8Bit(incomingRawData, 0));
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

double MicroController::converter8Bit(boolean data[], int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 7; i > -1; i--)
    {
        if (data[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter16Bit(boolean data[], int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 15; i > -1; i--)
    {
        if (data[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter32Bit(boolean data[], int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 31; i > -1; i--)
    {
        if (data[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}