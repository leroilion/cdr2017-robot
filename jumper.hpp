#ifndef __JUMPER_HPP__
#define __JUMPER_HPP__

#define JUMPER_TIMER_INTERVAL 50000
#define JUMPER_WAIT_TIME_MS 90000000UL
#define JUMPER_WAIT_TICK (JUMPER_WAIT_TIME_MS/JUMPER_TIMER_INTERVAL)

void jumperInit();
boolean jumperIsPresent();
void jumperWaitPresent();
void jumperWaitUnpresent();
void jumperTimerHandler();
void jumperStartTimer();
void jumperStopTimer();

#endif
