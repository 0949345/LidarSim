#include "MicroController.h"

void MicroController::getData(boolean *data, int counter)
{
    Serial.println(F("----------"));
    for (int i = 0; i < counter; i++)
    {
        incomingRawData[i] = data[i];
        Serial.print(incomingRawData[i]); //printen van de data
    }


    Serial.print(F("\ntest: "));
    //Serial.print(incomingRawData[3]);
    convertBody(1, 1);
}

void MicroController::convertBody(int num, int beamNum)
{
    converter8Bit(0);
    Serial.println(F("testing"));
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

double MicroController::converter8Bit(int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 7; i > -1; i--)
    {
        if (incomingRawData[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter16Bit(int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 15; i > -1; i--)
    {
        if (incomingRawData[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter32Bit(int byteNum)
{
    int num = byteNum * 8;
    double result = 0;
    // for (int i = 0; i < 8; i++)
    // {
    //     dataToBeConverted[i] = ;
    // }

    for (int i = 31; i > -1; i--)
    {
        if (incomingRawData[num] == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}