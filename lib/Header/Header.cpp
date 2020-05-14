#include "Header.h"

void Header::generateHeaderStart()
{ // A small part of the header can be hardcoded
    header.version.version = 20;
    header.version.MajorVersion = 25;
    header.version.MinorVersion = 107;
    header.version.release = 456;

    header.serialNumber = 455653;
    header.serialNumberSystemPlug = 67988;
    header.channelNumber = 2;
    // This part cannot be hardcoded
    header.sequenceNumber = sequencceCounter;
    header.scanNumber = scanCounter;
    header.timeStamp.date = millis();
    header.timeStamp.time = millis();

    header.deviceStatus.offset = 0;
    header.deviceStatus.size = 0;
    header.configurationData.offset = 0;
    header.configurationData.size = 0;
    header.measurementData.offset = 0;
    header.measurementData.size = 0;
    header.fieldInterruption.offset = 0;
    header.fieldInterruption.size = 0;
    header.applicationData.offset = 0;
    header.applicationData.size = 0;

    sequencceCounter++;
    scanCounter++;
}

void Header::printHeader()
{
    Serial.println(F("=====HeaderStart====="));
    Serial.print(F("Version:"));
    Serial.println(header.version.version);
    Serial.print(F("MajorVersion:"));
    Serial.println(header.version.MajorVersion);
    Serial.print(F("MinorVersion:"));
    Serial.println(header.version.MinorVersion);
    Serial.print(F("Release:"));
    Serial.println(header.version.release);

    Serial.print(F("Serialnumber:"));
    Serial.println(header.serialNumber);
    Serial.print(F("SystemSerialNumber:"));
    Serial.println(header.serialNumberSystemPlug);
    Serial.print(F("ChannelNumber:"));
    Serial.println(header.channelNumber);
    Serial.print(F("Sequence:"));
    Serial.println(header.sequenceNumber);
    Serial.print(F("Scan:"));
    Serial.println(header.scanNumber);
    Serial.print(F("Date:"));
    Serial.println(header.timeStamp.date);
    // delay(1000);
    Serial.print(F("Time:"));
    Serial.println(header.timeStamp.time);
    Serial.print(F("Device offset:"));
    Serial.println(header.deviceStatus.offset);
    Serial.print(F("Device size:"));
    Serial.println(header.deviceStatus.size);
    Serial.print(F("Config offset:"));
    Serial.println(header.configurationData.offset);
    Serial.print(F("Config size:"));
    Serial.println(header.configurationData.size);
    Serial.print(F("MeasurementData offset:"));
    Serial.println(header.measurementData.offset);
    Serial.print(F("MeasurementData size:"));
    Serial.println(header.measurementData.size);
    Serial.print(F("FieldInterruption offset:"));
    Serial.println(header.fieldInterruption.offset);
    Serial.print(F("FieldInterruption size:"));
    Serial.println(header.fieldInterruption.size);
    Serial.print(F("Application offset:"));
    Serial.println(header.applicationData.offset);
    Serial.print(F("Application size:"));
    Serial.println(header.applicationData.size);
}

// /////////////////////////////////////////////////////
//  Getters & Setters

headerStruct Header::getHeader()
{
    return header;
}

void Header::setHeader(headerStruct value)
{
    header = value;
}

void Header::setDataBlockOffset(int dataBlock, int size)
{
    if (dataBlock == 0)
    {
        if (size == 0)
        {
            header.deviceStatus.offset = 0;
            header.deviceStatus.size = 0;
            currentOffset = startOffset;
        }
        else
        {
            header.deviceStatus.offset = startOffset;
            header.deviceStatus.size = size;
            currentOffset = startOffset + size;
        }
    }

    else if (dataBlock == 1)
    {
        if (size == 0)
        {
            header.configurationData.offset = 0;
            header.configurationData.size = 0;
        }
        else if (size > 0)
        {
            header.configurationData.offset = currentOffset;
            header.configurationData.size = size;
            currentOffset = currentOffset + size;
        }
    }
    else if (dataBlock == 2)
    {
        if (size == 0)
        {
            header.measurementData.offset = 0;
            header.measurementData.size = 0;
        }
        else if (size > 0)
        {
            header.measurementData.offset = currentOffset;
            header.measurementData.size = size;
            currentOffset = currentOffset + size;
        }
    }
    else if (dataBlock == 3)
    {
        if (size == 0)
        {
            header.fieldInterruption.offset = 0;
            header.fieldInterruption.size = 0;
        }
        else if (size > 0)
        {
            header.fieldInterruption.offset = currentOffset;
            header.fieldInterruption.size = size;
            currentOffset = currentOffset + size;
        }
    }
    else if (dataBlock == 4)
    {
        if (size == 0)
        {
            header.applicationData.offset = 0;
            header.applicationData.size = 0;
        }
        else if (size > 0)
        {
            header.applicationData.offset = currentOffset;
            header.applicationData.size = size;
            currentOffset = currentOffset + size;
        }
    }
}