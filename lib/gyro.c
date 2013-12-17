//returns current angular position of the robot, only works when the updateGyro task is running also.
float getGyroAngle()
{
	return angle;
}

float getGyroOffset() //Returns offset of gyro for correcting different gyros having different offsets or gyros being moody (different values on different days).
{
	float average;
	const int SAMPLES = 200;
    average = SensorValue(gyro);
    for (int i = 0; i < SAMPLES; i++)//take readings and average them to find the offset when the robot is sitting still
    {
    	average = (average + SensorValue(gyro))/2.0;
    	wait1Msec(1);
    }
	return average;
}

void zeroGyro() //sets angle to zero for ease of use.
{
	angle = 0;
}

//Gyro task that updates the angle of robot continuously.
task updateGyro()
{
    cur_vel = 0;
    float prev_vel = 0;
    float avg_vel = 0;
    angle = 0;
    int offset = getGyroOffset();
    ClearTimer(T1);
    while (true) //integrate velocity and add to angular position
	{
        prev_vel = cur_vel;
        cur_vel = SensorValue(gyro) - offset;
        if (abs(cur_vel) < 2)
        {
        	cur_vel = 0;
        }
        avg_vel = (cur_vel + prev_vel) / 2.0; //trapezoidal approximation
        angle += ((float)(avg_vel*(float)((float)(time1[T1])/(float)(1000.0)))); //add trapezoid slice to position
        ClearTimer(T1);
        wait1Msec(15);
    }
}

//returns current velocity
int getVel()
{
		return cur_vel;
}
