#include <Arduino.h>
#include "pinout.hpp"
#include "ultrasound.hpp"

void ultrasoundInit()
{
    pinMode(US_ECHO, INPUT);
    pinMode(US_TRIGGER, OUTPUT);
    digitalWrite(US_TRIGGER, LOW);
}

unsigned long ultrasoundMeasureDistance()
{
    digitalWrite(US_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIGGER, LOW);
    unsigned long duration = pulseIn(US_ECHO, HIGH, 20000);
    return duration / 58;
}

unsigned long ultrasoundGetAverageDistance()
{
    unsigned long distances[ULTRASOUND_MAX_AVERAGE] = {0};

    for( int i = 0; i < ULTRASOUND_MAX_AVERAGE; i++ )
    {
        distances[i] = ultrasoundMeasureDistance();
        delay(20);
    }

    unsigned int min = 0, max = 0;

    // Search min and max values
    for( int i = 0; i < ULTRASOUND_MAX_AVERAGE; i++ )
    {
        if( distances[i] < distances[min] )
            min = i;

        if( distances[i] > distances[max] )
            max = i;
    }

    unsigned long avgDistance = 0;
    // Get average deleting min and max
    for( int i = 0; i < ULTRASOUND_MAX_AVERAGE; i++ )
    {
        if( i != min && i != max )
            avgDistance += distances[i];
    }

    return avgDistance / (ULTRASOUND_MAX_AVERAGE - 2);
}
