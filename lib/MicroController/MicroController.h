#include "Arduino.h"
#pragma once

class MicroController
{
private:
    boolean incomingRawData[1023];
    
    int headerBitLength = 416;
protected:
public:
    void getData(boolean data[],int counter);
    void convertBody(int num,int beamNum);
    void convertHeader();
    
    void converter8Bit(boolean data[],int num);
    void converter16Bit(boolean data[],int num);
    void converter32Bit(boolean data[],int num);
    void printData();
};
