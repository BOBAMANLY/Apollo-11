#pragma once


#include "mathFunctions.h";
#include <cassert>

using namespace std;

class testMathFunctions {
public:
	void run() {
		toRadiansConversionCorrect();
		toDegreesConversionCorrect();
		IntInputtoRadiansConversionCorrect();
		IntINputtoDegreesConversionCorrect();
		negativeDegrees();
		moreDegreesThanCircle();
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
		func.convertToRadians(1.0);
		//cout << "getRadians does this: " << func.getRadians() << endl;
		// Verify
		assert(round(func.getRadians()) == round(565.487));
		// Teardown
	}
	void IntInputtoRadiansConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(50);
		//cout << func.getRadians() << endl;
		// Verify
		assert(round(func.getRadians()) == round(28274.3));
		// Teardown
	}
	void toDegreesConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(0.872665);
		//cout << func.getDegrees() << endl;
		// Verify
		assert(round(func.getDegrees()) == round(493.48));
		// Teardown
	}
	void IntINputtoDegreesConversionCorrect() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToDegrees(10);
		//cout << func.getDegrees() << endl;
		// Verify
		assert(round(func.getDegrees()) == round(5654.87));
		// Teardown
	}
	void negativeDegrees() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(-50.0);
		//cout << func.getRadians() << endl;
		// Verify
		assert(round(func.getRadians()) == round(-28274.3));
		// Teardown
	}
	void moreDegreesThanCircle() {
		// Setup
		mathFunctions func;
		// Exercise
		func.convertToRadians(361.0);
		//cout << func.getRadians() << endl;
		// Verify
		assert(round(func.getRadians()) == round(204141));
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
		//cout << func.AreaOfCircle(10) << endl;
		// Verify
		assert(round(func.AreaOfCircle(10)) == round(314.159));
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
		//cout << func.verticalComponentSpeed(10, 10) << endl;
		// Verify
		assert(round(func.verticalComponentSpeed(10, 10)) == round(-8.39072));
		// Teardown
	}
	void negativeSpeedVerticalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		//cout << func.verticalComponentSpeed(-10, 10) << endl;
		// Verify
		assert(round(func.verticalComponentSpeed(-10, 10)) == round(8.39072));
		// Teardown
	}
	void negativeDirectionVerticalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		//cout << func.verticalComponentSpeed(10, -10) << endl;
		// Verify
		assert(round(func.verticalComponentSpeed(10, -10)) == round(-8.39072));
		// Teardown
	}
	void correctHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		//cout << func.HorizontalComponentSpeed(10, 10) << endl;
		// Verify
		assert(round(func.HorizontalComponentSpeed(10, 10)) == round(9.45598));
		// Teardown
	}
	void negativeSpeedHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		//cout << func.HorizontalComponentSpeed(-10, 10) << endl;
		// Verify
		assert(round(func.HorizontalComponentSpeed(-10, 10)) == round(-10.544));
		// Teardown
	}
	void negativeDirectionHorizontalComponent() {
		// Setup
		mathFunctions func;
		// Exercise
		// Verify
		assert(round(func.HorizontalComponentSpeed(10, -10)) == round(10.544));
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
		//cout << func.pythagoreanTheorem(10, 10) << endl;
		// Verify
		assert(round(func.pythagoreanTheorem(10, 10)) == round(14.1421));
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
		//cout << func.interpoleration(1, 1, 1, 1, 1) << endl;
		// Verify
		assert(func.interpoleration(1, 1, 1, 1, 1) == NULL);
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
		//cout << func.interpoleration(1, -1, 1, -1, 0) << endl;
		// Verify
		assert(func.interpoleration(1, -1, 1, -1, 0) == 0);
		// Teardown
	}
};