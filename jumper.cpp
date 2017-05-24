#include <Arduino.h>
#include "pinout.hpp"
#include "jumper.hpp"

void jumperInit()
{
    pinMode(JUMPER, INPUT);
}

boolean jumperIsPresent()
{
    return digitalRead(JUMPER);
}

void jumperWaitPresent()
{
    while( digitalRead(JUMPER) ) {};
}

void jumperWaitUnpresent()
{
    while( ! digitalRead(JUMPER) ) {};
}
