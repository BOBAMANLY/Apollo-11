#pragma once
#include "pos.h";
#include "direction.h";


class howitzer {
private:
	Position position;
	double muzzleVelocity;
	double elevation;
public:
	double getMuzzleVelocity();
	Position getposition();
	void setMuzzleVelocity(double velocity);
	void raise(double radians);
	void rotate(double radians);

	void generatePosition(double size);
	//void draw();
};