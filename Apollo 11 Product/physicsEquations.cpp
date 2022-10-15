// Apollo_5_sec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*************************************************************
 * 1. Name:
 *      Jacob Fisher, Joseph Gyman
 * 2. Assignment Name:
 *      Lab 02: Apollo 11
 * 3. Assignment Description:
 *      Simulate the Apollo 11 landing
 * 4. What was the hardest part? Be as specific as possible.
 *      We were easily able to implement a loop and get the format down, but the answer key was wrong so we thought we were wrong.
 *      This left us trying to fix a problem that did not exist.
 * 5. How long did it take for you to complete the assignment?
 *      4 Hours
 *****************************************************************/

#include <iostream>  // for CIN and COUT
#include <cmath>     // for Cos(), Sin(), PI
#include <string>
using namespace std;

#define _USE_MATH_DEFINES    // for PI
#define WEIGHT   15103.000   // Weight in KG
#define GRAVITY     -1.625   // Vertical acceleration due to gravity, in m/s^2
#define THRUST   45000.000   // Thrust of main engine, in Newtons (kg m/s^2)
#pragma once
class MathFun {
public:

    /***************************************************
    * COMPUTE DISTANCE
    * Apply inertia to compute a new position using the distance equation.
    * The equation is:
    *     s = s + v t + 1/2 a t^2
    * INPUT
    *     s : original position, in meters
    *     v : velocity, in meters/second
    *     a : acceleration, in meters/second^2
    *     t : time, in seconds
    * OUTPUT
    *     s : new position, in meters
    **************************************************/

    double computeDistance(double s, double v, double a, double t)
    {
        double newPos;
        newPos = (s + (v * t)) + ((0.5) * a * t * t);
        return newPos;
    }

    /**************************************************
     * COMPUTE ACCELERATION
     * Find the acceleration given a thrust and mass.
     * This will be done using Newton's second law of motion:
     *     f = m * a
     * INPUT
     *     f : force, in Newtons (kg * m / s^2)
     *     m : mass, in kilograms
     * OUTPUT
     *     a : acceleration, in meters/second^2
     ***************************************************/

    double computeAcceleration(double f, double m)
    {
        return f / m;
    }

    /***********************************************
     * COMPUTE VELOCITY
     * Starting with a given velocity, find the new
     * velocity once acceleration is applied. This is
     * called the Kinematics equation. The
     * equation is:
     *     v = v + a t
     * INPUT
     *     v : velocity, in meters/second
     *     a : acceleration, in meters/second^2
     *     t : time, in seconds
     * OUTPUT
     *     v : new velocity, in meters/second
     ***********************************************/

    double computeVelocity(double v, double a, double t)
    {
        double velocity;
        velocity = (v + (a * t));
        return velocity;
    }

    /***********************************************
     * COMPUTE VERTICAL COMPONENT
     * Find the vertical component of a velocity or acceleration.
     * The equation is:
     *     cos(a) = y / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     y : the vertical component of the total
     ***********************************************/

    double computeVerticalComponent(double a, double vOA)
    {
        return vOA * cos(a);
    }

    /***********************************************
     * COMPUTE HORIZONTAL COMPONENT
     * Find the horizontal component of a velocity or acceleration.
     * The equation is:
     *     sin(a) = x / total
     * This can be expressed graphically:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    |a/
     *    |/
     * INPUT
     *     a : angle, in radians
     *     total : total velocity or acceleration
     * OUTPUT
     *     x : the vertical component of the total
     ***********************************************/

    double computeHorizontalComponent(double a, double vOA)
    {
        return vOA * sin(a);
    }

    /************************************************
     * COMPUTE TOTAL COMPONENT
     * Given the horizontal and vertical components of
     * something (velocity or acceleration), determine
     * the total component. To do this, use the Pythagorean Theorem:
     *    x^2 + y^2 = t^2
     * where:
     *      x
     *    +-----
     *    |   /
     *  y |  / total
     *    | /
     *    |/
     * INPUT
     *    x : horizontal component
     *    y : vertical component
     * OUTPUT
     *    total : total component
     ***********************************************/

