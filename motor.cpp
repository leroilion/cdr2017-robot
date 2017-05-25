#include <Arduino.h>
#include "motor.hpp"
#include "pinout.hpp"

void motorInit()
{
    pinMode(RIGHT_MOTOR_PWM , OUTPUT);
    pinMode(LEFT_MOTOR_PWM, OUTPUT);
    pinMode(AHEAD_RIGHT_RELAY, OUTPUT);
    pinMode(AHEAD_LEFT_RELAY, OUTPUT);
    pinMode(BEHIND_RIGHT_RELAY, OUTPUT);
    pinMode(BEHIND_LEFT_RELAY, OUTPUT);
}

void motorSetDirection(motorDirection direction)
{
    switch(direction)
    {
        case FRONT:
            digitalWrite(BEHIND_RIGHT_RELAY, LOW);
            digitalWrite(BEHIND_LEFT_RELAY, LOW);
            digitalWrite(AHEAD_RIGHT_RELAY, HIGH);
            digitalWrite(AHEAD_LEFT_RELAY, HIGH);
            break;
        case BACK:
            digitalWrite(AHEAD_RIGHT_RELAY, LOW);
            digitalWrite(AHEAD_LEFT_RELAY, LOW);
            digitalWrite(BEHIND_RIGHT_RELAY, HIGH);
            digitalWrite(BEHIND_LEFT_RELAY, HIGH);
            break;
        case RIGHT:
            digitalWrite(AHEAD_RIGHT_RELAY, LOW);
            digitalWrite(BEHIND_LEFT_RELAY, LOW);
            digitalWrite(AHEAD_LEFT_RELAY, HIGH);
            digitalWrite(BEHIND_RIGHT_RELAY, HIGH);
            break;
        case LEFT:
            digitalWrite(AHEAD_LEFT_RELAY, LOW);
            digitalWrite(BEHIND_RIGHT_RELAY, LOW);
            digitalWrite(AHEAD_RIGHT_RELAY, HIGH);
            digitalWrite(BEHIND_LEFT_RELAY, HIGH);
            break;
        case NONE:
            digitalWrite(AHEAD_RIGHT_RELAY, LOW);
            digitalWrite(AHEAD_LEFT_RELAY, LOW);
            digitalWrite(BEHIND_RIGHT_RELAY, LOW);
            digitalWrite(BEHIND_LEFT_RELAY, LOW);
            break;
    }
}

void motorSetSpeed(unsigned int right, unsigned int left)
{
    analogWrite(RIGHT_MOTOR_PWM, right);
    analogWrite(LEFT_MOTOR_PWM, left);
}
