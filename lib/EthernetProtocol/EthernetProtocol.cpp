#include "EthernetProtocol.h"
EthernetProtocol::EthernetProtocol()
{
}

void EthernetProtocol::generate(int amount)
{
    b.setBeamAmount(6);
    b.generateBeams();
    b.printBeams();
    int test = b.getBeams()[0].distance;
    Serial.println(test);
    //Header h;
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
