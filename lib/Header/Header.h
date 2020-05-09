#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"

#pragma once
#define LIDARSIM_HEADER_H

class Header
{
private:
    headerStruct header;
    int startOffset = 32;
    int currentOffset;

    int sequencceCounter = 0;
    int scanCounter = 0;

protected:
public:
    void generateHeaderStart();
    void generateNonFirstHeader(int size, int prevSize, int prevOffsetd);
    void printHeader();
    headerStruct getHeader();
    void setHeader(headerStruct value); //not needed??

    void setFirstDataBlockOffset(int size);
    void setDataBlockOffset(int dataBlockint, int size);
};
