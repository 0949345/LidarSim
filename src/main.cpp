#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#include "../lib/EthernetProtocol/EthernetProtocol.h"
#include "EthernetConn.h"
#define onboardLed 13

//Testen van Jayden
void testFunctionJayden()
{

}

// Testen van keanu
void testFunctionKeanu()
{
  EthernetConn ethernet;
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
