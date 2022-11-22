#pragma once
#include <list>
#include "pos.h"
using namespace std;

class projectile {
private:
	double mass;
	double radius;
	list<Position> flightpath;
	
public:
	void reset();
	//void fire();
	//advance();
	//draw();
	bool isFlying();
	double getAltitude();
	Position getPosition();
	double getFlightTime();
	double getFlightDistance();
	double getSpeed();
	auto getCurrentTime();
	void setMass(double input);
	void setRadius(double input);
};