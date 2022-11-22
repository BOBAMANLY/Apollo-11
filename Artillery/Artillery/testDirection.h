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
        defaultConstructor();
        correctSetDegrees();
        correctSetRadians();
        correctSetDXDY();
        correctSetLeft();
        correctSetRight();
        correctSetUp();
        correctSetDown();
        correctReverse();
        correctOneRound();
        correctNegative();
        correctLotsaLaps();
        correctRotateNone();
        correctRotate180();
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
        assert(direction.getRadians() == 0.0);
    }  // teardown


    void correctSetDegrees()
    {  // setup
        Direction direction;
        // exercise
        direction.setDegrees(10);
        // verify
        assert(direction.getDegrees() == 10);
        // teardown
    }

    void correctSetRadians()
    {
        //setup
        Direction direction;
        //exercise
        direction.setRadians(1.0);
        //verify
        assert(direction.getRadians() == 1.0);
    } //teardown

    void correctSetDXDY()
    {
        //setup
        Direction direction;
        double dxInput = 2.0;
        double dyInput = 3.0;
        //exercise
        direction.setDXDY(dxInput, dyInput);
        //verify
        assert(direction.getDX() == dxInput);
        assert(direction.getDY() == dyInput);
    }

    void correctSetLeft()
    {
        //setup
        Direction direction;
        //exercise
        direction.setLeft();
        //verify
        assert(direction.getDegrees() == -22.0);
    }

    void correctSetRight()
    {
        //setup
        Direction direction;
        //exercise
        direction.setRight();
        //verify
        assert(direction.getDegrees() == -40);
    }

    void correctSetUp()
    {
        //setup
        Direction direction;
        //exercise
        direction.setUp();
        //verify
        assert(direction.getDegrees() == 0.0);
    }

    void correctSetDown()
    {
        //setup
        Direction direction;
        //exercise
        direction.setDown();
        //verify
        assert(direction.getDegrees() == 180.0);
    }

    void correctReverse()
    {
        //setup
        Direction direction;
        //exercise
        direction.setDegrees(90.0);
        direction.reverse();
        //verify
        assert(closeEnough(direction.getRadians(), -(2 * acos(0.0)), 0.001));
    }

    void correctOneRound()
    {
        //setup
        Direction direction;
        //exercise
        direction.setRadians(0.4 + (acos(0.0) * 2.0));
        //verify
        assert(closeEnough(direction.getRadians(), 0.40001, 0.399));
    }

    void correctNegative()
    {
        //setup
        Direction direction;
        //exercise
        direction.setRadians(-0.34);
        //verify
        assert(direction.getRadians() == -0.34);
    }

    void correctLotsaLaps()
    {
        //setup
        Direction direction;
        //exercise
        direction.setRadians(0.1 + (2.0 * acos(0.0) * 7.0));
        //verify
        assert(direction.getRadians() >= 0.0999 && direction.getRadians() <= 0.1001);
    }

    void correctRotateNone()
    {
        //setup
        Direction direction;
        //exercise
        direction.rotate(0.0);
        //verify
        assert(direction.getRadians() == 0.0);
    }

    void correctRotate180()
    {
        //setup
        Direction direction;
        //exercise
        direction.rotate(180);
        //verify
        assert(direction.getRadians() == 180.0);
    }
};