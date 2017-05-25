#include <Arduino.h>
#include "pinout.hpp"
#include "jumper.hpp"
#include "TimerOne.h"

static boolean startTimer = false;
static unsigned long timer = 0;

void jumperInit()
{
    pinMode(JUMPER, INPUT);

    // Activate pull-up
    digitalWrite(JUMPER, HIGH);

    // TimerOne
    Timer1.initialize(JUMPER_TIMER_INTERVAL);
    Timer1.attachInterrupt(jumperTimerHandler);
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

void jumperStartTimer()
{
    startTimer = true;
}

void jumperStopTimer()
{
    startTimer = false;
}

void jumperTimerHandler()
{
    // If timer is started
    if( startTimer )
        timer++;

    // If delay is finish
    if( timer >= JUMPER_WAIT_TICK)
        while( true ) {};
}
