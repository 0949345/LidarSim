//De globale variable
#pragma once
#include <arduino.h>
#define no_light 1
#define blind 2
#define reflector 3
#define error 4
#define warning 5




struct headerStruct {
    int datagram_marker;
    int protocol;               
    int version;
    int length;
    int fragment_offset;

};

struct beamStruct {
    int distance;       //in mm
    int RSSI;           //intensity
    byte status;        //status = geen licht/blind/reflector/Error/Warning 
};

