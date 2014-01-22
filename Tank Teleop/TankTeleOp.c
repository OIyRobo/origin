#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     color,          sensorCOLORFULL)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicColor)
#pragma config(Sensor, S4,     ir,             sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,          blockMotor,    tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorFR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorBR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     motorSlide,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     a,             tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorFlag,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorArm,      tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main()
{

	waitForStart();

	while(true)                            // Infinite loop:
	{
		getJoystickSettings(joystick); //update joystick values


		//movement
		if (abs(joystick.joy1_y1) > 35)
		{
			//Left motors mapped to joystick 1
			motor[motorFL] = -joystick.joy1_y1;
			motor[motorBL] = -joystick.joy1_y1;
		}
		else
		{
			motor[motorFL] = 0;
			motor[motorBL] = 0;
		}

		if (abs(joystick.joy1_y2) > 35)
		{
			//right motors mapped to joystick 2
			motor[motorFR] = -joystick.joy1_y2;
			motor[motorBR] = -joystick.joy1_y2;
		}
		else
		{
			motor[motorFR] = 0;
			motor[motorBR] = 0;
		}

		//flag raiser
		if (joy1Btn(1))
			motor[motorFlag] = -80;
		else if (joy1Btn(3))
			motor[motorFlag] = 80;
		else
			motor[motorFlag] = 0;

		//arm
		if (joy2Btn(6))
			motor[motorArm] = -100;
		else if (joy2Btn(8))
			motor[motorArm] = 50;
		else
			motor[motorArm] = 0;

		//slide
		if (joy2Btn(7))
			motor[motorSlide] = 50;
		else if (joy2Btn(5))
			motor[motorSlide] = -50;
		else
			motor[motorSlide] = 0;

	}
}
