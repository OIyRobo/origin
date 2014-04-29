#pragma config(Hubs,  S1, HTMotor,  none,     none,     none)
#pragma config(Sensor, S1,     ,               sensorI2CMuxController)
#pragma config(Motor,  mtr_S1_C1_1,     drive,         tmotorTetrix, PIDControl, reversed, encoder)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int target = 0;

task P();
task Display();
bool aligned = false;
float rate = 0;
float conv = -1000.0/0.405;
float error;
/*<-------DONT DELETE THIS ASTERISK PLEASE~!!!1!111111 OR THIS ONE ----->*/
//THIS IS THE BEST CODE THAT HAS BEEN WRITTEN
task main()
{
	bool isInMenu = true;
	float distance = 0;
	while(isInMenu){
		nxtDisplayCenteredTextLine(3, "Distance: %.1f", distance);
		if(nNxtButtonPressed == 1){
			distance+=0.5;
		}
		else if(nNxtButtonPressed == 2){
			distance-=0.5;
		}
		else if(nNxtButtonPressed == 3){
			nxtDisplayCenteredBigTextLine(3, "LAUNCH");
			isInMenu = false;
		}
		wait1Msec(250);
	}
	nMotorEncoder[drive] = 0;
	StartTask(Display);
	target = distance * conv;
	wait1Msec(100);
	StopTask(P);
	wait10Msec(100);
	motor[drive] = 0;
	StopTask(Display);
}

task Display()
{
	while (true)
	{
		nxtDisplayCenteredTextLine(1, "Error  : %.2f", error);
		nxtDisplayCenteredTextLine(2, "Rate   : %.2f", rate);
		nxtDisplayCenteredTextLine(3, "Aligned: %d", aligned);
		nxtDisplayCenteredTextLine(4, "Target : %d", target);
		wait1Msec(100);
	}
}

task P()
{
	float prevTime;
	float prevError;
	float time;
	float kP = .07;
	float kD = 1;
	aligned = false;
	time1[T1] = 0;
	error = target - nMotorEncoder[drive];
	while(true)
	{
		prevTime = time;
		prevError = error;
		time = time1[T1];
		error = target - nMotorEncoder[drive];
		rate = (error - prevError)/(time - prevTime);
		if (abs(error) > 20 || abs(rate) > 10)
		{
			if (error < 1000)
				kP = .03;
			motor[drive] = kP * error;
			aligned = false;
		}
		else
		{
			aligned = true;
			nxtDisplayCenteredBigTextLine(3, "BROKEN");
	  }
		wait1Msec(100);
	}
}