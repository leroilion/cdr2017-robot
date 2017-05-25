#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    Serial.print(F("VERSION : "));
    Serial.println(F(VERSION));
}

void loop()
{
}
