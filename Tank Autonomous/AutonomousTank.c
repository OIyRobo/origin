#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     color,          sensorCOLORFULL)
#pragma config(Sensor, S3,     ir,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,          blockMotor,    tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorFlag,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorFlywheel, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorL,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/* ASCI Generated by Kieran :D */
/*
 			   										   	  _______________________
                                                         /\  ___________________ \
                                                         \ \ \_________________/\ \
  _____       _____      __      __________    _______    \ \ \         __     \ \ \     __________    _____     _______     ________
 /\  __ \    /\  __\    /\ \    /\____  ___\  /\  ___ \    \ \ \       / \\     \ \ \   /\____  ___\  /\  __\   /\  ___ \   /\   \   \
 \ \ \ \ \   \ \ \_/    \ \ \   \/___/\ \__/  \ \ \_/\ \    \ \ \      \ \  \    \ \ \  \/___/\ \__/  \ \ \_/   \ \ \_/\ \  \ \ \ \ \ \
  \ \ \ \ \   \ \ \__    \ \ \       \ \ \     \ \ \\_\ \    \ \ \     \ \ __ \   \ \ \      \ \ \     \ \ \__   \ \ \\_\ \  \ \ \___\ \
   \ \ \ \ \   \ \  _\    \ \ \       \ \ \     \ \  ___ \    \ \ \    \ \ \/\  \  \ \ \      \ \ \     \ \  _\   \ \  __  \  \ \ \__/\ \
    \ \ \_\ \   \ \ \/__   \ \ \___    \ \ \     \ \ \_/\ \    \ \ \   \ \ \_\_\  \ \ \ \      \ \ \     \ \ \/__  \ \ \_/\ \  \ \ \ \ \ \
     \ \____/    \ \____\   \ \____\    \ \_\     \ \_\\ \_\  	\ \ \  \ \__________\\ \ \      \ \_\     \ \____\  \ \_\\ \_\  \ \_\ \ \_\
      \/___/      \/____/    \/____/     \/_/      \/_/ \/_/     \ \ \ \/__________/  \ \ \      \/_/      \/____/   \/_/ \/_/   \/_/  \/_/
                                                                  \ \ \________________\_\ \
                         	     				   				   \ \______________________\
  																	\/______________________/

*/
#include "JoystickDriver.c"
#include "..\headers\gyro.h"
#include "..\headers\servo.h"
#include "..\headers\ir.h"
#include "..\headers\movementTank.h"
//#include "headers\movementOmni.h"
#include "..\headers\color.h"

void init()
{
	StartTask(updateGyro);
	StartTask(updateIR);
	wait1Msec(300);
}

task main()
{

	//waitForStart();
	init();

	//move to color line
	while (getColor() != RED && getColor() != BLUE) {
		move(50);
	}

	ClearTimer(T2);
	while (getZone() != 8 && time1(T2) < 2000) {
		if (getColor() == RED || getColor() == BLUE) {
			motor[motorFR] = 0;
			motor[motorBR] = 0;
			motor[motorFL] = 50;
			motor[motorBL] = 50;
		}
		else {
			motor[motorFR] = 50;
			motor[motorBR] = 50;
			motor[motorFL] = 0;
			motor[motorBL] = 0;
		}
	}

	turn(-getGyroAngle());

	motor[blockMotor] = 100;
	wait1Msec(1000);
	motor[blockMotor] = -100;
	wait1Msec(700);

	ClearTimer(T2);
	while (time1(T2) < 2000) {
		if (getColor() == RED || getColor() == BLUE) {
			motor[motorFR] = -10;
			motor[motorBR] = -10;
			motor[motorFL] = -50;
			motor[motorBL] = -50;
		}
		else {
			motor[motorFR] = -50;
			motor[motorBR] = -50;
			motor[motorFL] = -10;
			motor[motorBL] = -10;
		}
	}

}
