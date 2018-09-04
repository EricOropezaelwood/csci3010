/**
Author: Eric Oropezaelwood
Date: 04 September 2018
PE1

This program will create 2 three dimensional points and calculate
the euclidean distance between the points and print out their coordinates.
**/

#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
	// create first point
	Point one(1.1, 2.2, 3.3);
	// create second point
	Point two(11.11, 12.12, 13.13);

	// store the coordinates of both points
	double oneX = one.getX();
	double oneY = one.getY();
	double oneZ = one.getZ();
	double twoX = two.getX();
	double twoY = two.getY();
	double twoZ = two.getZ();

	// calculate the distance between the two points
	double distance = one.euclDist3D(oneX, oneY, oneZ, twoX, twoY, twoZ);
	cout <<"The euclidean distance between the two points is: " << distance << endl;

	// display the coordinates
	cout <<"X coordinate of point one: " << oneX << endl;
	cout <<"Y coordinate of point one: " << oneY << endl;
	cout <<"Z coordinate of point one: " << oneZ << endl;

	cout <<"X coordinate of point two: " << twoX << endl;
	cout <<"Y coordinate of point two: " << twoY << endl;
	cout <<"Z coordinate of point two: " << twoZ << endl;

	return 0;
}