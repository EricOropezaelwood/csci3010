#ifndef _POINT_H_
#define _POINT_H_

using namespace std;

class Point
{
private:
	double xCoord;
	double yCoord;
	double zCoord;

public:
	Point();
	Point(double _xCoord, double _yCoord, double _zCoord);
	double getX();
	double getY();
	double getZ();
	double euclDist3D(double x1, double y1, double z1, double x2, double y2, double z2);
};

#endif