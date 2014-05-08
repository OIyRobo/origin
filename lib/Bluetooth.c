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
	nxtDisplayCenteredTextLine(1, "Linked");
	StartTask(ReceiveData);
}

task LookForAck()
{
	bBTHasProgressSounds = true; //make alert noises
	ClearMessage();
	bool linked = false;
	int i = 0;
	while (!linked)
	{
		nxtDisplayCenteredTextLine(3, "Searching");
		if (message == 0)
		{
			i++;
			nxtDisplayCenteredTextLine(2, "No msg rcvd, %i", i);
			ClearMessage();
		}
		else if (message == 42)
		{
			nxtDisplayCenteredTextLine(3, "Received Ack");
			wait1Msec(100);
			sendMessage(314);
			linked = true;
		}
		else
		{
			nxtDisplayCenteredTextLine(1, "Message: %i", message);
			ClearMessage();
		}
		wait1Msec(50);
	}
	StartTask(SendSensorData);
}

task SendSensorData()
{
	while (true)
	{
		sendMessageWithParm(SensorValue[S1], SensorValue[S2], SensorValue[S3]);
		wait10Msec(50);
	}
}

task ReceiveData()
{
	while (true) //main loop that reads messages from the other NXT
	{
		word temp;
		while (bQueuedMsgAvailable()) //empty queue to get latest message
		{
			ClearMessage();
			temp = message;
			wait1Msec(10);
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
			sonarValue[front] = SensorValue[S3];
			ClearMessage();
			wait1Msec(10);
		}
	}
}
