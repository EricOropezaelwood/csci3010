#include "Point.h"
#include<math.h>
using namespace std;

/**
    Initialized a point with all zeros

    @param none
    @return a 3-dimensional point
*/

Point::Point()
{
	xCoord = 0.0;
	yCoord = 0.0;
	zCoord = 0.0;
}

/**
    Initalizes a 3-dimensional point given an x, y and z-zoordinate

    @param x, y and z-coordinate
    @return A 3-dimensional point
*/

Point::Point(double _xCoord, double _yCoord, double _zCoord)
{
	xCoord = _xCoord;
	yCoord = _yCoord;
	zCoord = _zCoord;
}

/**
    Retreives the x-coordinate of a point

    @param none
    @return x-coordinate
*/

double Point::getX()
{
	return xCoord;
}

/**
    Retreives the y-coordinate of a point

    @param none
    @return y-coordinate
*/

double Point::getY()
{
	return yCoord;
}

/**
    Retreives the z-coordinate of a point

    @param none
    @return z-coordinate
*/

double Point::getZ()
{
	return zCoord;
}

/**
    Calculates the euclidean distance of 2 three dimensional points

    @param x1, x2, y1, y2, z1, z3
    @return euclidean distance as a double
*/

double Point::euclDist3D(double x1, double y1, double z1, double x2, double y2, double z2)
{
	// subtract the second x,y,z coordinates from the first
	double x3 = (x2-x1);
	double y3 = (y2-y1);
	double z3 = (z2-z1);

	// square the previous values and add them all together
	double dist = pow(x3, 2) + pow(y3, 2) + pow(z3, 2);

	// take the square root of the added values
	dist = sqrt(dist);

	return dist;
}