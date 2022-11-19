#include "velocity.h";

double velocity::getDX() {
	return dx;
}
double velocity::getDY() {
	return dy;
}
double velocity::getSpeed() {
	return speed;
}
double velocity::getDirection() {
	return direction;
}
void velocity::setDX(double input) {
	dx = input;
}
void velocity::setDY(double input) {
	dy = input;
}
void velocity::setSpeed(double input) {
	speed = input;
}
void velocity::setDirection(double input) {
	direction = input;
}
void velocity::reverse(double ddx, double ddy)
{
	dx = ddx * -1;
	dy = ddy * -1;
}
void velocity::addDX(double input) {
	dx += input;
}
void velocity::addDY(double input) {
	dy += input;
}
