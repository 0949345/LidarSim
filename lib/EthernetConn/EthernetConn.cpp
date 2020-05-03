#include "EthernetConn.h"
EthernetConn::EthernetConn()
{
 
    Ep.generate(beamAmount);
    convertBody();

}


void EthernetConn::convertHeader(){
Ep.getHeader();

}

void EthernetConn::convertBody(){
    for (int i = 0; i < beamAmount; i++)
    {   

    int distance__ = Ep.getBody()[i].distance;
    int RSSI__ = Ep.getBody()[i].RSSI;
    int status__ = Ep.getBody()[i].status;
    Serial.println("aaaaa");
    Serial.println(distance__);
    Serial.println(RSSI__);
    Serial.println(status__);
    }


    
}

void EthernetConn::sendData(){

    
}