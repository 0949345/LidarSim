#include <Arduino.h>
#include "../lib/Header/Header.h"
#include "../lib/Body/Body.h"
#define onboardLed 13

void setup()
{
  Serial.begin(9600);
  pinMode(onboardLed, OUTPUT);
  Serial.println("Leggoooooo");
  
}


//Testen van Jayden
void testFunctionJayden(){
  Header classHeader;
  Serial.println(classHeader.getHeader().version);
}

// Testen van keanu
void testFunctionKeanu(){

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
