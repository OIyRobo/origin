void move(int dir, int power, int time) {
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
		motor[motrFL] = -power;
		motor[motrFR] = -power;
		motor[motrBL] = -power;
		motor[motrBR] = -power;
	}
	wait1Msec(time);
	motor[motorFL] = 0;
	motor[motorFR] = 0;
	motor[motorBL] = 0;
	motor[motorBR] = 0;
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
