#include "MicroController.h"

void MicroController::getData(boolean *data, int counter)
{
    boolean temp;
    //memset(incomingRawData, 0, sizeof(incomingRawData));
    Serial.println();
    for (int i = 0; i < counter; i++)
    {
        //incomingRawData[i] = data[i];

        if (i % 8 == 0 && i != 0)
            Serial.print(F(" "));
        EEPROM.get(i, temp);
        //Serial.print(temp);
        //Serial.println(data[i]);  //printen van de data
    }
    Serial.println();

    // Serial.print("Test0: ");
    // Serial.println(converter8Bit(0));
    
    convertBody(1, 1);
}

void MicroController::convertBody(int num, int beamNum)
{

    //converter8Bit(0);
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
    Serial.print(F("Sequence: "));
    sequenceNum = converter32Bit(16);
    Serial.println(sequenceNum);

    //scan nummer converten+uitlezen
    Serial.print(F("Scan: "));
    scanNum = round(converter32Bit(20));
    Serial.println(scanNum);

    Serial.print(F("measurmentOffset: "));
    measurmentOffset = round(converter16Bit(40));
    Serial.println(measurmentOffset);

    Serial.print(F("measurmentSize: "));
    measurmentSize = round(converter16Bit(42));
    Serial.println(measurmentSize);

    //measurment data offset converten+uitlezen
    //convert
    //measurment data size converten+uitlezen
}

void MicroController::printData()
{
}

double MicroController::converter8Bit(int byteNum)
{
    boolean temp;
    int num = byteNum * 8;
    double result = 0;

    for (int i = 7; i > -1; i--)
    {
        EEPROM.get(num, temp);
        if (temp == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter16Bit(int byteNum)
{
    boolean temp;
    int num = byteNum * 8;
    double result = 0;

    for (int i = 15; i > -1; i--)
    {
        EEPROM.get(num, temp);
        if (temp == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}

double MicroController::converter32Bit(int byteNum)
{
    boolean temp;
    int num = byteNum * 8;
    double result = 0;

    for (int i = 31; i > -1; i--)
    {
        EEPROM.get(num, temp);
        if (temp == 1)
        {
            result += pow(2, i);
        }
        num++;
    }
    return result;
}