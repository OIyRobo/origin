
int getColor() {
	short rgb[4];
	getColorSensorData(color, colorRaw, &rgb[0]);

	//rgb array goes r value, g, b at index 0,1,2 respectively.
	int redVal = rgb[0];
	int greenVal = rgb[1];
	int blueVal = rgb[2];

	if(redVal>100 && greenVal>100 && blueVal>100){
		return WHITE;
	}
	else if(redVal<60 && greenVal<60 && blueVal<60){
		return BLACK;
	}
	else if(abs(redVal-greenVal)<20 && redVal<60 && greenVal<60 && blueVal<60 && abs(redVal-blueVal)<20 && abs(blueVal-greenVal)<20){
		return GREY;
	}
	else if(redVal>150 && greenVal>150 && blueVal<(redVal-100)){
		return YELLOW;
	}
	else if(blueVal>100 && abs(greenVal-redVal)<20 && redVal <(blueVal-100)){
		return BLUE;
	}
	else if(redVal>100 && abs(blueVal-greenVal)<20 && blueVal<(redVal-100)){
		return RED;
	}
	return -1;
}
