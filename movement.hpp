#ifndef __MOVEMENT_HPP__
#define __MOVEMENT_HPP__

#define MOVEMENT_HIGH_SPEED 180
#define MOVEMENT_LOW_SPEED 90

void movementGoFront(unsigned int distance);
void movementGoBack(unsigned int distance);
void movementTurnRight(unsigned int angle);
void movementTurnLeft(unsigned int angle);

#endif
