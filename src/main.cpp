#include <Arduino.h>
#define onboardLed 13

void setup()
{
  Serial.begin(9600);
  pinMode(onboardLed, OUTPUT);
  Serial.println("Leggoooooo");
  
}
void loop()
{
  digitalWrite(onboardLed, LOW);
  delay(1000);
  digitalWrite(onboardLed, HIGH);
  delay(1000);
  Serial.println("Ghello World! LilBish");
}
