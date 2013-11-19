#ifndef MOVEMENT_OMNI_H
#define MOVEMENT_OMNI_H

const int RIGHT = 1;
const int LEFT = 2;
const int FORWARD = 3;
const int BACKWARDS = 4;

void move(int dir, int power, int time);
void turn(int degrees);

#include "..\lib\movementOmni.c"
#endif
