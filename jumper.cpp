#include <Arduino.h>
#include "pinout.hpp"
#include "jumper.hpp"

void jumperInit()
{
    pinMode(JUMPER, INPUT);
}
