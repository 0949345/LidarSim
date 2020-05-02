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



}

beamStruct EthernetProtocol::getBody(){      //nog type aanpassen
// return b.getBeams();
//return b.
}

