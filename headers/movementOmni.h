#ifndef MOVEMENT_OMNI_H
#define MOVEMENT_OMNI_H

const int RIGHT = 1;
const int LEFT = 2;
const int FORWARD = 3;
const int BACKWARDS = 4;
const int FWDRIGHT = 5;
const int FWDLEFT = 6;
const int BACKRIGHT = 7;
const int BACKLEFT = 8;

//Adjust angle slightly for line following
const int ADJFWDRIGHT = 5;
const int ADJFWDLEFT = 6;
const int ADJBACKRIGHT = 7;
const int ADJBACKLEFT = 8;

void move(int dir, int power);
void turn(int degrees);
void brake();
void fixDrift(int corrAngle, int direction, int power);

#include "..\lib\movementOmni.c"
#endif
