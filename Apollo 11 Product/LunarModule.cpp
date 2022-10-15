#include "physicsEquations.cpp"


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

};