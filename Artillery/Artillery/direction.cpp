
#include "direction.h"
#include <cmath>

double Direction::getDX() {
	return dx;
}
double Direction::getDY() {
	return dy;
}
double Direction::getRadians() {
	return radians;
}
double Direction::getDegrees() {
	double pi = 2 * acos(0.0);
	return (360) * (radians / 2 * pi);
}

void Direction::setDXDY(double dxInput, double dyInput) {
	dx = dxInput;
	dy = dyInput;
}
void Direction::setDegrees(double input) {
	double pi = 2 * acos(0.0);
	radians = (360) * (input / 2 * pi);
}
void Direction::setRadians(double input) {
	double pi = 2 * acos(0.0);
	radians = input;
}

void Direction::setDown() {
	setDegrees(180.0);
}
void Direction::setUp() {
	setDegrees(0.0);
}
void Direction::setRight() {
	setDegrees(270.0);
}
void Direction::setLeft() {
	setDegrees(90.0);
}

void Direction::reverse()
{
	double pi = 2 * acos(0.0);
	setRadians(radians + pi);
}

void Direction::rotate(double input)
{
	double pi = 2 * acos(0.0);
	setRadians(input + radians);
	if (input >= 0.0)
	{
		double rotations = (double)(int)((pi + input) / (pi * 2.0));
		input -= rotations * (pi * 2.0);
	}
	else
	{
		double rotations = -(double)(int)((input - pi) / (pi * 2.0));
		input += rotations * (pi * 2.0);
	}
}
