void move(int dir, int power) {
	int offset = 9;
	if (dir == RIGHT) {
		motor[motorFL] = power;
		motor[motorFR] = -power;
		motor[motorBL] = -power;
		motor[motorBR] = power;
	}
	else if (dir == LEFT) {
		motor[motorFL] = -power;
		motor[motorFR] = power;
		motor[motorBL] = power;
		motor[motorBR] = -power;
	}
	else if (dir == FORWARD) {
		motor[motorFL] = power-offset;
		motor[motorFR] = power;
		motor[motorBL] = power-offset;
		motor[motorBR] = power;
	}
	else if (dir == BACKWARDS) {
		motor[motorFL] = -(power);
		motor[motorFR] = -(power-offset);
		motor[motorBL] = -(power);
		motor[motorBR] = -(power-offset);
	}
}

void move(int dir, int power, int time)
{
	int offset;
	ClearTimer(T2);
	while (time1(T2) <= time + offset)
	{
		if (dir == RIGHT) {
			motor[motorFL] = power;
			motor[motorFR] = -power;
			motor[motorBL] = -power;
			motor[motorBR] = power;
		}
		else if (dir == LEFT) {
			motor[motorFL] = -power;
			motor[motorFR] = power;
			motor[motorBL] = power;
			motor[motorBR] = -power;
		}
		else if (dir == FORWARD) {
			motor[motorFL] = power;
			motor[motorFR] = power;
			motor[motorBL] = power;
			motor[motorBR] = power;
		}
		else if (dir == BACKWARDS) {
			motor[motorFL] = -power;
			motor[motorFR] = -power;
			motor[motorBL] = -power;
			motor[motorBR] = -power;
		}
	}
}

void brake() {
	motor[motorFL] = 0;
	motor[motorFR] = 0;
	motor[motorBL] = 0;
	motor[motorBR] = 0;
}

void fixDrift(int corrAngle, int direction, int power) {
	if (direction == FORWARD) {
		if (abs(getGyroAngle() - corrAngle) > 1) {
			if (getGyroAngle() < corrAngle) {
				motor[motorFR] = power-30;
				motor[motorBR] = power-30;
			}
			else if (getGyroAngle() > corrAngle) {
				motor[motorFL] = power - 30;
				motor[motorFL] = power - 30;
			}
		}
		else {
			motor[motorFR] = power;
			motor[motorFL] = power;
			motor[motorBR] = power;
			motor[motorBL] = power;
		}
	}

	if (direction == BACKWARDS) {
		if (abs(getGyroAngle() - corrAngle) > 1) {
			if (getGyroAngle() < corrAngle) {
				motor[motorFR] = -(power-30);
				motor[motorBR] = -(power-30);
			}
			else if (getGyroAngle() > corrAngle) {
				motor[motorFL] = -(power - 30);
				motor[motorFL] = -(power - 30);
			}
		}
		else {
			motor[motorFR] = -power;
			motor[motorFL] = -power;
			motor[motorBR] = -power;
			motor[motorBL] = -power;
		}
	}
}

void turn(int degrees) {
	zeroGyro();
	int power = 20;
	bool starting = true;

	while ( abs(getGyroAngle() - degrees) > .5 || abs(getVel()) > 3)  {
		if (abs((int)(getGyroAngle() - degrees)) < 50)
			power = 15;
		if (abs((int)(getGyroAngle() - degrees)) < 30)
			power = 10;
		if(abs((int)(getGyroAngle() - degrees)) < 10)
			power = 5;
		if (abs(getVel()) < 2)
			power = 13;

		if (getGyroAngle() < degrees) {
			motor[motorFL] = power;
			motor[motorBL] = power;
			motor[motorFR] = -power;
			motor[motorBR] = -power;
		}
		else if (getGyroAngle() > degrees){
			motor[motorFL] = -power;
			motor[motorBL] = -power;
			motor[motorFR] = power;
			motor[motorBR] = power;
		}
		wait1Msec(1);
	}
	motor[motorFR] = 0;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorBL] = 0;
}
