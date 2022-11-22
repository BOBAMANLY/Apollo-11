
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
	return degrees;
}

void Direction::setDXDY(double dxInput, double dyInput) {
	dx = dxInput;
	dy = dyInput;
}
void Direction::setDegrees(double input) {
	double pi = 2 * acos(0.0);
	degrees = (input) * (180/pi);
}
void Direction::setRadians(double input) {
	double pi = 2 * acos(0.0);
	radians = (input) * (pi/180);
}

void Direction::setDown() {
	double pi = 2 * acos(0.0);
	setRadians(180.0);
	setDegrees(pi);
}
void Direction::setUp() {
	setRadians(0.0);
	setDegrees(0.0);
}
void Direction::setRight() {
	setRadians(270.0);
	setDegrees(4.71239);
}
void Direction::setLeft() {
	setRadians(90.0);
	setDegrees(1.5708);
}

double Direction::reverse()
{
	double pi = 2 * acos(0.0);
	double newRads = radians + pi;
	return newRads;
}

void Direction::rotate(double input)
{
	double pi = 2 * acos(0.0);
	double newInput;
	if (input >= 0.0)
	{
		double rotations = (double)(int)((pi + input) / (pi * 2.0));
		newInput = input -= rotations * (pi * 2.0);
	}
	else
	{
		double rotations = -(double)(int)((input - pi) / (pi * 2.0));
		newInput = input += rotations * (pi * 2.0);
	}
	radians = newInput;
}
