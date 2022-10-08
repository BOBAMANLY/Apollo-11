class LunarModule {
private:
	int fuel = 3000;
	int altitude = 0;
	double speed = 0;

public:

	int getFuel() {
		return fuel;
	}

	int getAltitude() {
		return altitude;
	}

	double getSpeed() {
		return speed;
	}

	void updateFuel(int fuelChange) {
		fuel += fuelChange;
	}

	void updateAltitude(int altitudeChange) {
		altitude += altitudeChange;
	}

	void updateSpeed(double speedChange) {
		speed += speedChange;
	}
};