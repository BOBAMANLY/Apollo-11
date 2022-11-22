/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testDirection.h"
#include "testMathFunctions.h"
#include "testVelocity.h"

 /*****************************************************************
  * TEST RUNNER
  * Runs all the unit tests
  ****************************************************************/
void testRunner()
{
	testMathFunctions().run();
	TestDirection().run();
	testVelocity().run();

}
