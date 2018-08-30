#include "Point.h"
#include<math.h>
using namespace std;


Point::Point()
{
	xCoord = 0.0;
	yCoord = 0.0;
	zCoord = 0.0;
}

Point::Point(double _xCoord, double _yCoord, double _zCoord)
{
	xCoord = _xCoord;
	yCoord = _yCoord;
	zCoord = _zCoord;
}

double Point::getX()
{
	return xCoord;
}

double Point::getY()
{
	return yCoord;
}

double Point::getZ()
{
	return zCoord;
}

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