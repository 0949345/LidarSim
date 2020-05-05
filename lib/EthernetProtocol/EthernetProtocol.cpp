#include "EthernetProtocol.h"
EthernetProtocol::EthernetProtocol()
{
}

void EthernetProtocol::generate(int amount)
{
    b.setBeamAmount(6);
    b.generateBeams();
    b.printBeams();

    if (isFirstHeader)
    { //Als de eerste header gemaakt moet worden
        if (isDataSplitted)
        { // als de data is gesplits dan is de size de max data grote
            //h.generateFirstHeader(maxDatasize)
        }
        else
        { // als data niet is gesplits dan is de grote het aantal beams
            generateHeader();
        }
    }
    else
    { // als de eerste header al gemaakt is
    }
    //Header h;
}

void EthernetProtocol::generateHeader()
{
    h.generateHeaderStart();
    h.setFirstDataBlockOffset(0);
    h.setDataBlockOffset(getHeader().configurationData, 0);
    h.setDataBlockOffset(getHeader().measurementData, 0);
    h.setDataBlockOffset(getHeader().fieldInterruption, 0);
    h.setDataBlockOffset(getHeader().applicationData, 0);
}

void EthernetProtocol::printHeader()
{
    h.printHeader();
}

headerStruct EthernetProtocol::getHeader()
{
    return h.getHeader();
}
//moet aangeroepen kunnen worden door de ethernet connection
//om de body te krijgen zodat deze weer omgezet kan worden

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
