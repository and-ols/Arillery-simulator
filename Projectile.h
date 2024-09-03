/***********************************************************************
 * Source File:
 *    Projectile : The things to do with the shell.
 * Author:
 *    Andrew Olson, Michael Darling.
 * Summary:
 *    The projectile or shell, which includes 
 *    how it flies and wher it is located.
 ************************************************************************/

#pragma once

#include <iostream>
#include "Position.h"
#include "Direction.h"
#include "Velocity.h"
#include "uiDraw.h"
#include <list>

#define PI                          3.14159   // Pi
#define MASS                           46.7   // Mass in KG
#define DIAMETER                    0.15489   // Diameter in M
#define RADIUS                 DIAMETER / 2   // Radius in M
#define SURFACEAREA  PI * (RADIUS * RADIUS)   // Surface area in M^2
#define INITIALVELOCITY              371.0    // Initial muzzle velocity

using namespace std;

struct lookupTable
{
   double key;
   double value;
};

class TestProjectile;

/*****************************************************************
 * PROJECTILE
 * The projectile class, which is the shell we will see on screen.
 ****************************************************************/
class Projectile
{
   friend TestProjectile;
private:
   Velocity velocity;
   Position position;
   double flightTime = 0.0;
   double flightDistance = 0.0;
   bool isFlying = false;

   // Lookups
   double lookUpGravity();
   double lookUpMach();
   double lookUpDragCo(double mach);
   double lookUpDensity();

   //Math
   double linearInterpolation(const lookupTable lookup[], 
                      int numLookupTable, double domain);
   double dragForceEquation(double dragCo, double density);

public:
   // Constructor
   Projectile() {};
   
   // Other
   void reset();
   void advance(double time);
   void draw(list<Position> projectilePath);

   // Getters.
   double getAltitude() { return position.getMetersY(); }
   Position getPosition() { return position; }
   double getFlightTime() { return flightTime; }
   double getFlightDistance() { return flightDistance; }
   double getSpeed() { return velocity.getSpeed(); }
   double getFlying() { return isFlying; }
   Direction getDirection() { return Direction().getAngleFromComponents
      (velocity.getDX(), velocity.getDY()); }

   // Setters.
   void setPosition(Position position) { this->position = position; }
   void setDirection(double angle);
   void setFlying(bool newFlyingStatus);

   // More math
   void updatePosition(double acceleration, double gravity, 
      double angle, double time);
};