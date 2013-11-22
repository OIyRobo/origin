#ifndef MOVEMENT_OMNI_H
#define MOVEMENT_OMNI_H

const int RIGHT = 1;
const int LEFT = 2;
const int FORWARD = 3;
const int BACKWARDS = 4;

void move(int dir, int power, int time);
void move(int dir, int power);
void turn(int degrees);
void brake();
void fixDrift(int corrAngle, int direction, int power);

#include "..\lib\movementOmni.c"
#endif
