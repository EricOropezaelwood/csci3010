#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Rectangle.h"



//TEST_CASE ( "Factorials are computed", "[factorial]") {
  //REQUIRE( Factorial(1) == 1 );
  //REQUIRE( Factorial(2) == 2 );
  //REQUIRE( Factorial(3) == 6 );
  //REQUIRE( Factorial(10) == 3628800 );
//}

TEST_CASE ( "Constructor", "[rectangle]")
{
	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);

	SECTION( "Constructor" )
	{
		REQUIRE(p3.x == 0);
	}
	SECTION( "Get the width" )
	{
		REQUIRE( r.GetWidth() == 2 );
	}
	SECTION( "Get the height")
	{
		REQUIRE( r.GetHeight() == 2 );
	}
	SECTION( "True if overlaps")
	{
		Point p5;
		Point p6;
		p5.x = 0;
		p5.y = 0;
		p6.x = 2;
		p6.y = 2;
		Rectangle s (p5, p6);

		REQUIRE( r.Overlaps(s) == true );
	}
	SECTION( "Calculate the area")
	{
		int width = r.GetWidth();
		int length = r.GetHeight();
		int area = width*length;

		REQUIRE( r.CalculateArea() ==  area );
	}
	SECTION( "Expand the rectangle")
	{
		int beforeW = r.GetWidth();
		r.Expand();
		int afterW = r.GetWidth();
		bool val;
		if(afterW > beforeW)
		{
			val = true;
		}
		else
		{
			val = false;
		}

		REQUIRE( val == true );
	}
	SECTION("Shrink the rectangle")
	{
		int beforeW = r.GetWidth();
		r.Shrink();
		int afterW = r.GetWidth();
		bool val;
		if(afterW < beforeW)
		{
			val = true;
		}
		else
		{
			val = false;
		}

		REQUIRE( val == true );
	}

	
}





/**


TEST_CASE ( "Get the width", "[getWidth]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);
	REQUIRE( r.GetWidth() == 2 );
}

TEST_CASE ( "Get the height", "[getheight]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);
	REQUIRE( r.GetHeight() == 2 );
}


TEST_CASE ( "True if overlaps", "[overlaps]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);

	Point p5;
	Point p6;
	p5.x = 0;
	p5.y = 0;
	p6.x = 2;
	p6.y = 2;
	Rectangle s (p5, p6);

	REQUIRE( r.Overlaps(s) == true );
}

TEST_CASE ( "Calculate the area", "[calculateArea]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);
	int width = r.GetWidth();
	int length = r.GetHeight();
	int area = width*length;

	REQUIRE( r.CalculateArea() ==  area );
}

TEST_CASE ( "Expand the rectangle", "[expand]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);
	int beforeW = r.GetWidth();
	r.Expand();
	int afterW = r.GetWidth();
	bool val;
	if(afterW > beforeW)
	{
		val = true;
	}
	else
	{
		val = false;
	}

	REQUIRE( val == true );
}

TEST_CASE ( "Shrink the rectangle", "[shrink]") {

	Point p3;
	Point p4;
	p3.x = 0;
	p3.y = 0;
	p4.x = 2;
	p4.y = 2;
	Rectangle r (p3, p4);
	int beforeW = r.GetWidth();
	r.Shrink();
	int afterW = r.GetWidth();
	bool val;
	if(afterW < beforeW)
	{
		val = true;
	}
	else
	{
		val = false;
	}

	REQUIRE( val == true );
}
**/