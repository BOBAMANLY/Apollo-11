#include "direction.h";
#include <cmath>

double direction::getDX() {
	return dx;
}
double direction::getDY() {
	return dy;
}
double direction::getRadians() {
	return radians;
}
double direction::getDegrees() {
	double pi = 2 * acos(0.0);
	return (360) * (radians / 2 * pi);
}

void direction::setDXDY(double dxInput, double dyInput) {
	dx = dxInput;
	dy = dyInput;
}
void direction::setDegrees(double input) {
	double pi = 2 * acos(0.0);
	radians = (360) * (input / 2 * pi);
}
void direction::setRadians(double input) {
	radians = input;
}
void direction::setDown() {
	setDegrees(180.0);
}
void direction::setUp() {
	setDegrees(0.0);
}
void direction::setRight() {
	setDegrees(270.0);
}
void direction::setLeft() {
	setDegrees(90.0);
}