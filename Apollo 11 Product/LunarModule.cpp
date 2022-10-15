#include "physicsEquations.cpp"
#include <tuple>


class LunarModule {
private:
	
	int fuel = 3000;
	int altitude = 0;
	double speed = 0;
	double velocity = 0;
	double lastAcceleration = 0;
	MathFun math;
	

public:

	void setLastAcceleration(double a) {
		lastAcceleration = a;
	}

	int getFuel() {
		return fuel;
	}

	int getAltitude() {
		return altitude;
	}

	double getSpeed() {
		return speed;
	}
	void setFuel(int newFuel) {
		fuel = newFuel;
	}

	void updateFuel(int fuelChange) {
		fuel += fuelChange;
	}

	void updateAltitude(int altitudeChange) {
		altitude += altitudeChange;
	}

	void updateSpeed(double speedChange) {
		speed = speedChange;
	}

	double getLastAcceleration() {
		return lastAcceleration;
	}

	tuple<double, double> moveLM(double radians) {
		double degrees = convertToDegrees(radians);
		double ddx = math.Computeddx(degrees);
		double ddy = math.Computeddy(degrees);
		return std::make_tuple(ddx, ddy);
		
	}

	double convertToDegrees(double input) {
		double pi = 2 * acos(0.0); // Solve PI
		double degrees = (input * 360) / (2 * pi);
		return degrees;
	}

};