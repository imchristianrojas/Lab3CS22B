
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


Rectangle::~Rectangle()
{
	std::cout << "Deleted Rectangle named:  " << this->name << std::endl;
}

void Rectangle::setX1(int pX1) { x1 = pX1; }
void Rectangle::setX2(int pX2) { x2 = pX2; }
void Rectangle::setY1(int pY1) { y1 = pY1; }
void Rectangle::setY2(int pY2) { y2 = pY2; }
void Rectangle::setName(std::string na) { name = na; }

std::string Rectangle::getName() { return name; }
int Rectangle::getX1() { return x1; }
int Rectangle::getX2() { return x2; }
int Rectangle::getY1() { return y1; }
int Rectangle::getY2() { return y2; }



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

	if (ARect.x2<BRect.x1 || BRect.x2<ARect.x1 || ARect.y1 > ARect.y2 || BRect.y1 > ARect.y2)
		return Rectangle(0, 0, 0, 0 ,"No overlap");

	
	if(ARect.x1 < BRect.x1)
	{
		x1 = fmax(ARect.x1, BRect.x1);
		y1 = fmax(ARect.y1, BRect.y1);
		x2 = fmin(ARect.x2, BRect.x2);
		y2 = fmin(ARect.y2, BRect.y2);
		
	
	}
	else{
		x1 = fmax(ARect.x1, BRect.x1);
		y1 = fmax(ARect.y1, BRect.y1);
		//y1 = (rect1.y1 < rect2.y1) ? rect1.y1 : rect2.y1;
		x2 = fmin(ARect.x2, BRect.x2);
		//y2 = (rect1.y2 < rect2.y2) ? rect1.y2 : rect2.y2;
		y2 = fmin(ARect.y2, BRect.y2);
		
	}

	return Rectangle(x1, y1, x2, y2, "Subtracted Rectangle");

}


int Rectangle::getArea() {

	int area = (x2 - x1) * (y2 - y1);
	return area;

}

int Rectangle::getPerimeter() {

	return (2 * (x2 - x1) + 2 * (y2 - y1));

}
std::ostream & operator << (std::ostream &out, Rectangle &a)
{

	out << a.name << "'s four corners are at (" << a.x1 << "," << a.y1 << ") ,(" << a.x1 << ',' << a.y2 <<
		"), (" << a.x2 << ',' << a.y2 << "), (" << a.x2 << ',' << a.y1 << ")." << '\n' << a.name <<
		"'s area is"<<a.getArea()<<  " and perimeter is "<<a.getPerimeter()<<'\n'<< std::endl;

	return out;
}

std::istream & operator >> (std::istream &in, Rectangle &b)
{
	
	std::cout << "Please enter the name of your rectangle:";	
	std::getline(in, b.name);
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