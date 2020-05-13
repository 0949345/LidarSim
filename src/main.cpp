#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#include "../lib/EthernetProtocol/EthernetProtocol.h"
#include "../lib/EthernetConn/EthernetConn.h"
#include "../lib/MicroController/MicroController.h"
#define onboardLed 13

//Testen van Jayden
void testFunctionJayden()
{

}

// Testen van keanu
void testFunctionKeanu()
{
  EthernetConn ethernet;
  MicroController microContr;
  //sends data to controller
  microContr.getData(ethernet.sendData(),ethernet.getCounter());
  //microContr.convertBody();
  microContr.printData();
}

void setup()
{
  Serial.begin(9600);
  pinMode(onboardLed, OUTPUT);
  Serial.println("Leggoooooo");
  testFunctionJayden();
  testFunctionKeanu();
}

void loop()
{
  digitalWrite(onboardLed, LOW);
  delay(1000);
  digitalWrite(onboardLed, HIGH);
  delay(1000);
}
