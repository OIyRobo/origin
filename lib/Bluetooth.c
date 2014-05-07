task SendAck()
{
	bBTHasProgressSounds = true; //make alert noises
	nxtDisplayCenteredTextLine(1, "Searching");
	wait1Msec(5000);

	bool linked = false;
	while (!linked)
	{
		nxtDisplayCenteredTextLine(1, "Not Linked");
		sendMessage(42);
		if (messageParm[0] != 0)
			linked = true;
		ClearMessage();
		wait1Msec(50);
	}
	StartTask(ReceiveData);
}

task LookForAck()
{
	bBTHasProgressSounds = true; //make alert noises
	ClearMessage();
	bool linked = true;
	int i = 0;
	while (!linked)
	{
		nxtDisplayCenteredTextLine(5, "Searching");
		if (message == 0)
		{
			i++;
			nxtDisplayCenteredTextLine(4, "No msg rcvd, %i", i);
			ClearMessage();
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
			StartTask(ReceiveData);
		}
		wait1Msec(50);
	}
}

task SendSensorData()
{
	StopTask(LookForAck);
	while (true)
	{
		sendMessageWithParm(SensorValue[left], SensorValue[back], SensorValue[right]);
		wait10Msec(50);
	}
}

task ReceiveData()
{
	StopTask(SendAck);
	while (true) //main loop that reads messages from the other NXT
	{
		word temp;
		while (bQueuedMsgAvailable()) //empty queue to get latest message
		{
			ClearMessage();
			temp = message;
		}
		if (message == 0)
		{
			ClearMessage();
			wait1Msec(10);
		}
		else
		{
			sonarValue[back] = messageParm[back];
			sonarValue[right] = messageParm[right];
			sonarValue[left] = messageParm[left];
			sonarValue[front] = SensorValue[sonar];
			ClearMessage();
			wait1Msec(10);
		}
	}
}