    double computeTotalComponent(double x, double y)
    {
        return sqrt((x * x) + (y * y));
    }

    /*************************************************
     * RADIANS FROM DEGEES
     * Convert degrees to radians:
     *     radians / 2pi = degrees / 360
     * INPUT
     *     d : degrees from 0 to 360
     * OUTPUT
     *     r : radians from 0 to 2pi
     **************************************************/
     // your function goes here
    double convertToRadians(double d)
    {
        double pi = 2 * acos(0.0); // Solve PI
        return ((d * (2 * pi)) / 360);
    }

    /****************************************************************
    * These functions were created to simplify the process, and make it easier to understand and implement.
    * These new functions also allow us to receive the correct solution.
    * They are used to replace the computeHorizontalComponent, computeVerticalComponent and computeAcceleration.
    * These are a combination of the three, and should be more accurate.
    ****************************************************************/

    double Computeddx(double degrees)
    {
        double acceleration = ((THRUST * cos(degrees)) / WEIGHT) * -1;
        return acceleration;
    }
    double Computeddy(double degrees)
    {
        double acceleration = (((THRUST * sin(degrees)) - (GRAVITY * WEIGHT)) / WEIGHT) * -1;
        return acceleration;
    }


};


/**************************************************
 * PROMPT
 * A generic function to prompt the user for a double
 * INPUT
 *      message : the message to display to the user
 * OUTPUT
 *      response : the user's response
 ***************************************************/
