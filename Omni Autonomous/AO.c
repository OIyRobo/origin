#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     color,          sensorCOLORFULL)
#pragma config(Sensor, S2,     ir,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,          motorBlock,    tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S3_C1_1,     liftMotor1,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_1,     motorH,        tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_2,     liftMotor2,    tmotorTetrix, openLoop)
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

	//raising lift
	motor[liftMotor1] = -50;
	motor[liftMotor2] = -50;
	wait1Msec(200);
	motor[liftMotor1] = 0;
	motor[liftMotor2] = 0;
}

task main()
{
  waitForStart();
	init();

	ClearTimer(T3); //timing for safety net
	ClearTimer(T2); //timing for IR correction
	//moving untill colored line or IR is seen
	while(getColor() != RED && getColor() != BLUE && getZone() != 2 && getZone() != 8){
		if (time1(T3) < 1000)
			move(0, 100);
		else
			move(90, 25);
	}

	//jerking to the left to avoid basket
	move(-45, 75);
	wait1Msec(100);

	ClearTimer(T3);
	//line following until you reach IR
	while (getZone() != 2 && getZone() != 8 && time1(T3) < 10000) {
		if (getColor() == RED || getColor() == BLUE)
			move(-35, 50);
		else
			move(35, 50);
	}

	//correcting for IR placement
	move(0, 50);
	if (time1(T2) > 2000)
		wait1Msec(300);
	else if (time1(T2) > 1000)
		wait1Msec(500);
	else
		wait1Msec(400);

	//moving closer to basket
	turn(-getGyroAngle());
	move(90, 50);
	wait1Msec(350);
	brake();

	//dump block by rotating motor forward and back.
	motor[motorBlock] = -100;
	wait1Msec(650);
	motor[motorBlock] = 100;
	wait1Msec(1000);
	motor[motorBlock] = 0;

	//backwards line following that moves on and off the line
	move(-90, 50); //moving away from baskets
	wait1Msec(350);
	ClearTimer(T2);
	ClearTimer(T3);
	while (time1(T2) < 1600 && time1(T3) < 10000) {
		if (getColor() == RED || getColor() == BLUE) {
			move(210, 50);
			ClearTimer(T2);
		}
		else
			move(150, 50);
	}
	brake();

	//moving to white line
	//wait1Msec(300);
	ClearTimer(T3);
	turn(-getGyroAngle());
	while (getColor() != RED && getColor() != BLUE && time1(T3) < 5000) {
		move(90, 50);
	}

	//move onto ramp
	turn(-getGyroAngle());
	ClearTimer(T2);
	int rampTime = 2700;
	while (time1(T2) < rampTime) {
		if (abs(getGyroAngle()) > 15) {
			turn(-getGyroAngle());
			rampTime = time1(T2) + 1000;
		}
		move(-getGyroAngle() + 5,50);
	}
	brake();
}//we win.
