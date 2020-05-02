#include "EthernetProtocol.h"
EthernetProtocol::EthernetProtocol()
{

}

void EthernetProtocol::generate(int amount)
{
    b.setBeamAmount(6);
    b.generateBeams();
    b.printBeams();
    int test = b.getBeams().distance;
    Serial.println(test);
    //Header h;
}


void EthernetProtocol::getHeader(){

//return h.

}
//moet aangeroepen kunnen worden door de ethernet connection
//om de body te krijgen zodat deze weer omgezet kan worden
beamStruct EthernetProtocol::getBody(){  
return b.getBeams();
//return b.
}

