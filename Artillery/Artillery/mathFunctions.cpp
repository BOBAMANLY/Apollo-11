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
double mathFunctions::getRadians() {
	return radians;
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
	//cout << output << endl;
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
	// dx^2 + dy^2 = s^2
	double speed = sqrt((dx * dx) + (dy * dy));
	if (dx < 0 or dy < 0)
		return NULL;
	return speed;
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
	double top = (r1 - r0);
	double bottom = (d1 - d0);
	if (bottom == 0)
		return NULL;
	double slope = (top / bottom);
	double r = r0 + slope * (d - d0);
	return r;
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
double mathFunctions :: AreaOfCircle(double radius){
	/*
	a = area of a circle (m2)
	r = radius of a circle
	*/
	//a = π r 2
	double pi = 2 * acos(0.0);
	double r = radius;
	double area = pi * (r * r);
	if (r < 0)
		return NULL;
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
/*
map<double, double> mathFunctions::dragCoefficientTable() {
	map<double, double> dragTableData;
										// mach,    drag
	dragTableData.insert(pair<double, double>(0.300,	0.1629));
	dragTableData.insert(pair<double, double>(0.500,	0.1659));
	dragTableData.insert(pair<double, double>(0.700,	0.2031));
	dragTableData.insert(pair<double, double>(0.890,	0.2597));
	dragTableData.insert(pair<double, double>(0.920,	0.3010));
	dragTableData.insert(pair<double, double>(0.960,	0.3287));
	dragTableData.insert(pair<double, double>(0.980,	0.4002));
	dragTableData.insert(pair<double, double>(1.000,	0.4258));
	dragTableData.insert(pair<double, double>(1.020,	0.4335));
	dragTableData.insert(pair<double, double>(1.060,	0.4483));
	dragTableData.insert(pair<double, double>(1.240,	0.4064));
	dragTableData.insert(pair<double, double>(1.530,	0.3663));
	dragTableData.insert(pair<double, double>(1.990,	0.2897));
	dragTableData.insert(pair<double, double>(2.870,	0.2297));
	dragTableData.insert(pair<double, double>(2.890,	0.2306));
	dragTableData.insert(pair<double, double>(5.000,	0.2656));
	return dragTableData;
}

map<double, double> mathFunctions::densityTable() {
	map<double, double> densityTableData;
										  // altitude, density
	densityTableData.insert(pair<double, double>(0,		1.2250000));
	densityTableData.insert(pair<double, double>(1000,	1.1120000));
	densityTableData.insert(pair<double, double>(2000,	1.0070000));
	densityTableData.insert(pair<double, double>(3000,	0.9093000));
	densityTableData.insert(pair<double, double>(4000,	0.8194000));
	densityTableData.insert(pair<double, double>(5000,	0.7364000));
	densityTableData.insert(pair<double, double>(6000,	0.6601000));
	densityTableData.insert(pair<double, double>(7000,	0.5900000));
	densityTableData.insert(pair<double, double>(8000,	0.5258000));
	densityTableData.insert(pair<double, double>(9000,	0.4671000));
	densityTableData.insert(pair<double, double>(10000,	0.4135000));
	densityTableData.insert(pair<double, double>(15000,	0.1948000));
	densityTableData.insert(pair<double, double>(20000,	0.0889100));
	densityTableData.insert(pair<double, double>(25000,	0.0400800));
	densityTableData.insert(pair<double, double>(30000,	0.0184100));
	densityTableData.insert(pair<double, double>(40000,	0.0039960));
	densityTableData.insert(pair<double, double>(50000,	0.0010270));
	densityTableData.insert(pair<double, double>(60000,	0.0003097));
	densityTableData.insert(pair<double, double>(70000,	0.0000828));
	densityTableData.insert(pair<double, double>(80000,	0.0000185));
	return densityTableData;
}
map<double, double> mathFunctions::soundTable() {
	map<double, double> soundTableData;
										 //altitude, speed of sound
	soundTableData.insert(pair<double, double>(0,		340));
	soundTableData.insert(pair<double, double>(1000,	336));
	soundTableData.insert(pair<double, double>(2000,	332));
	soundTableData.insert(pair<double, double>(3000,	328));
	soundTableData.insert(pair<double, double>(4000,	324));
	soundTableData.insert(pair<double, double>(5000,	320));
	soundTableData.insert(pair<double, double>(6000,	316));
	soundTableData.insert(pair<double, double>(7000,	312));
	soundTableData.insert(pair<double, double>(8000,	308));
	soundTableData.insert(pair<double, double>(9000,	303));
	soundTableData.insert(pair<double, double>(10000,	299));
	soundTableData.insert(pair<double, double>(15000,	295));
	soundTableData.insert(pair<double, double>(20000,	295));
	soundTableData.insert(pair<double, double>(25000,	295));
	soundTableData.insert(pair<double, double>(30000,	305));
	soundTableData.insert(pair<double, double>(40000,	324));
	return soundTableData;
}
map<double, double> mathFunctions::gravityTable() {
	map<double, double> gravityTableData;
											   //altitude, gravity
	gravityTableData.insert(pair<double, double>(0,		9.807));
	gravityTableData.insert(pair<double, double>(1000,	9.804));
	gravityTableData.insert(pair<double, double>(2000,	9.801));
	gravityTableData.insert(pair<double, double>(3000,	9.797));
	gravityTableData.insert(pair<double, double>(4000,	9.794));
	gravityTableData.insert(pair<double, double>(5000,	9.791));
	gravityTableData.insert(pair<double, double>(6000,	9.788));
	gravityTableData.insert(pair<double, double>(7000,	9.785));
	gravityTableData.insert(pair<double, double>(8000,	9.782));
	gravityTableData.insert(pair<double, double>(9000,	9.779));
	gravityTableData.insert(pair<double, double>(10000,	9.776));
	gravityTableData.insert(pair<double, double>(15000,	9.761));
	gravityTableData.insert(pair<double, double>(20000,	9.745));
	gravityTableData.insert(pair<double, double>(25000,	9.730));
	return gravityTableData;
}*/