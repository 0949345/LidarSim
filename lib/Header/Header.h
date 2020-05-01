#include <Arduino.h>
#include "../GlobalVars/GlobalVars.h"

#pragma once
#define LIDARSIM_HEADER_H

class Header{
private:
    char header[10];
protected:
public:
    void generateHeader(int size);
    
    char getHeaderIndex(int i);
    void setHeaderIndex(int i, char value); //not sure if needed
};