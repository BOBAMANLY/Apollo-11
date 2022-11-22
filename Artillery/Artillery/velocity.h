#pragma once


class Velocity {
private:
	double dx;
	double dy;
	double speed;
	double direction;
public:
	// Getters
	double getDX();
	double getDY();
	double getSpeed();
	double getDirection();

	void setDX(double input);
	void setDY(double input);
	void setSpeed(double input);
	void setDirection(double input);
	void reverse(double dx, double dy);

	void addDX(double input);
	void addDY(double input);
};