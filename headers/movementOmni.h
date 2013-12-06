#ifndef MOVEMENT_OMNI_H
#define MOVEMENT_OMNI_H

const int NE = 0;
const int NW = 1;
void move(float theta, int maxPower);
//void turn(int degrees);
void brake();
void maximizePower(float *powers, int power); //Maximizes the powers on the motors for translating at maximum speed. The powers array is passed by reference.

#include "..\lib\movementOmni.c"
#endif
