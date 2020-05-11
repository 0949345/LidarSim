//De globale variable
#pragma once
#include <arduino.h>
#include <string.h>
#include <math.h>
// #include <EEPROM.h>
#define valid 0
#define no_light 1
#define dazzle 2
#define reflector 3
#define error 4
#define warning 5

// EERef sequenceNum = EEPROM[0]; // Wordt gebruikt om bij te houden hoeveel dataset zijn verstuurd
// EERef scanNum = EEPROM[5];       // Wordt gebruikt om bij te houden hoeveel scans er zijn gemaakt


#define maxBeamCount = 100;


struct headerMajor
{
    String datagramMarker;
    String protocol;
    int versionMajor;
    int versionMinor;
    int totalLeangth;
    int id;
    int fragmentOffset;
    int reserved;
};


struct versionStruct
{
    int version;
    int MajorVersion;
    int MinorVersion;
    int release;
};
struct offsetBlock
{
    int offset;
    int size;
};
struct timeStruct
{
    unsigned int date;
    int time;
};

struct headerStruct {
    versionStruct version;
    int serialNumber;
    int serialNumberSystemPlug;
    int channelNumber;
    //3 bytes reserved
    int sequenceNumber;
    int scanNumber;
    timeStruct timeStamp;
    offsetBlock deviceStatus;           // Blok waar de device data in wordt aangegeven
    offsetBlock configurationData;      // Blok met de configuraties (aantal beams de kijkhoek etc.)
    offsetBlock measurementData;        // Blok waar de uitgelezen data staat (de beams die wij genereren)
    offsetBlock fieldInterruption;      // Blok waarin wordt aangegeven of er een reflector is waargenomen
    offsetBlock applicationData;        // Blok waarin wordt aangegeven of er "beams" zijn onderbroken (mogelijk om aan/uit te zetten in de LIDAR)
};

struct beamStruct {
    int distance;       //in mm
    int RSSI;           //intensity
    int status;         //status = geen licht/blind/reflector/Error/Warning 
};

