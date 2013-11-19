void servoTurn(float degrees, TServoIndex srvo)//turns a servo to a specified degree on a 180 degree arc.
{
	float k_deg = 237.0/180.0;
	int k_offset = 18;
	servoTarget[srvo] = (int)(degrees * k_deg) + k_offset;
	wait1Msec(degrees * 10);//wait for the servo finish turning.
}
