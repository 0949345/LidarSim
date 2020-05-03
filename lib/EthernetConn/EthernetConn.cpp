#include "EthernetConn.h"
EthernetConn::EthernetConn()
{
  EthernetProtocol Ep;
  Ep.generate(6);
}
