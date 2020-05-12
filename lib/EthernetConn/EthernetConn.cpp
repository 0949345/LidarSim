#include "EthernetConn.h"
EthernetConn::EthernetConn()
{

    Ep.generate(beamAmount);
    convertBody();
    convertHeader();
    //Ep.printHeader();
}

void EthernetConn::convertHeader()
{
    Serial.println("---(HEADER)---");
    //tell de characters die nodig zijn voor de header array
    //headerLength += Ep.getHeader().datagram_marker.length();
    convertToBinary8BitBigEnd(Ep.getHeader().version.version); //USInt

    convertToBinary8BitBigEnd(Ep.getHeader().version.version);      //USInt
    convertToBinary8BitBigEnd(Ep.getHeader().version.MajorVersion); //USInt
    convertToBinary8BitBigEnd(Ep.getHeader().version.MinorVersion); //USInt
    convertToBinary8BitBigEnd(Ep.getHeader().version.release);      //USint

    convertToBinary32BitBigEnd(Ep.getHeader().serialNumber);           //UDInt
    convertToBinary32BitBigEnd(Ep.getHeader().serialNumberSystemPlug); //UDint
    convertToBinary8BitBigEnd(Ep.getHeader().channelNumber);           //USInt

    reserveByte(3); //reserve 3 bytes

    convertToBinary32BitBigEnd(Ep.getHeader().sequenceNumber); //UDInt
    convertToBinary32BitBigEnd(Ep.getHeader().scanNumber);     //UDInt

    convertToBinary16BitBigEnd(Ep.getHeader().timeStamp.date); //UInt

    reserveByte(2); //reserve 2 bytes

    convertToBinary32BitBigEnd(Ep.getHeader().timeStamp.time); //UDInt

    convertToBinary16BitBigEnd(Ep.getHeader().deviceStatus.offset);      //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().deviceStatus.size);        //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().configurationData.offset); //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().configurationData.size);   //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().measurementData.offset);   //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().measurementData.size);     //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().fieldInterruption.offset); //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().fieldInterruption.size);   //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().applicationData.offset);   //UInt
    convertToBinary16BitBigEnd(Ep.getHeader().applicationData.size);     //UInt
}

void EthernetConn::reserveByte(int numOfBytes)
{
    for (int i = 0; i < numOfBytes * 8; i++)
    {
        rawBodyData[arrayCounterBody] = 0;
        arrayCounterBody++;
    }
}

void EthernetConn::convertBody()
{
    Serial.println("---(BODY)---");
    for (int l = 0; l < 1022; l++)
    {
        rawBodyData[l] = 0;
        //Serial.println(l);
    }
    int valLen = 0;
    int someValue = 0;
    for (int i = 0; i < beamAmount; i++) //gaat beamAmount keer erdoorheen
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
            }
            else if (j == 1)
            {
                someValue = RSSI__;
                convertToBinary8BitBigEnd(someValue);
            }
            else
            {
                someValue = status__;
                convertToStatus(someValue);
            }
        }
    }
    for (int l = 0; l < arrayCounterBody; l++)
    {
        Serial.println(rawBodyData[l]);
    }
}

void EthernetConn::sendData()
{
}

boolean EthernetConn::convertToBinary16BitBigEnd(long int n)
{ //0-65536
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
{ // 0-255
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
                    tempBoolArray[k] = 1;
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
        rawBodyData[arrayCounterBody + 1] = 1;
    }
    else if (n == dazzle)
    {
        //Serial.println("dazzle");
        rawBodyData[arrayCounterBody + 2] = 1;
    }
    else if (n == reflector)
    {
        //Serial.println("reflector");
        rawBodyData[arrayCounterBody + 3] = 1;
    }
    else if (n == error)
    {
        //Serial.println("error");
        rawBodyData[arrayCounterBody + 4] = 1;
    }
    else if (n == warning)
    {
        //Serial.println("warning");
        rawBodyData[arrayCounterBody + 5] = 1;
    }
    arrayCounterBody = arrayCounterBody + 8;
}

boolean EthernetConn::convertToBinary32BitBigEnd(unsigned long int n)
{ //0-65536

    boolean tempBoolArray[32];

    for (int s = 0; s < 32; s++)
    {
        tempBoolArray[s] = 0;
    }

    //Serial.println("---");
    for (int x = 31; x > -1; x--)
    {

        if (n >= pow(2, x))
        {
            if (n >= 4294967295)
            {
                //alles op 1 zetten
                for (int k = 0; k < 32; k++)
                {
                    tempBoolArray[k] = 1; //4294967296
                                          ////4294972928
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
        for (int s = 0; s < 32; s++)
        {
            Serial.print(tempBoolArray[s]);
        }
        Serial.println();
        return tempBoolArray;
    }
}
