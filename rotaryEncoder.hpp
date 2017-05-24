#ifndef __ROTARY_ENCODER_HPP__
#define __ROTARY_ENCODER_HPP__

#define ROTARY_ENCODER_RIGHT 0
#define ROTARY_ENCODER_LEFT 1
#define ROTARY_ENCODER_MAX 2

void rotaryEncoderInit();
void rotaryEncoderRightIncrement();
void rotaryEncoderLeftIncrement();
unsigned long rotaryEncoderGetRight();
unsigned long rotaryEncoderGetLeft();

#endif
