#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"

#pragma once
#define LIDARSIM_HEADER_H

class Header
{
private:
    headerStruct header;
    int startOffset = 32;
    int currentOffset= 0;

    unsigned long int sequencceCounter = 0;
    long int scanCounter = 0;

protected:
public:
    void generateHeaderStart();
    void generateNonFirstHeader(int size, int prevSize, int prevOffsetd);
    void printHeader();
    headerStruct getHeader();
    void setHeader(headerStruct value); //not needed??

    void setDataBlockOffset(int dataBlockint, int size);
};
