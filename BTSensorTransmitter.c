#pragma config(Sensor, S1,     left,           sensorSONAR)
#pragma config(Sensor, S2,     back,           sensorSONAR)
#pragma config(Sensor, S3,     right,          sensorSONAR)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task debug()
{
	while (true){
	nxtDisplayCenteredTextLine(3, "Back: %i", SensorValue[back]);
	nxtDisplayCenteredTextLine(4, "Left: %i", SensorValue[left]);
	nxtDisplayCenteredTextLine(5, "Right: %i", SensorValue[right]);
	wait1Msec(100);
	}

}

task commLink()
{
	//bBTSkipPswdPrompt = true;
  //setBluetoothVisibility(true);
	bBTHasProgressSounds = true; //make alert noises
	//setBluetoothOn();
	//string name = "Manager";
  //setFriendlyName(name);

	ClearMessage();
	bool linked = true;
	int i = 0;
	while (!linked)  //basic link ack
	{
		nxtDisplayCenteredTextLine(5, "Searching");
		//while (bQueuedMsgAvailable())
		//{
		//	if (message == 0)
		//	{
		//		ClearMessage();
		//	}
		//}
		if (message == 0)
		{
			i++;
			nxtDisplayCenteredTextLine(4, "No msg rcvd, %i", i);
			ClearMessage();
			//5wait1Msec(100);
		}
		else if (message == 42)
		{
			nxtDisplayCenteredTextLine(5, "Received Ack");
			wait1Msec(100);
			sendMessage(314);
			linked = true;
		}
		else
		{
			nxtDisplayCenteredTextLine(3, "Message: %i", message);
			ClearMessage();
		}
		wait1Msec(50);
	}
	StartTask(debug);
	while (true)
	{
		sendMessageWithParm(SensorValue[left], SensorValue[back], SensorValue[right]);
		wait10Msec(50);
	}
}

task main()
{
	StartTask(commLink);
	while (true)
		wait1Msec(1000);
}