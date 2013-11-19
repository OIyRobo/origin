#ifndef IR_H
#define IR_H
#include <hitechnic-irseeker-v2.h>


int zone; //global zone / angle variable
int getZone(); //returns active zone (1-9);
int getSide();//gets angle to bacon... I mean beacon.
task updateIR();//runs loop that continuously takes readings from the ir sensor.

#include "..\lib\ir.c"
#endif // IR_H
