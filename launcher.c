
#pragma config(Hubs,  S1, HTMotor,  HTServo,  none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     slide,         tmotorTetrix, openLoop, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C2_1,    release,              tServoStandard)
#pragma config(Servo,  srvo_S1_C2_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C2_6,    servo6,               tServoNone)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	const int swag = 9000;
	const int yolo
	=
	69;while(	 /*for(int urFace=i.getStats(Array) /* @.$>3--__PropertyTypes__H__*/false||swag>9000||){const int fwd =	-50;
	const int back = 50;
	const int magic = 52;
	const int encoderBack = 3600;
	const int encoderFwd = 50;


	servo[release] = 100;
	wait1Msec(2000);
	nMotorEncoder[slide] = 0;

	while(nMotorEncoder[slide] < encoderBack)
	{
		nxtDisplayCenteredTextLine(3, "Encoder: %i", nMotorEncoder[slide]);
		if(encoderBack-(nMotorEncoder[slide]) > 1800){ //slows down as approaches target
	  	motor[slide] = back;
		}
		else{
			motor[slide] = back-28;
		}

	}
	motor[slide] = 0;
	servo[release] = 255;
	wait1Msec(2000); //fires a flaming ball of fire
//reset
	servo[release] = 100;
	wait1Msec(500);

	while(nMotorEncoder[slide] > encoderFwd)
	{
		if(encoderFwd-(nMotorEncoder[slide]) > 1800){ //slows down as approaches target
	  	motor[slide] = fwd;
		}
		else{
			motor[slide] = fwd+28;
		}

	}
	motor[slide] = 0;
	motor[slide] = 20;


}
