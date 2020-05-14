#include "EthernetProtocol.h"
EthernetProtocol::EthernetProtocol()
{
}

void EthernetProtocol::generate(int amount)
{
    int bodyByteSize;
    b.setBeamAmount(amount);
    b.generateBeams();
    b.splitToMaxSize();

    bodyByteSize = 4* b.getBeamAmount() +4;
    
    generateHeader(0, 0, bodyByteSize, 0, 0);

    if (isFirstHeader)
    { //Als de eerste header gemaakt moet worden
        if (isDataSplitted)
        { // als de data is gesplits dan is de size de max data grote
            //h.generateFirstHeader(maxDatasize)
        }
        else
        { // als data niet is gesplits dan is de grote het aantal beams
        }
    }
    else
    { // als de eerste header al gemaakt is
    }
    //Header h;
}

void EthernetProtocol::generateHeader(int device, int config, int measurement, int fieldInterruption, int application)
{
    h.generateHeaderStart();
    h.setDataBlockOffset(0, device);
    h.setDataBlockOffset(1, config);
    h.setDataBlockOffset(2, measurement);
    h.setDataBlockOffset(3, fieldInterruption);
    h.setDataBlockOffset(4, application);
}

void EthernetProtocol::splitData()
{
}

void EthernetProtocol::printHeader()
{
    h.printHeader();
}

void EthernetProtocol::printAllData(){
    h.printHeader();
    b.printBeams();
}

headerStruct EthernetProtocol::getHeader()
{
    return h.getHeader();
    //moet aangeroepen kunnen worden door de ethernet connection
    //om de body te krijgen zodat deze weer omgezet kan worden
}

//deze functie wordt aangeroepen vanuit ethernet Con hierbij maken wij een var
//met een * zodat hiernaar verwezen kan worden aangezien dit de eerste waarde is
//in de de struct
//dus converterableStruct* = Ep.getBody();
//converterableStruct[]
beamStruct *EthernetProtocol::getBody()
{
    return b.getBeams();
    //return b.
}
