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
float cur_vel = 0;//global variable to store the current angular velocity of the robot
float angle = 0;//global to store rotation... Otherwise the main task cannot see the angle from the gyroTask

//Returns the current angular position in degrees
float getGyroAngle();

//finds the gyro offset in order to calibrate the gyro, can only be used while the robot is sitting still.
float getGyroOffset();

//sets angular position
void zeroGyro();

//task that runs an update loop that reads the gyro's velocity and integrates to find angular position
task updateGyro();


#include "..\lib\gyro.c"
#endif // GYRO
