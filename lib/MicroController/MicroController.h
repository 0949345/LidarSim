#include "Arduino.h"
#pragma once

class MicroController
{
private:
    boolean incomingRawData[1023];
    boolean header[416];
    int headerBitLength = 416;

protected:
public:
    void getData(boolean data[],int counter);
    void convert();
    void printData();
    void seperateToHeader();
};
