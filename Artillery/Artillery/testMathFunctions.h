#pragma once


#include "mathFunctions.h";
#include <cassert>



class testMathFunctions {
public:
	void run() {
		toRadiansConversionCorrect();
		toDegreesConversionCorrect();
		IntInputtoRadiansConversionCorrect();
		IntINputtoDegreesConversionCorrect();
		negativeDegrees();
		negativeRadians();
		moreDegreesThanCircle();
		moreRadiansThanCircle();
		correctDragForce();
		intInputToDragForce();
		negativeInputsForDrag();
		CorrectAreaOfCircle();
		NegativeRadiusAreaOfCircle();
		ZeroRadiusAreaOfCircle();
		CorrectForce();
		NegativeForce();
		ZeroForce();
		correctVerticalComponent();
		negativeSpeedVerticalComponent();
		negativeDirectionVerticalComponent();
		correctHorizontalComponent();
		negativeSpeedHorizontalComponent();
		negativeDirectionHorizontalComponent();
		correctAngleFromComponents();
		NegativeAngleFromComponents();
		ZeroAngleFromComponents();
		correctPythagoreanTheorem();
		NegativePythagoreanTheorem();
		ZeroPythagoreanTheorem();
		CorrectInterpoleration();
		ZeroInterpoleration();
		NegativeInterpoleration();
	}
private:
	/*
	TEMPLATE
	void TestName() {
		// Setup
		mathFunctions func;
		// Exercise

		// Verify

		// Teardown
	}
	*/
	
	/* Functions to be tested
	void convertToDegrees(double input);
	void convertToRadians(double input);
	double DragForceEquation(double dragco, double density, double velocity, double surfaceArea);
	double AreaOfCircle();
	double Force(double acceleration);
	double verticalComponentSpeed(double speed, double direction);
	double HorizontalComponentSpeed(double speed, double direction);
	double AngleFromComponents(double dx, double dy);
	double pythagoreanTheorem(double dx, double dy);
	double interpoleration(double r0, double d0, double r1, double d1, double d);
	*/

	void toRadiansConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(50.0);
		// Verify
		assert(func.getRadians() == 0.872665);
		// Teardown
	}
	void IntInputtoRadiansConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(50);
		// Verify
		assert(func.getRadians() == 0.872665);
		// Teardown
	}
	void toDegreesConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(0.872665);
		// Verify
		assert(func.getDegrees() == 50.0);
		// Teardown
	}
	void IntINputtoDegreesConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(10);
		// Verify
		assert(func.getDegrees() == 572.958);
		// Teardown
	}
	void negativeDegrees() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(-50.0);
		// Verify
		assert(func.getRadians() == -0.872665);
		// Teardown
	}
	void negativeRadians() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(-0.872665);
		// Verify
		assert(func.getDegrees() == -50.0);
		// Teardown
	}
	void moreDegreesThanCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(361.0);
		// Verify
		assert(func.getRadians() == 6.30064);
		// Teardown
	}
	void moreRadiansThanCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(6.30064);
		// Verify
		assert(func.getDegrees() == 361.0);
		// Teardown
	}
	
	void correctDragForce() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.DragForceEquation(10.0, 50.0, 10.0, 20.0) == 500000);
		// Teardown
	}
	void intInputToDragForce() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.DragForceEquation(10, 50, 10, 20) == 500000);
		// Teardown
	}
	void negativeInputsForDrag() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.DragForceEquation(-10.0, -50.0, -10.0, -20.0) == -500000);
		// Teardown
	}
	void CorrectAreaOfCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.AreaOfCircle(10) == 314.16);
		// Teardown
	}
	void NegativeRadiusAreaOfCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.AreaOfCircle(-10) == NULL);
		// Teardown
	}
	void ZeroRadiusAreaOfCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.AreaOfCircle(0) == NULL);
		// Teardown
	}
	void CorrectForce() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.Force(10) == 467);
		// Teardown
	}
	void NegativeForce() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.Force(-10) == -467);
		// Teardown
	}
	void ZeroForce() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.Force(0) == 0);
		// Teardown
	}
	void correctVerticalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.verticalComponentSpeed(10, 10) == 9.84807753012208);
		// Teardown
	}
	void negativeSpeedVerticalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.verticalComponentSpeed(-10, 10) == -9.84807753012208);
		// Teardown
	}
	void negativeDirectionVerticalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.verticalComponentSpeed(10, -10) == 9.84807753012208);
		// Teardown
	}
	void correctHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.HorizontalComponentSpeed(10, 10) == 1.736481776669303);
		// Teardown
	}
	void negativeSpeedHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.HorizontalComponentSpeed(-10, 10) == -1.736481776669303);
		// Teardown
	}
	void negativeDirectionHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.HorizontalComponentSpeed(10, -10) == -1.736481776669303);
		// Teardown
	}
	void correctAngleFromComponents() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		//assert(func.AngleFromComponents() == );
		// Teardown
	}
	void NegativeAngleFromComponents() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.AngleFromComponents(-1, 1) < 0);
		// Teardown
	}
	void ZeroAngleFromComponents() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.AngleFromComponents(0, 0) == 0);
		// Teardown
	}
	void correctPythagoreanTheorem() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.pythagoreanTheorem(10, 10) == 14.14214);
		// Teardown
	}
	void NegativePythagoreanTheorem() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.pythagoreanTheorem(-10, 10) == NULL);
		// Teardown
	}
	void ZeroPythagoreanTheorem() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.pythagoreanTheorem(0, 0) == NULL);
		// Teardown
	}
	void CorrectInterpoleration() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.interpoleration(1, 1, 1, 1, 1) == 0);
		// Teardown
	}
	void ZeroInterpoleration() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.interpoleration(0, 0, 0, 0, 0) == 0);
		// Teardown
	}
	void NegativeInterpoleration() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(func.interpoleration(1, -1, 1, -1, 0) == 1);
		// Teardown
	}
};