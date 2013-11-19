#ifndef GYRO_H
#define GYRO_H

/*

 _________    __     __    _______     ________
/\  ______\  /\ \   /\ \  /\  ____ \  /\  ___  \
\ \ \_____/  \ \ \__\_\ \ \ \ \__/\ \ \ \ \__/\ \
 \ \ \  ____  \ \___  ___\ \ \ \_\_\ \ \ \ \ \ \ \
  \ \ \/\___ \ \/__/\ \__/  \ \  __  _\ \ \ \ \ \ \
   \ \ \/__/\ \    \ \ \     \ \ \/\_\/  \ \ \ \ \ \
    \ \ \__\_\ \    \ \ \     \ \ \//\_\_ \ \ \_\_\ \
     \ \________\    \ \_\     \ \_\\//\_\ \ \_______\
      \/________/     \/_/      \/_/  \/_/  \/_______/

*/

float cur_vel = 0;
float angle = 0;//global to store rotation... Otherwise the main task cannot see the angle from the gyroTask

float getGyroAngle();
float getGyroOffset();
void zeroGyro();
task updateGyro();


#include "..\lib\gyro.c"
#endif // GYRO_H
