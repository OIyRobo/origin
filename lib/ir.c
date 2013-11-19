int getZone() //returns active zone (1-9);
{
    return zone;
}

int getSide()//gets angle to bacon... I mean beacon. updateIR MUST be running before this can be used.
{
    if (getZone() > 5)
    {
        return 0;
    }
    else
    	return 1;
}

task updateIR()//runs loop that continuously takes readings from the ir sensor.
{
    const int threshold = 50;
    int dirAC = 0;
    int ac[5];
    tHTIRS2DSPMode _mode = DSP_1200;

    if(!HTIRS2setDSPMode(ir, _mode))
    {
        nxtDisplayCenteredTextLine(3, "Failed to set IR Mode at %i", _mode);
    }

    while(true)
    {
        dirAC = HTIRS2readACDir(ir);
        HTIRS2readAllACStrength(ir, ac[0], ac[1], ac[2], ac[3], ac[4]);
        switch (dirAC)
        {
            case 1:
                if (ac[0] > threshold)
                    zone = 1;
                break;
            case 2:
                if (ac[0] > threshold && ac[1] > threshold)
                    zone = 2;
                break;
            case 3:
                if (ac[1] > threshold)
                    zone = 3;
                break;
            case 4:
                if (ac[1] > threshold && ac[2] > threshold)
                    zone = 4;
                break;
            case 5:
                if (ac[2] > threshold)
                    zone = 5;
                break;
            case 6:
                if (ac[2] > threshold && ac[3] > threshold)
                    zone = 6;
                break;
            case 7:
                if (ac[3] > threshold)
                    zone = 7;
            case 8:
                if (ac[3] > threshold && ac[4] > threshold)
                    zone = 8;
                break;
            case 9:
                if (ac[4] > threshold)
                    zone = 9;
                break;
            default:
                zone = -1;
                break;
        }
        wait1Msec(16);
    }
    //returned zones    1 2 3 4 5 6 7 8 9
    //actual zones      0 ^ 1 ^ 2 ^ 3 ^ 4
}
