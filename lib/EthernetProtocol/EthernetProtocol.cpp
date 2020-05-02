#include "EthernetProtocol.h"
EthernetProtocol::EthernetProtocol()
{

}

void EthernetProtocol::generate(int amount)
{
    b.setBeamAmount(6);
    b.generateBeams();
    b.printBeams();
    //Header h;
}


void EthernetProtocol::getHeader(){



}

void EthernetProtocol::getBody(){      //nog type aanpassen

//return b.
}

