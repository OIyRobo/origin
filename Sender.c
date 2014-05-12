#pragma config(Sensor, S1,     ,           sensorSONAR)
#pragma config(Sensor, S2,     ,           sensorSONAR)
#pragma config(Sensor, S3,     ,          sensorSONAR)

#include "headers/bluetooth.h"

task debug()
{
	while (true){
	nxtDisplayCenteredTextLine(5, "Back: %i", SensorValue[back]);
	nxtDisplayCenteredTextLine(6, "Left: %i", SensorValue[left]);
	nxtDisplayCenteredTextLine(7, "Right: %i", SensorValue[right]);
	wait1Msec(100);
	}
}


task main()
{
	StartTask(LookForAck);
	//StartTask(debug);
	while(true)
		wait10Msec(1000);
}
