void move(int power) {
	motor[motorFR] = power;
	motor[motorFL] = power;
	motor[motorBR] = power;
	motor[motorBL] = power;
}

void turn(int power, int offset)
{
	motor[motorFR] = power - offset;
	motor[motorFL] = power + offset;
	motor[motorBR] = power - offset;
	motor[motorBL] = power + offset;
}

void turn(int degrees) {
	zeroGyro();
	int power = 20;
	bool starting = true;

	while ( abs((int)(getGyroAngle() - degrees)) != 0 || abs(getVel()) > 5)  {
		if (abs((int)(getGyroAngle() - degrees)) < 50)
			power = 15;
		if (abs((int)(getGyroAngle() - degrees)) < 30)
			power = 10;
		if(abs((int)(getGyroAngle() - degrees)) < 10)
			power = 5;
		if (abs(getVel()) < 2)
			power = 17;

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
