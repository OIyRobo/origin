
int getColor() {
	short rgb[4];
	getColorSensorData(color, colorRaw, &rgb[0]);

	//rgb array goes r value, g, b at index 0,1,2 respectively.
	int redVal = rgb[0];
	int greenVal = rgb[1];
	int blueVal = rgb[2];

	if(redVal > 120 && greenVal > 120 && blueVal > 120){ //ugliest logic NA checks the color over and over
		return WHITE;
	}
	else if(redVal < 50 && greenVal < 50 && blueVal < 50) {
		return BLACK;
	}
	else if(redVal > 65 && redVal < 100 && greenVal > 65 && greenVal < 100 && blueVal > 50 && blueVal < 100){
		return GREY;
	}
	else if(blueVal > 100 && greenVal < 150 && redVal < 100){
		return BLUE;
	}
	else if(redVal > 130 && greenVal < 50 && blueVal < 50){
		return RED;
	}
	return -1;
}
