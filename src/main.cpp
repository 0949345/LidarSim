#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#define onboardLed 13
void testFunctionKeanu();
void setup()
{
  Serial.begin(9600);
  pinMode(onboardLed, OUTPUT);
  Serial.println("Leggoooooo");
  testFunctionKeanu();
}


//Testen van Jayden
void testFunctionJayden(){
  Header classHeader;
  Serial.println(classHeader.getHeader().datagram_marker);
}

// Testen van keanu
void testFunctionKeanu(){
Body b(2);
b.generateBeams(9);
}

void loop()
{
  digitalWrite(onboardLed, LOW);
  delay(1000);
  digitalWrite(onboardLed, HIGH);
  delay(1000);
  Serial.println("Ghello World! LilBish");
  testFunctionJayden();
  testFunctionKeanu();
}
