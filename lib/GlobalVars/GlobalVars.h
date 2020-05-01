//De globale variable
#pragma once
#include <arduino.h>
#include <string.h>
#define no_light 1
#define blind 2
#define reflector 3
#define error 4
#define warning 5




struct headerStruct {
    String datagram_marker;
    String protocol;
    double version;
    int length;
    int fragment_offset;

};

struct beamStruct {
    int distance;       //in mm
    int RSSI;           //intensity
    byte status;        //status = geen licht/blind/reflector/Error/Warning 
};

