#include <Arduino.h>
#include "pinout.hpp"
#include "rotaryEncoder.hpp"
#include "motor.hpp"
#include "movement.hpp"

void movementGoFront(unsigned int distance)
{
    rotaryEncoderResetPartial(ROTARY_ENCODER_RIGHT);
    rotaryEncoderResetPartial(ROTARY_ENCODER_LEFT);
    motorSetDirection(FRONT);
    motorSetSpeed(MOVEMENT_HIGH_SPEED, MOVEMENT_HIGH_SPEED);

    while(rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) < distance && rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) < distance)
    {
        if( rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) > rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) )
        {
            motorSetSpeed(MOVEMENT_LOW_SPEED, MOVEMENT_HIGH_SPEED);
        }
        else if( rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) < rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) )
        {
            motorSetSpeed(MOVEMENT_HIGH_SPEED, MOVEMENT_LOW_SPEED);
        }
        delay(20);
    }

    motorSetSpeed(0, 0);
    motorSetDirection(NONE);
}

void movementGoBack(unsigned int distance)
{
    rotaryEncoderResetPartial(ROTARY_ENCODER_RIGHT);
    rotaryEncoderResetPartial(ROTARY_ENCODER_LEFT);
    motorSetDirection(BACK);
    motorSetSpeed(MOVEMENT_HIGH_SPEED, MOVEMENT_HIGH_SPEED);

    while(rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) < distance && rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) < distance)
    {
        if( rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) > rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) )
        {
            motorSetSpeed(MOVEMENT_LOW_SPEED, MOVEMENT_HIGH_SPEED);
        }
        else if( rotaryEncoderGetPartial(ROTARY_ENCODER_RIGHT) < rotaryEncoderGetPartial(ROTARY_ENCODER_LEFT) )
        {
            motorSetSpeed(MOVEMENT_HIGH_SPEED, MOVEMENT_LOW_SPEED);
        }
        delay(20);
    }

    motorSetSpeed(0, 0);
    motorSetDirection(NONE);
}

void movementTurnRight(unsigned int angle)
{
}

void movementTurnLeft(unsigned int angle)
{
}
