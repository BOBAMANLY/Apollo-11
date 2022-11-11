#pragma once

class direction {
private:
	double dx;
	double dy;
	double radians;
public:
	// Getters
	double getDX();
	double getDY();
	double getRadians();
	double getDegrees();

	void setDXDY(double dxInput, double dyInput);
	void setDegrees(double input);
	void setRadians(double input);
	void setDown();
	void setUp();
	void setRight();
	void setLeft();
};