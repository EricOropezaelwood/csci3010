/**
Author: Eric Oropezaelwood
Date: 06 September 2018
PE2

This program will create 2 n-dimensional points and calculate
the euclidean distance between the points with functionality to print out a
specific coordinate upon request.
**/

#include <iostream>
#include <vector>
#include "Point.h"

using namespace std;

int main()
{
	// Create 2 vectors of desired size to be used for setting up points
	vector<int> first {2,4,6};
	vector<int> second {12,24,36};
	// create first point
	Point one (first);
	// create second point
	Point two (second);

/** // use if you want to see a specific coordinates
	int foundCoord = one.getCoordinate(0);
	cout << "The coordinate you requested is: " << foundCoord << endl;
**/
	// calculate the distance between the two points
	double distance = one.euclDist3D(one,two);
	cout <<"The euclidean distance between the two points is: " << distance << endl;

	// display number of dimensions
	int numberOfDimensions = one.numDimensions(first);
	cout <<"The number of dimensions of the point is :" << numberOfDimensions << endl;

	return 0;
}