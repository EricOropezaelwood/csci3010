#include "Point.h"
#include <iostream>
#include<math.h>
#include <vector>
using namespace std;

/**
    Initialized a point 

    @param none
    @return none
*/

Point::Point()
{
	// blah
}

/**
    Initalizes an n-dimensional point given a vector

    @param vector of dimensions
    @return An n-dimensional point
*/

Point::Point(vector<int> inputVector)
{
    // copy input vector into class vector
    for (int d = 0; d < inputVector.size(); d++)
    {
        nCoordinates.push_back(inputVector[d]);
    }
}

/**
    Retreives the number of dimensions

    @param A point
    @return The number of dimensions for this point
*/

int Point::numDimensions(vector<int> number)
{
    int amount = number.size();
    return amount;
}

/**
    Retreives the requested coordinate of a point

    @param Number to represent the dimension
    @return Coordinate
*/

int Point::getCoordinate(int desiredCoord)
{
    int theCoord = nCoordinates[desiredCoord];
    return theCoord;
}

/**
    Calculates the euclidean distance of 2 n-dimensional points

    @param 2 different points
    @return euclidean distance as a double or an error message
*/

double Point::euclDist3D(Point p1, Point p2)
{
    // get the lengths of both points
    int p1Dimen = p1.nCoordinates.size();
    int p2Dimen = p2.nCoordinates.size();
    // initialize a total and difference
    double total = 0;
    double diff = 0;

    // if the lengths are equal
    if (p1Dimen == p2Dimen)
    {
        for (int k = 0; k < p1Dimen; k++)
        {
            // get the difference of the two points at every spot in the vectors
            diff = p2.nCoordinates[k] - p1.nCoordinates[k];
            // cumutalive total + difference squared
            total = total + (diff*diff);
        }
        // square the cumutalive total
        double answer = sqrt(total);
        return answer;
    }
    // if the dimensions are not equal
    else
    {
        cout << "Your dimensions are not equal" << endl;
        return -1;
    }
}