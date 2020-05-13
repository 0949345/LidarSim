#include "Arduino.h"
#pragma once

class MicroController
{
private:
    boolean incomingRawData[1023];

protected:
public:
    void getData(boolean data[],int counter);
    void convert();
    void printData();
};
