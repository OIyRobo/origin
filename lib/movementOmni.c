
void move(float theta, int maxPower) {
	theta = (-theta + 45.0)*PI/180.0; //adjusting from unit circle to compass heading, then converting to rad.

	float powers[2] = {cos(theta), sin(theta)}; //this might be problematic because of floating point precision. We'll see.
	maximizePower(powers, maxPower);

	motor[motorFR] = powers[NW]; //this actually turns out to be opposite to the intuitive mapping because the wheels rotate 90 degrees off from the motor's orientation.
	motor[motorBL] = powers[NW];

	motor[motorFL] = powers[NE];
	motor[motorBR] = powers[NE];

	/*
	motor[motorBR] = cos(theta) * power; //NE vector
	motor[motorFL] = cos(theta) * power;

	motor[motorBL] = sin(theta) * power; //NW vector
	motor[motorFR] = sin(theta) * power;
	*/
}

void brake() {
	motor[motorFL] = 0;
	motor[motorFR] = 0;
	motor[motorBL] = 0;
	motor[motorBR] = 0;
}

void turn(int degrees) {
	int target = degrees + getGyroAngle();
	int power = 20;

	while ( abs(getGyroAngle() - target) > .5 || abs(getVel()) > 3)  {
		if (abs((int)(getGyroAngle() - target)) < 50)
			power = 15;
		if (abs((int)(getGyroAngle() - target)) < 30)
			power = 10;
		if(abs((int)(getGyroAngle() - target)) < 10)
			power = 5;
		if (abs(getVel()) < 2)
			power = 13;

		if (getGyroAngle() < target) {
			motor[motorFL] = power;
			motor[motorBL] = power;
			motor[motorFR] = -power;
			motor[motorBR] = -power;
		}
		else if (getGyroAngle() > target){
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

void maximizePower(float *powers, int power)
{
	float coefficient = 1.0;
	if (abs(powers[NW]) < power && abs(powers[NE]) < power)
	{
		if (abs(powers[NW]) >= abs(powers[NE]))
		{
			coefficient = (float)(power)/abs(powers[NW]);
			powers[NW] *= coefficient;
			powers[NE] *= coefficient;
		}
		else if (abs(powers[NE]) > abs(powers[NW]))
		{
			coefficient = (float)(power)/abs(powers[NE]);
			powers[NW] *= coefficient;
			powers[NE] *= coefficient;
		}
	}
}
