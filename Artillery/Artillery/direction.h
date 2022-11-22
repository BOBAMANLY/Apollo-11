#pragma once

#include <iostream> 
#include <cmath>


class Direction {
private:
	double dx;
	double dy;
	double degrees;
	double radians;
public:
	//friend TestDirection;

	// Constructors/assignment operators
	//Direction(double degrees) : radians(0.0)
	//{
	//	radians = getRadians();
	//}
	//Direction(const Direction& rhs) : radians(rhs.radians) {}
	//Direction& operator = (const Direction& rhs)
	//{
	//	radians = rhs.radians;
	//	return *this;
	//}
	// Getters
	double getDX();
	double getDY();
	double getRadians();
	double getDegrees();

	// Setters
	void setDXDY(double dxInput, double dyInput);
	void setDegrees(double input);
	void setRadians(double input);
	void setDown();
	void setUp();
	void setRight();
	void setLeft();
	void reverse();
	void rotate(double input);
};