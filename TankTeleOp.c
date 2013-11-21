#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  HTMotor)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     motorBL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     motorBR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     motorFL,       tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_2,     motorFR,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_1,     motorCube,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C4_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C3_6,    servo6,               tServoNone)
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

	//front spinner
	if (joy1Btn(5) == 1)
  	{
	motor[motorCube] = 100;
	}
	else if (joy1Btn(6) == 1)
	{
		motor[motorCube] = -100;
	}
	else
	{
		motor[motorCube] = 0;
	}
	wait1Msec(4); //200 updates/second, more than enough...
  }
}
