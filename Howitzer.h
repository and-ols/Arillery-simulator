/***********************************************************************
 * Source File:
 *    Howitzer : The things to do with the gun.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    The gun or artilary piece, which includes
 *    where it is locted and the way it is angled/pointed.
 ************************************************************************/

#pragma once
#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Velocity.h"
#include "Projectile.h"
#include "uiDraw.h"

using namespace std;

/***********************************************************
 * HOWITZER
 * Takes care of the Howitzer, which is the howitzer 
 * that we see on the screen.
 ***********************************************************/
class Howitzer
{
private:
   Position position;
   Direction elevation;
   double flightTime = -1.0;

public:
   // Constructor.
   Howitzer() {};

   // Getters.
   Position getPosition() { return position; }
   Direction getDirection() { return elevation; }
   
   // Setters.
   void setPosition(Position newPosition) {
      position = newPosition;
   }
   void rotate(double radians) { elevation.setRadians
      (elevation.getRadians() + radians); }
   void raise(double radians);
   void draw(double simTime);
   void resetTime() { flightTime = 0.0; }
};

