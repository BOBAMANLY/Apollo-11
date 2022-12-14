#pragma once
#include "velocity.h"
#include <cassert>
#include "mathFunctions.h"
#include "math.h"
#include <cmath>

using namespace std;

class testVelocity {
public:
	void run() {
		// Put the function call of each unit test here:
		correctAddDY();
		AddForZeroDY();
		AddNegativeDY();
		correctAddDX();
		AddForZeroDX();
		AddNegativeDX();
		correctTestReverseDX();
		correctTestReverseDY();
		negativeReverseDX();
		negativeReverseDY();
		reverseZeroDX();
		reverseZeroDY();
		reverseOpposites1();
		reverseOpposites2();
		getDrirectionUp();
		getDirecttionRight();
		getDirectionLeft();
		getDirectionDown();
		passed();
	}
private:
	// Write unit tests using this format.
	/*
	void TestName() {
		// Setup
		velocity v;
		// Exercise
		do something
		// Verify
		assert(something == something)
		// Teardown
	}*/
	void passed()
	{
		cout << "All Velocity tests passed!" << endl;
	}
	void correctAddDY() {
		// Setup
		Velocity v;
		v.setDY(10.0);
		// Exercise
		v.addDY(10.0);
		// Verify
		assert(v.getDY() == 20.0);
		// Teardown
	}
	void AddForZeroDY() {
		//setup
		Velocity v;
		v.setDY(0.0);
		//exercise
		v.addDY(0.0);
		//verify
		assert(v.getDY() == 0.0);
	}
	void AddNegativeDY() {
		//setup
		Velocity v;
		v.setDY(0.0);
		//exercise
		v.addDY(-10.0);
		//verify
		assert(v.getDY() == -10.0);
	}
	void correctAddDX() {
		//setup
		Velocity v;
		v.setDX(10.0);
		//exercise
		v.addDX(10.0);
		//verify
		assert(v.getDX() == 20.0);
	}
	void AddForZeroDX() {
		//setup
		Velocity v;
		v.setDX(0.0);
		//exercise
		v.addDX(0.0);
		//verify
		assert(v.getDX() == 0.0);
	}
	void AddNegativeDX() {
		//setup
		Velocity v;
		v.setDX(0.0);
		//exercise
		v.addDX(-10.0);
		//verify
		assert(v.getDX() == -10.0);
	}

	void correctTestReverseDX() {
		//setup
		Velocity v;
		v.setDX(10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx,dy);
		//verify
		assert(v.getDX() == -10.0);
	}
	void correctTestReverseDY() {
		//setup
		Velocity v;
		v.setDY(10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDY() == -10.0);
	}
	void negativeReverseDX() {
		//setup
		Velocity v;
		v.setDX(-10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDX() == 10.0);
	}
	void negativeReverseDY() {
		//setup
		Velocity v;
		v.setDY(-10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDY() == 10.0);
	}
	void reverseZeroDX() {
		//setup
		Velocity v;
		v.setDX(0.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDX() == 0.0);
	}
	void reverseZeroDY() {
		//setup
		Velocity v;
		v.setDY(0.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDY() == 0.0);

	}
	void reverseOpposites1() {
		//setup
		Velocity v;
		v.setDX(-10.0);
		v.setDY(10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDX() == 10.0 and v.getDY() == -10.0);
	}
	void reverseOpposites2() {
		//setup
		Velocity v;
		v.setDX(10.0);
		v.setDY(-10.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		v.reverse(dx, dy);
		//verify
		assert(v.getDX() == -10.0 and v.getDY() == 10.0);
	}
	void getDrirectionUp() {
		//setup
		Velocity v;
		mathFunctions math;
		v.setDX(0.0);
		v.setDY(1.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		double result = math.AngleFromComponents(dx, dy);
		//verify
		assert(result == 0);
	}
	void getDirecttionRight() {
		//setup
		Velocity v;
		mathFunctions math;
		v.setDX(1.0);
		v.setDY(1.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		double result = math.AngleFromComponents(dx, dy);
		//verify
		assert(result == (2 * acos(0.0)) / 4);
		//assert(3.14 > result > 0 );
	}
	void getDirectionLeft() {
		//setup
		Velocity v;
		mathFunctions math;
		v.setDX(-1.0);
		v.setDY(0.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		double result = math.AngleFromComponents(dx, dy);
		//verify
		assert(result == -(2 * acos(0.0)) / 2);
	}
	void getDirectionDown() {
		//setup
		Velocity v;
		mathFunctions math;
		v.setDX(0.0);
		v.setDY(-1.0);
		//exercise
		double dx = v.getDX();
		double dy = v.getDY();
		double result = math.AngleFromComponents(dx, dy);
		//verify
		assert(result == 2 * acos(0.0));
	}
};