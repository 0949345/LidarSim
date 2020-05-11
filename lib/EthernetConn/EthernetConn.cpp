#include "EthernetConn.h"
EthernetConn::EthernetConn()
{

    Ep.generate(beamAmount);
    convertBody();
    // convertHeader();
    Ep.printHeader();
}

void EthernetConn::convertHeader()
{
    //tell de characters die nodig zijn voor de header array
    //headerLength += Ep.getHeader().datagram_marker.length();
}

void EthernetConn::convertBody()
{
    
    // convertToBinary16BitBigEnd(32768);
    // convertToBinary16BitBigEnd(65536);
    //convertToBinary16BitBigEnd(38999);
    //convertToBinary8BitBigEnd(123);
    for (int l = 0; l < 1000; l++)
    {
        rawBodyData[l] = 0;
    }
    int valLen = 0;
    int someValue = 0;
    for (int i = 0; i < beamAmount; i++) //gaat boumamount keer erdoorheen
    {
        Serial.println();

        int distance__ = Ep.getBody()[i].distance;
        int RSSI__ = Ep.getBody()[i].RSSI;
        int status__ = Ep.getBody()[i].status;

        for (int j = 0; j < 3; j++) //iederekeer pakt het de struct met 3 waardes in dezelfde volgoorde
        {
            if (j == 0)
            {
                someValue = distance__;
                convertToBinary16BitBigEnd(someValue);

                // itoa(distance__, intArray, 10);
            }
            else if (j == 1)
            {
                someValue = RSSI__;
                convertToBinary8BitBigEnd(someValue);

                //Serial.println(convertDecimalToBinary(someValue));
                // itoa(RSSI__, intArray, 10);
            }
            else
            {
                someValue = status__;
                //
                // --(komt nog een convert)--
                //
                convertToStatus(someValue);
                //Serial.println(someValue);
                //Serial.println(convertDecimalToBinary(someValue));
                // itoa(status__, intArray, 10);
            }

            // if (someValue > 9999)
            //     valLen = 5;
            // else if (someValue > 999)
            //     valLen = 4;
            // else if (someValue > 99)
            //     valLen = 3;
            // else if (someValue > 9)
            //     valLen = 2;
            // else
            //     valLen = 1;

            // for (int l = 0; l < valLen; l++)
            // {
            //     bodyArray[arrayCounterBody] = intArray[l];
            //     //Serial.println(bodyArray[arrayCounterBody]);
            //     arrayCounterBody++;
            // }

            //Serial.println(distance__);
            //Serial.println(RSSI__);
            //Serial.println(status__);
        }
    }
    //Serial.println("----------");
    for (int l = 0; l < arrayCounterBody; l++)
    {
        Serial.println(rawBodyData[l]);
    }
}

void EthernetConn::sendData()
{
}

boolean EthernetConn::convertToBinary16BitBigEnd(long int n)
{
    boolean tempBoolArray[16];

    for (int s = 0; s < 16; s++)
    {
        tempBoolArray[s] = 0;
    }

    //Serial.println("---");
    for (int x = 15; x > -1; x--)
    {

        if (n >= pow(2, x))
        {
            if (n >= 65536)
            {
                //alles op 1 zetten
                for (int k = 0; k < 16; k++)
                {
                    tempBoolArray[k] = 1; //65535
                    rawBodyData[arrayCounterBody] = 1;
                }
            }
            n = n - pow(2, x);
            tempBoolArray[x] = 1;
            rawBodyData[arrayCounterBody] = 1;
        }
        arrayCounterBody++;
    }

    //printen van de variablen
    if (1 == 0)
    {
        for (int s = 0; s < 16; s++)
        {
            Serial.print(tempBoolArray[s]);
        }
        Serial.println();
        return tempBoolArray;
    }
}

boolean EthernetConn::convertToBinary8BitBigEnd(int n)
{
    boolean tempBoolArray[8];

    for (int s = 0; s < 8; s++)
    {
        tempBoolArray[s] = 0;
    }

    //Serial.println("---");
    for (int x = 7; x > -1; x--)
    {

        if (n >= pow(2, x))
        {
            if (n >= 255)
            {
                //alles op 1 zetten
                for (int k = 0; k < 8; k++)
                {
                    tempBoolArray[k] = 1; //65535
                    rawBodyData[arrayCounterBody] = 1;
                }
            }
            n = n - pow(2, x);
            tempBoolArray[x] = 1;
            rawBodyData[arrayCounterBody] = 1;
        }
        arrayCounterBody++;
    }

    //printen van de variablen
    if (1 == 0)
    {
        for (int s = 0; s < 8; s++)
        {
            Serial.print(tempBoolArray[s]);
        }
        Serial.println();
        return tempBoolArray;
    }
}

boolean EthernetConn::convertToStatus(int n)
{
    if (n == valid)
    {
        //Serial.println("valid");
        rawBodyData[arrayCounterBody] = 1;
    }
    else if (n == no_light)
    {
        //Serial.println("no_light");
        rawBodyData[arrayCounterBody+1] = 1;
    }
    else if (n == dazzle)
    {
        //Serial.println("dazzle");
        rawBodyData[arrayCounterBody+2] = 1;
    }
    else if (n == reflector)
    {
        //Serial.println("reflector");
        rawBodyData[arrayCounterBody+3] = 1;
    }
    else if (n == error)
    {
        //Serial.println("error");
        rawBodyData[arrayCounterBody+4] = 1;
    }
    else if (n == warning)
    {
        //Serial.println("warning");
        rawBodyData[arrayCounterBody+5] = 1;
    }
    arrayCounterBody = arrayCounterBody + 8;
}
