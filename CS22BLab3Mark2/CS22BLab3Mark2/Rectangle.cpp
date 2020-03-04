
/*
CIS 22B
Lab 3: Make A Rectangle Class and overload the +, -,<<, and >> operators
Author: Christian Rojas
Date:03/03/2020
Professor Goel



Pseudocode Rectangle.cpp:

For Default Constructor initialize attribbuts to default values
For Constructor Initalization list assign attributes to user input
Define Destructor with proper message
Write the defintions for mutators, assessors
Functions getArea() and getPerimeters() return area and perimeter accoridingly


*/


#include <stdio.h>
#include "rectangle.h"

//default set the point at origin
Rectangle::Rectangle()
{
	x1 = 0;
	x2 = 0;
	y1 = 0;
	y2 = 0;
	name = " ";
}
//initialization list
Rectangle::Rectangle(int x1, int y1, int x2, int y2, std::string name)
	: x1(x1), y1(y1), x2(x2), y2(y2), name(name)
{}

//Destructor
Rectangle::~Rectangle()
{
	std::cout << "Deleted Rectangle named:  " << this->name << std::endl;
}

//Mutators
void Rectangle::setX1(int pX1) { x1 = pX1; }
void Rectangle::setX2(int pX2) { x2 = pX2; }
void Rectangle::setY1(int pY1) { y1 = pY1; }
void Rectangle::setY2(int pY2) { y2 = pY2; }
void Rectangle::setName(std::string na) { name = na; }

//Assessors
std::string Rectangle::getName() { return name; }
int Rectangle::getX1() { return x1; }
int Rectangle::getX2() { return x2; }
int Rectangle::getY1() { return y1; }
int Rectangle::getY2() { return y2; }





int Rectangle::getArea() {

	int area = (x2 - x1) * (y2 - y1);
	return area;

}

int Rectangle::getPerimeter() {

	return (2 * (x2 - x1) + 2 * (y2 - y1));

}

/*
Pseudocode for Overloaded Operators

Operator +:
Find what Rectangle is untop of the other
Assign the highest yValue to the highest between both Rectangles
Assign the furthest Right xValue to the greater xValue from both
Assign the Lowest yValue to the lowestY between both Rectangles
Assign the closest Left xValue to the lowest xValue from both
return Rectangle object initalized with the all four integers with "Added Rectangle"

Operator - :
First checks to see if there is a overlap or not.If not returns Rectangle with attriubutes all zeros
Next checks to see if there is a rectangle inside of another rectangle if yes returns the inner rectangle
set int x1 to the greatest x Value between both Rectangles
set int y1 to the greatest y Value between both Rectangles
set int x2 to the lowest x Value between both Rectangles
set int y2 to the lowest Y Value between both Rectangles
Return Rectangle Object initalize with those four integers with name "Subtracted Rectangle"

Operator <<:
print out a prompt that includes all four corners as well as area and perimeter
return out;

Operator >>:

Ask User To Input Name
Assign value to name attribute
Ask User to input first x point. 
Assign value to x1 attribute
Ask User to input first y point.
Assign value to y1 attribute.
Ask User to input second x point.
if User input is equal to the first x value then ask again for another x value.
Assign value to x2 attribute
Ask User to input second y point.
if user Input is equal to or lower than(to mantain consistency with the specifications) the first Y value Ask User again
Assign value to y2 attribute
Return in;

*/

//Operator Overloads

Rectangle Rectangle::operator+(const Rectangle &rect)
{
	int yTop, xRight;
	int yBot, xLeft;

	//Gets the hightest Y Value and X value.
	yTop = (this->y2 > rect.y2) ? this->y2 : rect.y2;
	xRight = (rect.x2 > this->x2) ? rect.x2 : this->x2;

	//Gets the Lowerst Y value and X value.
	yBot = ((this->y1<rect.y1) ? this->y1 : rect.y1);
	xLeft = ((this->x1<rect.x1) ? this->x1 : rect.x1);

	return Rectangle(xLeft, yBot, xRight, yTop, "Added Rectangle");
}


Rectangle operator-(const Rectangle &ARect, const Rectangle &BRect)
{

	int x1, y1, x2, y2;

	//Check to see if there is an overlap or not
	if (ARect.x2<BRect.x1 || BRect.x2<ARect.x1 || ARect.y1 > ARect.y2 || BRect.y1 > ARect.y2)
		return Rectangle(0, 0, 0, 0, "No overlap");

	// if BRectangle is inside of aRectangle then return BRectangle
	if ((BRect.x2<ARect.x2 && BRect.x2>ARect.x1) && (BRect.x1 > ARect.x1 && BRect.x1 < ARect.x2) && (BRect.y1 > ARect.y1 && BRect.y1 < ARect.y2)
		&& (BRect.y2 < ARect.y2 && BRect.y2 > ARect.y1)) {
		return BRect;
	}
	//if ARectangle is inside of BRectangle then return ARectangle
	else if ((ARect.x2<BRect.x2 && ARect.x2>BRect.x1) && (ARect.x1 > BRect.x1 && ARect.x1 < BRect.x2) && (ARect.y1 > BRect.y1 && ARect.y1 < BRect.y2)
		&& (ARect.y2 < BRect.y2 && ARect.y2 > BRect.y1)) {
		return ARect;

	}
	//Set the Coordinates to the maximum value of each Rectangle
	x1 = std::max(ARect.x1, BRect.x1);
	y1 = std::max(ARect.y1, BRect.y1);

	//Set the Coordinates to the minimum value of each Rectangle
	x2 = std::min(ARect.x2, BRect.x2);
	y2 = std::min(ARect.y2, BRect.y2);

	return Rectangle(x1, y1, x2, y2, "Subtracted Rectangle");

}

// out operator overload
std::ostream & operator << (std::ostream &out, Rectangle &a)
{
	out << a.name << "'s four corners are at (" << a.x1 << "," << a.y1 << ") ,(" << a.x1 << ',' << a.y2 <<
		"), (" << a.x2 << ',' << a.y2 << "), (" << a.x2 << ',' << a.y1 << ")." << '\n' << a.name <<
		"'s area is "<<a.getArea()<<  " and perimeter is "<<a.getPerimeter()<<'\n'<< std::endl;

	return out;
}

// in operator overload
std::istream & operator >> (std::istream &in, Rectangle &b)
{

	std::cout << "Please enter the name of your rectangle: ";
	getline(in, b.name);
	std::cout << "\nPlease enter the first x point: ";
	in >> b.x1;
	std::cout << "\nPlease enter the first y point: ";
	in >> b.y1;
	std::cout << "\nPlease enter the second x point: ";
	in >> b.x2;

	//Input Validation, cannot allow user to enter same value.
	if (b.x1 == b.x2)
	{
		while (b.x1 == b.x2)
		{
			std::cout << "You already enter that value please try another one." << std::endl;
			in >> b.x2;
		}
	}

	std::cout << "\nPlease enter the second y point: ";
	in >> b.y2;
	
	//Input Validation: Cannot have same Y value or Lower Y to be consistent with Top Right requirement from specifications.
	if (b.y1 == b.y2||(b.y2<b.y1))
	{
		while (b.y1 == b.y2 || b.y2 < b.y1)
		{
			if (b.y2 < b.y1) {
				std::cout << "Value cannot be less than the first Y value please try another one. " << std::endl;
				in >> b.y2;

			}
			else {
				std::cout << "You already enter that value please try another one." << std::endl;
				in >> b.y2;
			}
		}
	}
	in.ignore();
	
	return in;
}