/*
double prompt(string message)
{
    double response;
    cout << message << endl;
    cin >> response;
    return response;
}

// Test function to run 3 test cases through automation
int test()
{
    double aRadians;
    double ddx;
    double ddy;
    double v;
    double t = 1.0;
    MathFuntions math;


    // Test Case 1
    cout << endl << "Test 1" << endl;
    double dx = 10.53;
    double dy = -13.959;
    double y = 100.0;
    double x = 0.0;
    double aDegrees = -45.0;
    double newAngle = 0.00;

    aRadians = math.convertToRadians(aDegrees);

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            aRadians = math.convertToRadians(newAngle);
            aDegrees = newAngle;
            cout << "New Angle" << endl;
        }

        // Calculations
        ddx = math.Computeddx(aRadians);
        ddy = math.Computeddy(aRadians);
        dx = math.computeVelocity(dx, ddx, t);
        dy = math.computeVelocity(dy, ddy, t);
        x = math.computeDistance(x, dx, ddx, t);
        y = math.computeDistance(y, dy, ddy, t);
        v = math.computeTotalComponent(dx, dy);

        // Output
        int count = i;
        count++;
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);

        cout << count << "s" << " (X,Y): (" << x << ", " << y << ")m ";
        cout << "(DX, DY): (" << dx << ", " << dy << ")m/s ";
        cout << "Speed: " << v << "m/s " << "Angle: " << aDegrees << " degrees" << endl;
    }

    // Test Case 2
    cout << endl << "Test 2" << endl;
    dx = -35.00;
    dy = -15.000;
    y = 207.77;
    x = 0.0;
    aDegrees = 90.00;
    newAngle = 45.00;

    aRadians = math.convertToRadians(aDegrees);

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            aRadians = math.convertToRadians(newAngle);
            aDegrees = newAngle;
            cout << "New Angle" << endl;
        }

        // Calculations
        ddx = math.Computeddx(aRadians);
        ddy = math.Computeddy(aRadians);
        dx = math.computeVelocity(dx, ddx, t);
        dy = math.computeVelocity(dy, ddy, t);
        x = math.computeDistance(x, dx, ddx, t);
        y = math.computeDistance(y, dy, ddy, t);
        v = math.computeTotalComponent(dx, dy);

        // Output
        int count = i;
        count++;
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);

        cout << count << "s" << " (X,Y): (" << x << ", " << y << ")m ";
        cout << "(DX, DY): (" << dx << ", " << dy << ")m/s ";
        cout << "Speed: " << v << "m/s " << "Angle: " << aDegrees << " degrees" << endl;
    }

    // Test Case 3
    cout << endl << "Test 3" << endl;
    dx = 10.00;
    dy = -10.000;
    y = 56.11;
    x = 0.0;
    aDegrees = -42.185;
    newAngle = 0;

    aRadians = math.convertToRadians(aDegrees);

    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            aRadians = math.convertToRadians(newAngle);
            aDegrees = newAngle;
            cout << "New Angle" << endl;
        }

        // Calculations
        ddx = math.Computeddx(aRadians);
        ddy = math.Computeddy(aRadians);
        dx = math.computeVelocity(dx, ddx, t);
        dy = math.computeVelocity(dy, ddy, t);
        x = math.computeDistance(x, dx, ddx, t);
        y = math.computeDistance(y, dy, ddy, t);
        v = math.computeTotalComponent(dx, dy);

        // Output
        int count = i;
        count++;
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);

        cout << count << "s" << " (X,Y): (" << x << ", " << y << ")m ";
        cout << "(DX, DY): (" << dx << ", " << dy << ")m/s ";
        cout << "Speed: " << v << "m/s " << "Angle: " << aDegrees << " degrees" << endl;
    }
    return 0;
}
*/
/****************************************************************
 * MAIN
 * Prompt for input, compute new position, and display output
 ****************************************************************/
 /*
int main()
{
    /*
    Test Case Name	Vertical Velocity	Horizontal Velocity	Altitude	Initial Angle	New Angle
    Hard landing	-13.959	10.53	100.0	-45	0
    Crash	-15.000	-35.00	207.77	90	45
    Armstrong is awesome!	-10.000	10.00	56.11	-42.185	0
    

    // Test function
    //test();


    // Prompt for input and variables to be computed
    double dx = prompt("What is your horizontal velocity (m/s)? ");
    double dy = prompt("What is your vertical velocity (m/s)? ");
    double y = prompt("What is your altitude (m)? ");
    double x = 0.0;
    double aDegrees = prompt("What is the angle of the LM where 0 is up (degrees)? ");
    double t = 1.0;
    double aRadians;            // Angle in radians
    //double accelerationThrust;  // Acceleration due to thrust 
    //double ddxThrust;           // Horizontal acceleration due to thrust
    //double ddyThrust;           // Vertical acceleration due to thrust
    double ddx;                 // Total horizontal acceleration
    double ddy;                 // Total vertical acceleration
    double v;                   // Total velocity

    // Go through the simulator five times

    MathFuntions math;
    aRadians = math.convertToRadians(aDegrees);


    for (int i = 0; i < 10; i++)
    {
        if (i == 5)
        {
            aDegrees = prompt("What is the new angle of the LM where 0 is up (degrees)? ");
            aRadians = math.convertToRadians(aDegrees);
        }

        // Calculations
        ddx = math.Computeddx(aRadians);
        ddy = math.Computeddy(aRadians);
        dx = math.computeVelocity(dx, ddx, t);
        dy = math.computeVelocity(dy, ddy, t);
        x = math.computeDistance(x, dx, ddx, t);
        y = math.computeDistance(y, dy, ddy, t);
        v = math.computeTotalComponent(dx, dy);

        // Output
        int count = i;
        count++;
        cout.setf(ios::fixed | ios::showpoint);
        cout.precision(2);
        /* Old Output
        cout << "\tNew position:" << count << "s  (" << x << ", " << y << ")m\n";
        cout << "\tNew velocity:" << count << "s  (" << dx << ", " << dy << ")m/s\n";
        cout << "\tTotal velocity:" << count << "s  " << v << "m / s\n\n";
        
        // New Output
        cout << count << "s" << " (X,Y): (" << x << ", " << y << ")m ";
        cout << "(DX, DY): (" << dx << ", " << dy << ")m/s ";
        cout << "Speed: " << v << "m/s " << "Angle: " << aDegrees << " degrees" << endl;

    }

    return 0;
}
*/