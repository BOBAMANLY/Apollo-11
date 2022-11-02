// Artillery.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Names: Philip Marvin, Jacob Fisher, Joseph Gyman
//

#include <iostream>
#include "mathFunctions.h"
#include "math.h"
#include <cmath>
#include "pos.h"
using namespace std;


// Setters
void mathFunctions :: setDegrees(double input)
{
	degrees = input;
}
	
void mathFunctions :: setRadians(double input)
{
	radians = input;
}

void mathFunctions :: setDistance(double input) {
	distance = input;
}

void mathFunctions :: setHangtime(double input) {
	hangtime = input;
}

// Getters
double mathFunctions :: getDegrees() {
	return degrees;
}
double mathFunctions :: getDistance() {
	return distance;
}
double mathFunctions :: getHangtime() {
	return hangtime;
}

// Equations
void mathFunctions :: convertToDegrees(double input)
{
	/*
		r = angle in radians
		π = pi, about 3.14159
		d = angle in degrees
	*/
	// 	r / 2 π = d / 360
	double pi = 2 * acos(0.0);
	double output = (360) * (input / 2 * pi);
	setDegrees(output);
}
void mathFunctions :: convertToRadians(double input) {
	/*
		r = angle in radians
		π = pi, about 3.14159
		d = angle in degrees
	*/
	// 	r / 2 π = d / 360
	double pi = 2 * acos(0.0);
	double output = (360) * (input / 2 * pi);
	setRadians(output);
}
double mathFunctions :: verticalComponentSpeed(double speed, double direction) {
	/*
		dy = vertical component of speed(m / s)
		s = overall speed(m / s)
		a = direction of travel where 0 is pointing up(radians)
	*/
	// dy = s cos(a)
	double dy = speed * cos(direction);
	return dy;
}
double mathFunctions :: HorizontalComponentSpeed(double speed, double direction)
{
	/*
		dx = vertical component of speed (m/s)
		s = overall speed (m/s)
		a = direction of travel where 0 is pointing up (radians)
	*/
	// dx = s sin(a)
	double dx = speed + sin(direction);
	return dx;
}
double mathFunctions :: AngleFromComponents(double dx, double dy) {
	/*
		a = directon of travel where 0 is pointing up (radians)
		dx = horizontal component of speed (m/s)
		dy = vertical component of speed (m/s)
	*/
	//a = atan(dx, dy)
	double output;
	output = atan2 (dx, dy);
	return output;
}
double mathFunctions :: pythagoreanTheorem(double dx, double dy) {
	/*
		dx = horizontal component of speed (m/s)
		dy = vertical component of speed (m/s)
		s = overall speed (m/s)
	*/
	// dx^2 + dy^2 = s2
	double speed = (dx * dx) + (dy * dy);

	return speed, dx;
}
double mathFunctions :: interpoleration(double d0, double r0, double d1, double r1, double d) {

	// TODO: Not done
	/*
		d0,r0 = coordinates of one point
		d1,r1 = coordinates of a second point
		d,r = coordinates of a point in the middle
	*/
	// (r - r0) / (d - d0) = (r1 - r0) / (d1 - d0)
	// for finding Density at altitude
	//(r - 1.225)/(d - 0) = (1.112 - 1.225) / (1000 - 0)
	double slope = ((r1 - r0) / (d1 - d0));
	double r = r0 + slope * (d - d0);
	return d, r;
}
double mathFunctions :: Force(double acceleration = 827){
	/*
	f = force in newtons (N)
	m = mass in kilograms (kg)
	a = acceleration (m/s2)
	*/
	//f = m a
	double force = 46.7 * acceleration;
	return force;
}
double mathFunctions :: AreaOfCircle(){
	/*
	a = area of a circle (m2)
	r = radius of a circle
	*/
	//a = π r 2
	double pi = 2 * acos(0.0);
	double r = (154.89 / 2);
	double area = pi * (r * r);
	return area;
}
double mathFunctions :: DragForceEquation(double c, double p, double v, double a){
	/*
	d = force in newtons (N)
	c = drag coefficient
	ρ = density of the fluid/gas
	v = velocity of the projectile
	a = surface area
	*/
	//d = ½ c ρ v2 a
	double drag = .5 * c * p * (v * v) * a;
	return drag;
}


int main()
{
    // Test case up
	cout << "What is the angle of the howitzer where 0 is up (Degrees)? " << endl;
	mathFunctions test1;
	Position ptest1;
	Position cannonPosition;
	cannonPosition.setMetersX(0.0);
	cannonPosition.setMetersY(0.0);
	Position endingPosition;
	test1.setDegrees(0.0);
	cout << test1.getDegrees() << endl;
	cout << "Distance:      ";
	//cout << ptest1.computeDistance(cannonPosition, endingPosition) << "       ";
	cout << "Hang Time:     ";
	//cout << test1.DragForceEquation() << endl;

	// Test case high
	cout << "\nWhat is the angle of the howitzer where 0 is up (Degrees)? " << endl;
	mathFunctions test2;
	test2.setDegrees(30.0);
	cout << test2.getDegrees() << endl;
	cout << "Distance:      ";
	//cout << test1.computeDistance(pos1, pos2) << "       ";
	cout << "Hang Time:     ";
	//cout << test1.DragForceEquation() << endl;

	// Test case low
	cout << "\nWhat is the angle of the howitzer where 0 is up (Degrees)? " << endl;
	mathFunctions test3;
	test3.setDegrees(60.0);
	cout << test3.getDegrees() << endl;
	cout << "Distance:      ";
	//cout << test1.computeDistance(pos1, pos2) << "       ";
	cout << "Hang Time:     ";
	//cout << test1.DragForceEquation() << endl;

	// Test case backwards
	cout << "\nWhat is the angle of the howitzer where 0 is up (Degrees)? " << endl;
	mathFunctions test4;
	test4.setDegrees(-45.0);
	cout << test4.getDegrees() << endl;
	cout << "Distance:      ";
	//cout << test1.computeDistance(pos1, pos2) << "       ";
	cout << "Hang Time:     ";
	//cout << test1.DragForceEquation() << endl;

	return 0;
}
