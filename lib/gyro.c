
float getGyroAngle()
{
	return angle;
}

float getGyroOffset() //Returns offset of gyro for correcting different gyros having different offsets or gyros being moody (different values on different days).
{
	float average;
	const int SAMPLES = 200;
        average = SensorValue(gyro);
        for (int i = 0; i < SAMPLES; i++)
        {
            average = (average + SensorValue(gyro))/2.0;
            wait1Msec(1);
        }
	return average;
}

void zeroGyro()
{
	angle = 0;
}

//Gyro task that updates the angle of robot continuously.
task updateGyro()
{
    const int SAMPLE_RATE = 1000; // rate in hertz which the gyro is read at.
    cur_vel = 0;
    float prev_vel = 0;
    float avg_vel = 0;
    angle = 0;
    int offset = getGyroOffset();
    while (true)
    {
        prev_vel = cur_vel;
        cur_vel = SensorValue(gyro) - offset;
        if (abs(cur_vel) < 1)
        {
        	cur_vel = 0;
        }
        avg_vel = (cur_vel + prev_vel) / 2.0;
        angle += (avg_vel/SAMPLE_RATE);
        wait1Msec(1000/SAMPLE_RATE);
    }
}

int getVel()
{
		return cur_vel;
}
