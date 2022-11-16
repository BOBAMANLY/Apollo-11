#pragma once

/*
class Velocity {
public:
	//Constructors and assignment operators
	Velocity() : dx(0.0), dy(0.0) {}
	Velocity(double dx, double dy) : dx(dx), dy(dy) {}
	Velocity(const Velocity & rhs) : dx(rhs.dx), dy(rhs.dy) {}
	Velocity& operator = (const Velocity& rhs)
	{
		dx = rhs.dx;
		dy = rhs.dy;
		return *this;
	}

	// Getters
	double getDX() const { return dx; }
	double getDY() const { return dy; }
	double getSpeed() const;
	double getDirection() const;

	//Setters
	void setDX(double dx) { this->dx = dx; }
	void setDY(double input);
	void setDxDy(double dx, double dy)
	{ 
		this->dy = dy; this->dy = dy; 
	}

	void setDirection(const Direction& direction)
	{
		setSpeedDirection(getSpeed(), direction);
	}

	void setSpeed(double speed)
	{
		setSpeedDirection(speed, getDirection());
	}

	void setSpeedDirection(double speed, const Direction & direction);
	
	void addDX(double dx) { setDX(getDX() + dx); }
	void addDY(double dy) { setDY(getDY() + dy); }
	void addV(const Velocity& v)
	{
		dx += v.dx;
		dy += v.dy;
	}

	Velocity& operator += (const Velocity& rhs)
	{
		addV(rhs);
		return *this;
	}

	void reverse()
	{
		dx *= -1.0;
		dy *= -1.0;
	}
};*/