#include "pos.h"
#pragma once


class mathFunctions {
private:
	double distance;
	double hangtime;
	double degrees;
	double radians;
public:
	// Setters
	void setDegrees(double input);
	void setDistance(double input);
	void setHangtime(double input);
	void setRadians(double input);

	// Getters
	double getDegrees();
	double getRadians();
	double getDistance();
	double getHangtime();

	// Math Functions
	void convertToDegrees(double input);
	void convertToRadians(double input);
	double DragForceEquation(double dragco, double density, double velocity, double surfaceArea);
	double AreaOfCircle(double radius);
	double Force(double acceleration);
	double verticalComponentSpeed(double speed, double direction);
	double HorizontalComponentSpeed(double speed, double direction);
	double AngleFromComponents(double dx, double dy);
	double pythagoreanTheorem(double dx, double dy);
	double interpoleration(double r0, double d0, double r1, double d1, double d);
};