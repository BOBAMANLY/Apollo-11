#pragma once
#include "velocity.h";
#include <cassert>

class testVelocity {
public:
	void run() {
		// Put the function call of each unit test here:
		correctAddDY();
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
	void correctAddDY() {
		// Setup
		velocity v;
		v.setDY(10.0);
		// Exercise
		v.addDY(10.0);
		// Verify
		assert(v.getDY() == 20.0);
		// Teardown
	}
};