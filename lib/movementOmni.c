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
	int startAngle = getGyroAngle();
	int power = 20;

	while ( abs((int)(getGyroAngle() - (startAngle + degrees))) > 1) {
		if (getGyroAngle() < (startAngle	+ degrees)) {
			motor[motorFL] = power;
			motor[motorBL] = power;
			motor[motorFR] = -power;
			motor[motorBR] = -power;
		}
		else if (getGyroAngle() > (startAngle + degrees)){
			motor[motorFL] = -power;
			motor[motorBL] = -power;
			motor[motorFR] = power;
			motor[motorBR] = power;
		}
		wait1Msec(50);
	}
	motor[motorFR] = 0;
	motor[motorFL] = 0;
	motor[motorBR] = 0;
	motor[motorBL] = 0;
}
