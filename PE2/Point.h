#ifndef _POINT_H_
#define _POINT_H_
#include <vector>

using namespace std;

class Point
{
private:
	std::vector<int> nCoordinates;

public:
	Point();
	Point(vector<int> inputVector);
	int numDimensions(vector<int> number);
	int getCoordinate(int desiredCoord);
	double euclDist3D(Point p1, Point p2);
};

#endif