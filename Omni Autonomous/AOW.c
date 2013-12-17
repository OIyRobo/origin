#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     color,          sensorCOLORFULL)
#pragma config(Sensor, S2,     ir,             sensorI2CCustom)
#pragma config(Sensor, S3,     ,               sensorI2CMuxController)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,          ,    tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,           motorBlock,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     motorD,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C4_1,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C4_2,     motorFL,       tmotorTetrix, openLoop, reversed)
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
//#include "headers\movementTank.h"
#include "..\headers\movementOmni.h"
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
	wait10Msec(1000);
	init();
	ClearTimer(T2);
	while(getColor() != RED && getColor() != BLUE && getZone() != 2 && getZone() != 8){
		move(0, 100);
	}

	while (getColor() != GREY)
		move(-45, 75);

	while (getZone() != 2 && getZone() != 8) {
		if (getColor() == RED || getColor() == BLUE)
			move(-35, 50);
		else
			move(35, 50);
	}

	move(0, 50);
	if (time1(T2) > 2000)
		wait1Msec(400);
	else if (time1(T2) > 1000)
		wait1Msec(500);
	else
		wait1Msec(300);

	turn(-getGyroAngle());
	move(90, 50);
	wait1Msec(300);
	brake();

	motor[motorBlock] = -100;
	wait1Msec(550);
	motor[motorBlock] = 100;
	wait1Msec(1000);
	motor[motorBlock] = 0;

	move(-90, 50);
	wait1Msec(350);
	ClearTimer(T3);
	while (time1(T3) < 1000) {
		if (getColor() == RED || getColor() == BLUE) {
			move(210, 50);
			ClearTimer(T3);
		}
		else
			move(150, 50);
	}
	brake();
	//wait1Msec(300);
	turn(-getGyroAngle());
	while (getColor() != WHITE) {
		move(90, 50);
	}
	wait1Msec(400);
	turn(-getGyroAngle());
	move(0,100);
	wait1Msec(2000);
	brake();

}
