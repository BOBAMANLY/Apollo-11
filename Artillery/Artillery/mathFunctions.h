#pragma once

class mathFunctions {
private:
	double distance;
	double hangtime;
	int degrees;
public:
	// Setters
	void setDegrees(double input);
	void setDistance(double input);
	void setHangtime(double input);

	// Getters
	double getDegrees();
	double getDistance();
	double getHangtime();

	// Math Functions
	void convertToDegrees(double input);
	double verticalComponentSpeed(double speed, double direction);
	double HorizontalComponentSpeed(double speed, double direction);
	double AngleFromComponents(double dx, double dy);
	double pythagoreanTheorem(double dx, double dy);
	double interpoleration(double r0, double d0, double r1, double d1);

};