#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"

#pragma once
#define LIDARSIM_HEADER_H

class Header{
private:
    headerStruct header;
protected:
public:
    void generateFirstHeader(int size);
    void generateNonFirstHeader(int size, int prevSize, int prevOffsetd);

    headerStruct getHeader();
    void setHeader(headerStruct value); //not sure if needed
};