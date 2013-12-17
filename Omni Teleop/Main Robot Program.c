#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTMotor,  HTMotor)
#pragma config(Motor,  mtr_S3_C1_1,     lifterMotor1,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S3_C1_2,     flagRaiserMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     rightFrontMotor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C2_2,     rightBackMotor, tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S3_C3_1,     flywheelMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C3_2,     lifterMotor2,  tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S3_C4_1,     leftBackMotor, tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C4_2,     leftFrontMotor, tmotorTetrix, openLoop)

#include "JoystickDriver.c"


task main()
{
	int threshold = 20;
	nMotorEncoder[lifterMotor1] = 0;
	nMotorEncoder[lifterMotor2] = 0;

	while(true)
	{
    getJoystickSettings(joystick);
    float joystick_x1 = joystick.joy1_x1/1.0;
    float joystick_y1 = joystick.joy1_y1/-1.0;
    float joystick_x2 = joystick.joy1_x2/1.0;
    float rightFrontMotorPower = (joystick_y1*0.4) + (joystick_x1*0.4) + (joystick_x2*0.2); // Made each wheel have a compilation
		float leftBackMotorPower   = (joystick_y1*0.4) + (joystick_x1*0.4) - (joystick_x2*0.2); // of all the joysticks as its power
		float leftFrontMotorPower  = (joystick_y1*0.4) - (joystick_x1*0.4) - (joystick_x2*0.2); // so that it can turn and move in
		float rightBackMotorPower  = (joystick_y1*0.4) - (joystick_x1*0.4) + (joystick_x2*0.2); // any direction at the same time.

   	if(abs(joystick.joy1_x1) > threshold || abs(joystick.joy1_y1) > threshold || abs(joystick.joy1_x2) > threshold)
    {
    	motor[rightBackMotor]  = rightBackMotorPower;
    	motor[leftFrontMotor]  = leftFrontMotorPower;
    	motor[rightFrontMotor] = rightFrontMotorPower;
    	motor[leftBackMotor]   = leftBackMotorPower;
    }
		else
		{
    	motor[rightFrontMotor] = 0;
    	motor[leftBackMotor]   = 0;
    	motor[leftFrontMotor]  = 0;
    	motor[rightBackMotor]  = 0;
    }
  	/*if(joy1Btn(02) == 1)
    {
     	motor[flywheelMotor] = 100;
    }
    else if(joy1Btn(02) == 0)
    {
    	motor[flywheelMotor] = 0;
    }*/
    if(joy1Btn(03) == 1)
    {
    	motor[flagRaiserMotor] = 100;
    }
    else if(joy1Btn(03) == 0)
    {
    	motor[flagRaiserMotor] = 0;
    }
		/*if(joy1Btn(04) == 1 && nMotorEncoder[lifterMotor1] >= 0)
		{
    	motor[lifterMotor1] = 75;
    	motor[lifterMotor2] = 75;
		}
		if(joy1Btn(01) == 1 && nMotorEncoder[lifterMotor1] <= 1755)
		{
			motor[lifterMotor1] = -75;
    	motor[lifterMotor2] = -75;
		}
		else if(joy1Btn(04) == 0 && joy1Btn(01) == 0)
		{
    	motor[lifterMotor1] = 0;
    	motor[lifterMotor2] = 0;
    }*/
    if(joy1Btn(06) == 1) // && nMotorEncoder[lifterMotor1] <= 1755
    {
    	motor[lifterMotor1] = -35;
    }
    else if(joy1Btn(08) == 1)
    {
    	motor[lifterMotor1] = 35;
    }
    else if(joy1Btn(06) == 0 && joy1Btn(08) == 0)
    {
    	motor[lifterMotor1] = 0;
    }

    if(joy1Btn(05) == 1)
    {
    	motor[lifterMotor2] = -35;
    }
    else if(joy1Btn(07) == 1)
    {
    	motor[lifterMotor2] = 35;
    }
    else if(joy1Btn(05) == 0 && joy1Btn(07) == 0)
    {
    	motor[lifterMotor2] = 0;
    }
 	}
}
