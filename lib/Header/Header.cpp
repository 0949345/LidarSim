#include "Header.h"

void Header::generateHeaderStart()
{ //biggest part of the header can be hardcoded
    header.version.version = 1;
    header.version.MajorVersion = 2;
    header.version.MinorVersion = 3;
    header.version.release = 456;

    header.serialNumber = 4653;
    header.serialNumberSystemPlug = 678;
    header.channelNumber = 2;
    header.sequenceNumber = 213;
    header.scanNumber = 321;
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
}

void Header::printHeader()
{
    Serial.println(header.version.version);
    Serial.println(header.version.MajorVersion);
    Serial.println(header.version.MinorVersion);
    Serial.println(header.version.release);

    Serial.println(header.serialNumber);
    Serial.println(header.serialNumberSystemPlug);
    Serial.println(header.channelNumber);
    Serial.println(header.sequenceNumber);
    Serial.println(header.scanNumber);
    Serial.println(header.timeStamp.date);
    Serial.println(header.timeStamp.time);

    Serial.println(header.deviceStatus.offset);
    Serial.println(header.deviceStatus.size);
    Serial.println(header.configurationData.offset);
    Serial.println(header.configurationData.size);
    Serial.println(header.measurementData.offset);
    Serial.println(header.measurementData.size);
    Serial.println(header.fieldInterruption.offset);
    Serial.println(header.fieldInterruption.size);
    Serial.println(header.applicationData.offset);
    Serial.println(header.applicationData.size);
}
//  Getters & Setters

headerStruct Header::getHeader()
{
    return header;
}

void Header::setHeader(headerStruct value)
{
    header = value;
}

void Header::setFirstDataBlockOffset(int size)
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

void Header::setDataBlockOffset(offsetBlock dataBlock, int size)
{
    if (size == 0)
    {
        dataBlock.offset = 0;
        dataBlock.size = 0;
    }
    else if (size > 0)
    {
        dataBlock.offset = startOffset;
        dataBlock.size = size;
        currentOffset = startOffset + size;
    }
}