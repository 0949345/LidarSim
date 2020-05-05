#include "Header.h"

void Header::generateHeaderStart() { //biggest part of the header can be hardcoded
    header.version.version = 1;
    header.version.MajorVersion = 2;
    header.version.MinorVersion = 3;
    header.version.release = 456;

    header.serialNumber = 4653;
    header.serialNumberSystemPlug = 678;
    header.channelNumber = 2;
    header.sequenceNumber = 213;
    header.scanNumber = 321;
    header.timeStamp.date = 24345;
    header.timeStamp.time = 26864;
}



void Header::printHeader(){
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
}
//  Getters & Setters

headerStruct Header::getHeader(){
    return header;
}

void Header::setHeader(headerStruct value){
    header = value;
}