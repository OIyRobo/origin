void move(float angle, int power) {
	float theta = (-angle + 45.0)*PI/180.0; //adjusting angle to unit circle

	motor[motorFR] = cos(theta) * power; //NE vector
	motor[motorBL] = cos(theta) * power;

	motor[motorFL] = sin(theta) * power; //NW vector
	motor[motorBR] = sin(theta) * power;
}

void brake() {
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
