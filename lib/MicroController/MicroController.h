#include "Arduino.h"
#include "../GlobalVars/GlobalVars.h"
#pragma once

class MicroController
{
private:
    //boolean incomingRawData[1023];
    int headerBitLength = 416;
    int messageLength = 0;

    //converted data
    double sequenceNum = 0;
    double scanNum = 0;
    double measurmentOffset = 0;
    double measurmentSize = 0;
protected:
public:
    void getData(int counter);
    void convertBody(int num, int beamNum);
    void convertHeader();

    double converter8Bit(int byteNum);
    double converter16Bit(int byteNum);
    double converter32Bit(int byteNum);
    void printData();
};
