#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#include "../lib/EthernetProtocol/EthernetProtocol.h"
#define onboardLed 13

//Testen van Jayden
void testFunctionJayden()
{
  EthernetProtocol Ep;
  Ep.generate(6);
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
