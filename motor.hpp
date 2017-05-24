#ifndef __MOTOR_HPP__
#define __MOTOR_HPP__

enum motorDirection {FRONT, BACK, RIGHT, LEFT, NONE};

void motorInit();
void motorSetDirection(motorDirection direction);
void motorSetSpeed(unsigned int right, unsigned int left);

#endif
