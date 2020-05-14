#include "EthernetConn.h"
EthernetConn::EthernetConn()
{

    Ep.generate(beamAmount);
    convertHeader();
    convertBody();
    //Ep.printHeader();
    //printRawData();
}

void EthernetConn::convertHeader()
{
    // Empty the array
    for (int l = 0; l < 1022; l++)
    {
        rawBodyData[l] = 0;
        EEPROM.put(l,0);
        //Serial.println(l);
    }
    //Serial.println("---(HEADER)---");
    //tell de characters die nodig zijn voor de header array
    //headerLength += Ep.getHeader().datagram_marker.length();

    convertToBinary8Bit(Ep.getHeader().version.version);      //USInt
    convertToBinary8Bit(Ep.getHeader().version.MajorVersion); //USInt
    convertToBinary8Bit(Ep.getHeader().version.MinorVersion); //USInt
    convertToBinary8Bit(Ep.getHeader().version.release);      //USint

    convertToBinary32Bit(Ep.getHeader().serialNumber);           //UDInt
    convertToBinary32Bit(Ep.getHeader().serialNumberSystemPlug); //UDint
    convertToBinary8Bit(Ep.getHeader().channelNumber);           //USInt

    reserveByte(3); // reserve 3 bytes

    convertToBinary32Bit(Ep.getHeader().sequenceNumber); //UDInt
    convertToBinary32Bit(Ep.getHeader().scanNumber);     //UDInt

    convertToBinary16Bit(Ep.getHeader().timeStamp.date); //UInt

    reserveByte(2); // reserve 2 bytes

    convertToBinary32Bit(Ep.getHeader().timeStamp.time); //UDInt

    convertToBinary16Bit(Ep.getHeader().deviceStatus.offset);      //UInt
    convertToBinary16Bit(Ep.getHeader().deviceStatus.size);        //UInt
    convertToBinary16Bit(Ep.getHeader().configurationData.offset); //UInt
    convertToBinary16Bit(Ep.getHeader().configurationData.size);   //UInt
    convertToBinary16Bit(Ep.getHeader().measurementData.offset);   //UInt
    convertToBinary16Bit(Ep.getHeader().measurementData.size);     //UInt
    convertToBinary16Bit(Ep.getHeader().fieldInterruption.offset); //UInt
    convertToBinary16Bit(Ep.getHeader().fieldInterruption.size);   //UInt
    convertToBinary16Bit(Ep.getHeader().applicationData.offset);   //UInt
    convertToBinary16Bit(Ep.getHeader().applicationData.size);     //UInt
}

void EthernetConn::reserveByte(int numOfBytes)
{
    for (int i = 0; i < numOfBytes * 8; i++)
    {
        rawBodyData[arrayCounterBody] = 0;
        EEPROM.put(arrayCounterBody,0);
        arrayCounterBody++;
    }
}

void EthernetConn::printRawData()
{
    for (int i = 0; i < arrayCounterBody; i++)
    {
        Serial.print(rawBodyData[i]);
    }
}

void EthernetConn::convertBody()
{
    //Serial.println("---(BODY)---");
    convertToBinary32Bit(beamAmount);

    int someValue = 0;
    for (int i = 0; i < beamAmount; i++) //gaat beamAmount keer erdoorheen
    {
        int distance__ = Ep.getBody()[i].distance;
        int RSSI__ = Ep.getBody()[i].RSSI;
        int status__ = Ep.getBody()[i].status;

        for (int j = 0; j < 3; j++) //iederekeer pakt het de struct met 3 waardes in dezelfde volgoorde
        {
            if (j == 0)
            {
                someValue = distance__;
                convertToBinary16Bit(someValue);
            }
            else if (j == 1)
            {
                someValue = RSSI__;
                convertToBinary8Bit(someValue);
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
        //Serial.println(rawBodyData[l]);
    }
}

boolean *EthernetConn::sendData()
{
    return rawBodyData;
}

void EthernetConn::convertToBinary16Bit(long int n)
{ //0-65536

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
                                            //65535
                    rawBodyData[arrayCounterBody] = 1;
                    EEPROM.put(arrayCounterBody,1);
                }
            }
            n = n - pow(2, x);
            rawBodyData[arrayCounterBody] = 1;
            EEPROM.put(arrayCounterBody,1);
        }
        arrayCounterBody++;
    }
}

void EthernetConn::convertToBinary8Bit(int n)
{ // 0-255

    for (int x = 7; x > -1; x--)
    {

        if (n >= pow(2, x))
        {
            if (n >= 255)
            {
                //alles op 1 zetten
                for (int k = 0; k < 8; k++)
                {
                    rawBodyData[arrayCounterBody] = 1;
                    EEPROM.put(arrayCounterBody,1);
                }
            }
            n = n - pow(2, x);
            rawBodyData[arrayCounterBody] = 1;
            EEPROM.put(arrayCounterBody,1);
        }
        arrayCounterBody++;
    }
}

void EthernetConn::convertToStatus(int n)
{
    if (n == valid)
    {
        //Serial.println("valid");
        rawBodyData[arrayCounterBody] = 1;
        EEPROM.put(arrayCounterBody,1);
    }
    else if (n == no_light)
    {
        //Serial.println("no_light");
        rawBodyData[arrayCounterBody + 1] = 1;
        EEPROM.put(arrayCounterBody + 1,1);
    }
    else if (n == dazzle)
    {
        //Serial.println("dazzle");
        rawBodyData[arrayCounterBody + 2] = 1;
        EEPROM.put(arrayCounterBody + 2,1);
    }
    else if (n == reflector)
    {
        //Serial.println("reflector");
        rawBodyData[arrayCounterBody + 3] = 1;
        EEPROM.put(arrayCounterBody + 3,1);
    }
    else if (n == error)
    {
        //Serial.println("error");
        rawBodyData[arrayCounterBody + 4] = 1;
        EEPROM.put(arrayCounterBody + 4,1);
    }
    else if (n == warning)
    {
        //Serial.println("warning");
        EEPROM.put(arrayCounterBody + 5,1);
        rawBodyData[arrayCounterBody + 5] = 1;
    }
    arrayCounterBody = arrayCounterBody + 8;
}

void EthernetConn::convertToBinary32Bit(unsigned long int n)
{ //0-65536


    for (int x = 31; x > -1; x--)
    {

        if (n >= pow(2, x))
        {
            if (n >= 4294967295)
            {
                //alles op 1 zetten
                for (int k = 0; k < 32; k++)
                {
                                            //4294967296
                                            ////4294972928
                    rawBodyData[arrayCounterBody] = 1;
                    EEPROM.put(arrayCounterBody,1);
                }
            }

            n = n - pow(2, x);
            rawBodyData[arrayCounterBody] = 1;
            EEPROM.put(arrayCounterBody,1);
        }
        arrayCounterBody++;
    }
}

int EthernetConn::getCounter(){
    return arrayCounterBody;
}