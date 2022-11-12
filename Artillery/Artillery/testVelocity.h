#pragma once
#include "velocity.h";
#include "direction.cpp"
#include <cassert>

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
		getDirectionUpRight();
		getDirectionLeft();
		getDirectionDown();
		addVelUpRight();
		addVelDownRight();

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
		v.reverse();
		//verify
		assert(v.getDX() == -10.0);
	}
	void correctTestReverseDY() {
		//setup
		Velocity v;
		v.setDY(10.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDY() == -10.0);
	}
	void negativeReverseDX() {
		//setup
		Velocity v;
		v.setDX(-10.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDX() == 10.0);
	}
	void negativeReverseDY() {
		//setup
		Velocity v;
		v.setDY(-10.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDY() == 10.0);
	}
	void reverseZeroDX() {
		//setup
		Velocity v;
		v.setDX(0.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDX() == 0.0);
	}
	void reverseZeroDY() {
		//setup
		Velocity v;
		v.setDY(0.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDY() == 0.0);

	}
	void reverseOpposites1() {
		//setup
		Velocity v;
		v.setDX(-10.0);
		v.setDY(10.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDX() == 10.0 and v.getDY() == -10.0);
	}
	void reverseOpposites2() {
		//setup
		Velocity v;
		v.setDX(10.0);
		v.setDY(-10.0);
		//exercise
		v.reverse();
		//verify
		assert(v.getDX() == -10.0 and v.getDY() == 10.0);
	}
	void getDrirectionUp() {
		//setup
		Velocity v;
		v.setDX(0.0);
		v.setDY(1.0);
		//exercise
		v.setDirection(v.getDX, v.getDY);
		//verify
		assert(v.getDirection == 0);
	}
	void getDirecttionRight() {
		//setup
		Velocity v;
		v.setDX(1.0);
		v.setDY(1.0);
		//exercise
		v.setDirection(v.getDX, v.getDY);
		//verify
		assert(v.getDirection == pi / 2);
	}
	void getDirectionUpRight() {
		//setup
		Velocity v;
		v.setDX(1.0);
		v.setDY(1.0);
		//exercise
		v.setDirection(v.getDX, v.getDY);
		//verify
		assert(v.getDirection == pi / 4);
	}
	void getDirectionLeft() {
		//setup
		Velocity v;
		v.setDX(-1.0);
		v.setDY(0.0);
		//exercise
		v.setDirection(v.getDX, v.getDY);
		//verify
		assert(v.getDirection == -pi / 2);
	}
	void getDirectionDown() {
		//setup
		Velocity v;
		v.setDX(0.0);
		v.setDY(-1.0);
		//exercise
		v.setDirection(v.getDX, v.getDY);
		//verify
		assert(v.getDirection == pi);
	}
	void addVelUpRight() {
		//setup
		Velocity v;
		v.setDX(0.0);
		v.setDY(1.0);
		//exercise
		v.addDX(0.0);
		v.addDY(1.0);
		v.addV(v.setDX, v.setDY);
		//verify
		assert(*this == (1.0, 1.0);
		//teardown
		delete v
	}
	void addVelDownRight() {
		//setup
		Velocity v;
		v.setDX(4.0);
		v.setDY(0.0);
		//exercise
		v.addDX(0.0);
		v.addDY(-3.0);
		v.addV(v.setDX, v.setDY);
		//verify
		assert(*this == (4.0, -3.0);
	}
};