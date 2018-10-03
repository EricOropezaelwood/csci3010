#include "Rectangle.h"
#include <iostream>
/**
Author: Eric Oropezaelwood
Date: 24 September 2018
PE5

**/

using namespace std;

/**
    Initialize a rectangle given two points

    @param two points

    Bug: It looked like there were 2 Rectangle(Point p1, Point p2) in the original file
*/
Rectangle::Rectangle(Point p1, Point p2)
{
	p1_ = p1;
	p2_ = p2;
}

/**
    Find the width of the rectangle

    @param none
    @return int value of p2_ x - p1_ x
*/
int Rectangle::GetWidth()
{
	int x1 = p1_.x;
	int x2 = p2_.x;
	int width = x2-x1;
	return width;
}

/**
    Find the height of the rectangle

    @param none
    @return int value of p2_ y - p1_ y
*/
int Rectangle::GetHeight()
{
	int y1 = p1_.y;
	int y2 = p2_.y;
	int height = y2-y1;
	return height;
}

/**
    See if the given rectangle object shares a point with the original point

    @param Rectangle object
    @return true or false 

    Bug: When I rant the test this function did not return what it was supposed to
*/
bool Rectangle::Overlaps(Rectangle& other)
{
	if(((other.p1_.x == p1_.x) || (other.p2_.x == p2_.x)) && ((other.p1_.x == p1_.x) || (other.p2_.y == p2_.y)))
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
    Calculate the area of the current Rectangle

    @param none
    @return int value of rectangle's width*height
*/
int Rectangle::CalculateArea()
{
	int width = GetWidth();
	int height = GetHeight();
	int area = width*height;
	return area;	
}

/**
	Moves the bottom left coordinate down one and to the left one
	Moves the upper right coordinate up one and to the right one

    @param none
    @return nono
*/
void Rectangle::Expand()
{
	p1_.x = p1_.x - 1;
	p1_.y = p1_.y - 1;
	p2_.x = p2_.x + 1;
	p2_.y = p2_.y + 1;
}

/**
	Moves the bottom left coordinate up one and to the right one
	Moves the upper right coordinate down one and to the left one

    @param none
    @return nono
*/
void Rectangle::Shrink()
{
	p1_.x = p1_.x + 1;
	p1_.y = p1_.y + 1;
	p2_.x = p2_.x - 1;
	p2_.y = p2_.y - 1;
}