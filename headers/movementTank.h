#ifndef MOVEMENT_STANDARD_H
#define MOVEMENT_STANDARD_H
#pragma systemFile

void move(int power, int time);
void turn(int power, int offset);//positive offset goes clockwise, negative counterclockwise.
void turn(int degrees);

#include "..\lib\movementTank.c"
#endif
