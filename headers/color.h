#ifndef COLOR_H
#define COLOR_H

const int WHITE = 0;  //all between 240-255
const int BLACK = 1;  //all between 0-60
const int GREY = 2;   //all between 60-240 s.t. the color range is less than 20
const int YELLOW = 3; //red, green between 255-150 range less than 20 && b<=r-100
const int BLUE = 4;   // b>100, r range<20 g && r<b-100
const int RED = 5;    // r>100, b range<20 g && b<r-100

int getColor();

#include "..\lib\color.c"
#endif
