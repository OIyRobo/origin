#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ir,             sensorI2CCustom)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     color,          sensorCOLORFULL)
#pragma config(Motor,  motorA,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorJ,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorK,        tmotorTetrix, openLoop)
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
#include "headers\gyro.h"
#include "headers\servo.h"
#include "headers\ir.h"
//#include "headers\movementTank.h"
#include "headers\movementOmni.h"
#include "headers\color.h"

void init()
{
	StartTask(updateGyro);
	StartTask(updateIR);
	wait1Msec(300);
}

task main()
{
	init();
	int startTime;
	int endTime;
	int totalTime;
	int corrAngle;

	//moving to IR Beacon & timing
	startTime = nSysTime;
	zeroGyro();
	corrAngle = getGyroAngle();
	move(FORWARD, 100);
	while(zone!=2 && zone !=8){
		fixDrift(corrAngle, FORWARD, 100);
		wait1Msec(4);
	}
	brake();
	endTime = nSysTime;
	totalTime = endTime - startTime;
	wait1Msec(1000);

	if(zone==8){

		//put block

	}
	else if(zone==2){

		//put block

	}

	//moving back to start
	zeroGyro();
	move(BACKWARDS, 100);
	startTime = nSysTime;
	while (nSysTime < startTime + totalTime) {
		fixDrift(corrAngle, BACKWARDS, 100);
		wait1Msec(4);
	}
	brake();
	wait1Msec(1000);
	move(RIGHT, 100);

	//moving to white line
	while( getColor() != WHITE ) {
		fixDrift(corrAnlge, RIGHT, 100);
		wait1Msec(4);
	}
	wait1Msec(300);
	brake();

	//moving onto ramp
	move(FORWARD, 80);
	wait1Msec(3000);
}
