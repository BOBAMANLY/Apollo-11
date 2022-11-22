#include "velocity.h"

double Velocity::getDX() {
	return dx;
}
double Velocity::getDY() {
	return dy;
}
double Velocity::getSpeed() {
	return speed;
}
double Velocity::getDirection() {
	return direction;
}
void Velocity::setDX(double input) {
	dx = input;
}
void Velocity::setDY(double input) {
	dy = input;
}
void Velocity::setSpeed(double input) {
	speed = input;
}
void Velocity::setDirection(double input) {
	direction = input;
}
void Velocity::reverse(double ddx, double ddy)
{
	dx = ddx * -1;
	dy = ddy * -1;
}
void Velocity::addDX(double input) {
	dx += input;
}
void Velocity::addDY(double input) {
	dy += input;
}
