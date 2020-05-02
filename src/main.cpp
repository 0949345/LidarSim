#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#include "../lib/EthernetProtocol/EthernetProtocol.h"
#define onboardLed 13

//Testen van Jayden
void testFunctionJayden()
{
  String test = "testing";
  Header classHeader;
  Serial.println("Header:");
  classHeader.generateHeader(8);
  Serial.println(classHeader.getHeader().datagram_marker);
  Serial.println(classHeader.getHeader().protocol);
  Serial.println(classHeader.getHeader().version);
  Serial.println(classHeader.getHeader().length);
  Serial.println("=================\n");
  Serial.println("Body:");
  Body classBody(1);
  classBody.generateBeams(6);
  Serial.println("=================\n");
}

// Testen van keanu
void testFunctionKeanu()
{
  EthernetProtocol ethernet;
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
