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
    void convert();
    void convertHeader();

    

    void printData();
};
