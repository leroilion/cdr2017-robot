#include <Arduino.h>
#include "pinout.hpp"
#include "rotaryEncoder.hpp"

static unsigned long rotaryEncoderTick[ROTARY_ENCODER_MAX];
static unsigned long rotaryEncoderPartial[ROTARY_ENCODER_MAX];

void rotaryEncoderInit()
{
    for( int i = 0; i < ROTARY_ENCODER_MAX; i++)
    {
        rotaryEncoderTick[i] = 0;
    }
    pinMode(RIGHT_ROTARY_ENCODER, OUTPUT);
    pinMode(LEFT_ROTARY_ENCODER, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(RIGHT_ROTARY_ENCODER), rotaryEncoderRightIncrement, CHANGE);
    attachInterrupt(digitalPinToInterrupt(LEFT_ROTARY_ENCODER), rotaryEncoderLeftIncrement, CHANGE);
}

void rotaryEncoderRightIncrement()
{
    rotaryEncoderTick[ROTARY_ENCODER_RIGHT] += 1;
}

void rotaryEncoderLeftIncrement()
{
    rotaryEncoderTick[ROTARY_ENCODER_LEFT] += 1;
}

unsigned long rotaryEncoderGetRight()
{
    return rotaryEncoderTick[ROTARY_ENCODER_RIGHT];
}

unsigned long rotaryEncoderGetLeft()
{
    return rotaryEncoderTick[ROTARY_ENCODER_LEFT];
}

void rotaryEncoderResetPartial(unsigned short encoder)
{
    if( encoder < ROTARY_ENCODER_MAX)
    {
        rotaryEncoderPartial[encoder] = rotaryEncoderTick[encoder];
    }
}

unsigned long rotaryEncoderGetPartial(unsigned short encoder)
{
    if( encoder < ROTARY_ENCODER_MAX)
    {
        return rotaryEncoderTick[encoder] - rotaryEncoderPartial[encoder];
    }
}
