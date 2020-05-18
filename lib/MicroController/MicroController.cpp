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
        Serial.print(temp);
        //Serial.println(data[i]);  //printen van de data
    }
    Serial.println();

    // Serial.print("Test0: ");
    // Serial.println(converter8Bit(0));
    
    
}

void MicroController::convertBody()
{

    Serial.println(converter32Bit(52));

    Serial.println(converter16Bit(56));


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
    // Serial.print(F("Sequence: "));
    // double sequence = converter32Bit(16);
    // Serial.println(sequence);

    //scan nummer converten+uitlezen
    // Serial.print("Scan: ");
    // double scan = round(converter32Bit(20));
    // Serial.println(scan);

    // Serial.print("poep: ");
    // double poep = round(converter32Bit(20));
    // Serial.println(poep);

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