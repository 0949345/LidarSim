#include "EthernetConn.h"
EthernetConn::EthernetConn()
{

  Ep.generate(beamAmount);
  convertBody();
  convertHeader();
}

void EthernetConn::convertHeader()
{
  //tell de characters die nodig zijn voor de header array
  headerLength += Ep.getHeader().datagram_marker.length();
  headerLength += Ep.getHeader().protocol.length();
  headerLength += String(Ep.getHeader().version).length();
  headerLength += String(Ep.getHeader().length).length();
  headerLength += String(Ep.getHeader().fragment_offset).length();

  
}

void EthernetConn::convertData()
{
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

void EthernetConn::sendData()
{
}