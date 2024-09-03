/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Michael and Andrew
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include <iostream>
#include "test.h"
#include "testPosition.h"
#include "testGround.h"
#include "TestVelocity.h"
#include "TestProjectile.h"

using namespace std;

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   TestProjectile().run();
   TestVelocity().run();
   TestPosition().run();
   cout << "Position tests passed" << endl;
   TestGround().run();
   cout << "Ground tests passed" << endl;
}
