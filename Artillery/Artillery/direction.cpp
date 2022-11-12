#include "direction.h";
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
