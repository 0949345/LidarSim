#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#define onboardLed 13


//Testen van Jayden
void testFunctionJayden(){
  String test = "testing";
  Header classHeader;
  Serial.println("test");
  classHeader.generateHeader(8);
  Serial.println(classHeader.getHeader().datagram_marker);
  Serial.println(classHeader.getHeader().protocol);
  Serial.println(classHeader.getHeader().version);
  Serial.println(classHeader.getHeader().length);
}

// Testen van keanu
void testFunctionKeanu(){
Body b(2);
b.generateBeams(9);
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
