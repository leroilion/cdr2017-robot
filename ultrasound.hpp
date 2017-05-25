#ifndef __ULTRASOUND_HPP__
#define __ULTRASOUND_HPP__

#define ULTRASOUND_MAX_AVERAGE 5

void ultrasoundInit();
unsigned long ultrasoundMeasureDistance();
unsigned long ultrasoundGetAverageDistance();

#endif
