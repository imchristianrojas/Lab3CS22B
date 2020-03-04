#pragma once
/*
CIS 22B
Lab 3: Make A Rectangle Class and overload the +, -,<<, and >> operators
Author: Christian Rojas
Date:03/03/2020
Professor Goel

Pseudocode Rectangle.h:

Declared Rectangle's attributes which are the left lower endpoint (x1,y1) and the right upper endpoint (x2,y2) so thatRectangles are parallel.
Created default constructor with not parameters
Created Construcotr Initialization list
Define proper Assessors
Define proper Mutators
Overload + operator as class member
Overload - operator as friend function
Overload << operator as friend function
Overload >> operator as friend function

*/
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>



class Rectangle {

	//Attributes
private:
	int x1, x2, y1, y2;
	std::string name;
public:
	Rectangle();
	Rectangle(int, int, int, int, std::string);
	~Rectangle();


	//Accessors
	int getArea();
	int getPerimeter();
	int getX1();
	int getX2();
	int getY1();
	int getY2();
	std::string getName();


	//Mutators
	void setX1(int);
	void setX2(int);
	void setY1(int);
	void setY2(int);
	void setName(std::string);


	//Overloading Operators
	Rectangle operator+(const Rectangle &A);
	friend Rectangle operator-(const Rectangle &rect1, const Rectangle &rect2);
	friend std::ostream & operator << (std::ostream &out,  Rectangle &a);
	friend std::istream & operator >> (std::istream &in, Rectangle &b);

};
