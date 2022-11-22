#include "projectile.h"
#include "ground.h"
#include <chrono>
#include <tuple>
using namespace std;


void projectile::reset() {
	mass = NULL;
	radius = NULL;
	flightpath.clear();
}
//void fire();
//advance();
//draw();
bool projectile::isFlying() {
	if (flightpath.empty() == false) {
		return true;
	}
	else {
		return false;
	}
}
double projectile::getAltitude() {
	Position pos = getPosition();
	double altitude;
	Ground ground;
	altitude = ground.getElevationMeters(pos);
	return altitude;
}
Position projectile::getPosition() {
	return flightpath.back();
}
double projectile::getFlightTime() {
	return 0.0;
}
double projectile::getFlightDistance() {
	return 0.0;
}
double projectile::getSpeed() {
	return 0.0;
}
auto projectile::getCurrentTime() {
	auto time = std::chrono::system_clock::now();
	return time;
}
void projectile::setMass(double input) {
	mass = input;
}
void projectile::setRadius(double input) {
	radius = input;
}