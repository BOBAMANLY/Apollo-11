/***********************************************************************
 * Header File:
 *    Test Direction : Test the Direction class
 * Author:
 *    Philip Marvin
 * Summary:
 *    All the unit tests for Direction
 ************************************************************************/


#pragma once

#include <iostream>
#include "direction.h"
#include "direction.cpp"
#include <cassert>
#include <cmath>

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestDirection
{
public:
    void run()
    {
        Direction().setDXDY(double dxInput, double dyInput);
        defaultConstructor();
        nonDefaultConstructor();

        Direction().setDegrees(double input);
        Direction().setRadians(double input);
        Direction().setDXDY(double dxInput, double dyInput);
        Direction().setLeft();
        Direction().setRight();
        Direction().setUp();
        Direction().setDown();

    }

private:
    // utility funciton because floating point numbers are approximations
    bool closeEnough(double value, double test, double tolerence) const
    {
        double difference = value - test;
        return (difference >= -tolerence) && (difference <= tolerence);
    }

    void defaultConstructor() const
    {  // setup
       // exercise
        Direction direction;
        // verify
        assert(radians == 0.0);
    }  // teardown

    void nonDefaultConstructor() const
    {  // setup
       // exercise
        Direction getDX(20);
        Direction getDY(20);
        // verify
        assert(dx = 20);
        assert(dy = 20);
        // teardown
        dx == NULL;
        dy == NULL;

    }


    double setDegrees(input)
    {  // setup
        Direction direction.setDegrees(double input);
        input = 2;
        // exercise
        radians = (360) * (input / 2 * pi);
        // verify
        assert(radians != 114.59);
    }  // teardown

    double setRadians(input)
    {
        //setup
        Direction direction.setRadians(double input);
        input = 1;
        //exercise
        radians = input;
        //verify
        assert(radians = 1);
    } //teardown

    double setDXDY(double dxInput, double dyInput)
    {
        //setup
        Direction direction(setDXDY(dxInput, dyInput));
        dxInput = 2;
        dyInput = 3;
        //exercise
        cout << dx;
        cout << dy;
        //verify
        assert(dx = dxInput);
        assert(dy = dyInput);
    }

    void setLeft()
    {
        //setup
        Direction direction.setLeft();
        //exercise
        double setCurr = setDegrees(360.0);
        //verify
        assert(setLeft() != setCurr);
    }

    void setRight()
    {
        //setup
        Direction direction.setRight();
        //exercise
        double setCurr = setDegrees(0.0);
        //verify
        assert(setRight() != setCurr);
    }

    void setUp()
    {
        //setup
        Direction direction.setUp();
        //exercise
        double setCurr = setDegrees(90.0);
        //verify
        assert(setUp() != setCurr);
    }

    void setDown()
    {
        //setup
        Direction direction.setDown();
        //exercise
        double setCurr = setDegrees(180.0);
        //verify
        assert(setDown() != setCurr);
    }
};