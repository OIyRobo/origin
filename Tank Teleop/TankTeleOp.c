#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Sensor, S2,     ir,             sensorI2CCustom)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     color,          sensorCOLORFULL)
#pragma config(Motor,  motorA,          blockMotor1,   tmotorNXT, PIDControl)
#pragma config(Motor,  motorB,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorC,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorFL,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorBR,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     motorFlag,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorLift,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorFlywheel, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorL,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "JoystickDriver.c"

task main()
{

	waitForStart();
	bool holdServo = true;

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

		//front spinner
		if (joy1Btn(5) == 1)
		{
			motor[motorFlywheel] = 100;
		}
		else if (joy1Btn(6) == 1)
		{
			motor[motorFlywheel] = -100;
		}
		else
		{
			motor[motorFlywheel] = 0;
		}

		if (joy1Btn(2) == 1) {
			if (holdServo)
				holdServo = false;
			else
				holdServo = true;
		}
		//lifting mechanism mapped to triggers. Left goes up, Right goes down.
		if(joy1Btn(7) == 1){
			motor[motorLift] = -100;
		}
		else if(joy1Btn(8) == 1){
			motor[motorLift] = 100;
		}
		else{
			motor[motorLift] = 0;
		}
		//flag raising mechanism mapped to A+B
		if(joy1Btn(2) == 1){
			motor[motorFlag] = -100;
		}
		else if(joy1Btn(3) == 1){
			motor[motorFlag] = 100;
		}
		else{
			motor[motorFlag] = 0;
		}
		//servo
		/*	if (holdServo)
		servo[blockServo] = 127;
		else
		servo[blockServo] = 0;
		wait1Msec(4); //200 updates/second, more than enough...

		*/
	}
}