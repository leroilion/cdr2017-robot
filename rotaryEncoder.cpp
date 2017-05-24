#include <Arduino.h>
#include "pinout.hpp"
#include "rotaryEncoder.hpp"

static unsigned long rightTick = 0;
static unsigned long leftTick = 0;

void rotaryEncoderInit()
{
    pinMode(RIGHT_ROTARY_ENCODER, OUTPUT);
    pinMode(LEFT_ROTARY_ENCODER, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ROTARY_ENCODER), rotaryEncoderRightIncrement, CHANGE);
    attachInterrupt(digitalPinToInterrupt(LEFT_ROTARY_ENCODER), rotaryEncoderLeftIncrement, CHANGE);
}

void rotaryEncoderRightIncrement()
{
    rightTick++;
}

void rotaryEncoderLeftIncrement()
{
    leftTick++;
}

unsigned long rotaryEncoderGetRight()
{
    return rightTick;
}

unsigned long rotaryEncoderGetLeft()
{
    return leftTick;
}
