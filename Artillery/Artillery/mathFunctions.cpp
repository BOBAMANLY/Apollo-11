// Artillery.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class mathFunctions {
private:
	double distance;
	double hangtime;
	double degrees;
	double radians;
public:
	// Setters
	void setDegrees(double input) {
		degrees = input;
	}
	void setRadians(double input) {
		radians = input;
	}
	void setDistance(double input) {
		distance = input;
	}
	void setHangtime(double input) {
		hangtime = input;
	}

	// Getters
	double getDegrees() {
		return degrees;
	}
	double getDistance() {
		return distance;
	}
	double getHangtime() {
		return hangtime;
	}

	// Equations
	void convertToDegrees(double input) {
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
	void convertToRadians(double input) {
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
	double verticalComponentSpeed(double speed, double direction) {
		/*
			dy = vertical component of speed(m / s)
			s = overall speed(m / s)
			a = direction of travel where 0 is pointing up(radians)
		*/
		// dy = s cos(a)
		double dy = speed * cos(direction);
		return dy;
	}
	double HorizontalComponentSpeed(double speed, double direction) {
		/*
			dx = vertical component of speed (m/s)
			s = overall speed (m/s)
			a = direction of travel where 0 is pointing up (radians)
		*/
		// dx = s sin(a)
		double dx = speed + sin(direction);
		return dx;
	}
	double AngleFromComponents(double dx, double dy) {
		/*
			a = directon of travel where 0 is pointing up (radians)
			dx = horizontal component of speed (m/s)
			dy = vertical component of speed (m/s)
		*/
		// 	a = atan(dx, dy)
		double output;
		//output = atan(dx, dy);
		return output;
	}
	double pythagoreanTheorem(double dx, double dy) {
		/*
			dx = horizontal component of speed (m/s)
			dy = vertical component of speed (m/s)
			s = overall speed (m/s)
		*/
		// dx^2 + dy^2 = s2
		double speed = (dx * dx) + (dy * dy);
		return speed * speed;
	}
	double interpoleration(double r0, double d0, double r1, double d1) {

		// TODO: Not done
		/*
			d0,r0 = coordinates of one point
			d1,r1 = coordinates of a second point
			d,r = coordinates of a point in the middle
		*/
		// (r - r0) / (d - d0) = (r1 - r0) / (d1 - d0)
		double d;
		double r = ((((r1 - r0) / (d1 - d0)) * (d - d0)) - r0);

	}
};
int main()
{
    // Test case up
	cout << "What is the angle of the howitzer where 0 is up (Degrees)? " << 0 << endl;
	mathFunctions test1;
	test1.setDegrees(0.0);

	// Test case high
	cout << "What is the angle of the howitzer where 0 is up (Degrees)? " << 30 << endl;
	mathFunctions test2;
	test2.setDegrees(30.0);

	// Test case low
	cout << "What is the angle of the howitzer where 0 is up (Degrees)? " << 60 << endl;
	mathFunctions test3;
	test3.setDegrees(60.0);

	// Test case backwards
	cout << "What is the angle of the howitzer where 0 is up (Degrees)? " << -45 << endl;
	mathFunctions test4;
	test4.setDegrees(-45.0);

	return 0;
}
