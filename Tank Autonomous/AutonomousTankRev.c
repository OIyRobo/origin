#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     color,          sensorCOLORFULL)
#pragma config(Sensor, S3,     ir,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          blockMotor,    tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
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

void init()//updates sensors
{
	StartTask(updateGyro);
	StartTask(updateIR);
	wait1Msec(300);
}

task main()
{
	waitForStart();
	init();

	ClearTimer(T2);
	while (getZone() != 8) { //drives until IR sensor
		if (time1(T2) < 200)
			move(time1(T2) / -8);
	}
	int time = time1(T2);

	if (time < 1500) {
		move(-25);
		wait1Msec(100);
		move(0);
		time -= 500; //overdrive correction
	}
	else { time -= 600;}
	move(0);

	motor[blockMotor] = 70;
	wait1Msec(500);
	motor[blockMotor] = -100;
	wait1Msec(700);
	motor[blockMotor] = 0; //places block

	ClearTimer(T2);
	while (time1(T2) < time ) {
		if (time1(T2) < 200)
			move(time1(T2) / 8);
	}
	move(0); //drives by the timer in reverse

	turn(-45);
	move(50);
	wait1Msec(500);
	turn(-45); //45 degree turns toward the ramp

	while(getColor() != WHITE) {
		move(50);
	} //moves until the white line

	turn(90);
	move(-100);
	wait1Msec(1200);

}
