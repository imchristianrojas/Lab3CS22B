//
//  rectangle.cpp
//  CS22BLab3Mac
//
//  Created by Christian on 2/25/20.
//  Copyright © 2020 Christian Rojas. All rights reserved.
//

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
    std::cout<<"Deleted Rectangle named:  "<<this->name<<std::endl;
}

void Rectangle::setX1(int pX1){x1 = pX1;}
void Rectangle::setX2(int pX2){x2 = pX2;}
void Rectangle::setY1(int pY1){y1 = pY1;}
void Rectangle::setY2(int pY2){y2 = pY2;}
void Rectangle::setName(std::string na){name = na;}
//void Rectangle::setArea()
//{
//    area =(abs(x2-x1) * abs(y2-y1));
//    
//}


std::string Rectangle::getName(){return name;}
int Rectangle::getX1(){return x1;}
int Rectangle::getX2(){return x2;}
int Rectangle::getY1(){return y1;}
int Rectangle::getY2(){return y2;}

void Rectangle::Area(){
    int myArea = (abs(x2-x1) * abs(y2-y1));
    this->area = myArea;
    
   // return area;
    
}
void Rectangle::Perimeter(){
    
   
}




//Operator Overloads
Rectangle Rectangle::operator+(const Rectangle &rect)
{
    int yTop, xRight;
    int yBot, xLeft;
    
    //Gets the hightest Y Value and X value.
    yTop = (this->y2 > rect.y2) ? this->y2 : rect.y2;
    xRight = (rect.x2 > this->x2) ? rect.x2 : this->x2;
    
    //Gets the Lowerst Y value and X value.
    yBot = ((this->y1<rect.y1)? this->y1: rect.y1);
    xLeft =((this->x1<rect.x1)? this->x1: rect.x1);
    
    return Rectangle(xLeft,yBot,xRight,yTop,"Added Rectangle");
}

Rectangle operator-(const Rectangle &rect1, const Rectangle &rect2)
{
    /*
     -First need to find out which case are the rectangles at
     -There are 4 cases
     -Case 1: Rectangle 1 is ontop of Rectangle 2 and Rectangle 2 is on the right
     -Case 2: Rectanlge 2 is ontop of Rectangle 1 but Rectangle 2 is still on the right
     -Case 3: Rectanlge 2 is ontop of Rectangle 1 but Rectangle 1 is now on the right.
     -Case 4: Rectangles 1 is ontop of Rectangle 2 but Rectangle 1 is still on the right
     -Case 5: Both Rectangles do not overlap therefore all points are set to (0,0)
     
     
     
     
     */
    int checkTop, checkRight;
     checkTop = (rect1.y2 > rect2.y2) ? rect1.y2 : rect2.y2;
    checkRight = (rect1.x2> rect2.x2)? rect1.x2 :rect2.x2;
        
    int test = 0;
    int xRight,xLeft,yTop,yBot;
    
    //Check to see what rectangle is on top and to the furest right.
    if(checkTop == rect1.y2 && checkRight == rect2.x2)
        test = 1;
    if(checkTop == rect2.y2 && checkRight == rect2.x2)
        test = 2;
    if(checkTop == rect2.y2 && checkRight == rect1.x2)
        test = 3;
    if(checkTop == rect1.y2 && checkRight == rect1.x2)
        test = 4;
    if(rect1.x1 > rect2.x2 || rect1.x2 < rect2.x1 || rect1.y1 < rect2.y2 || rect1.y2 > rect2.y1)
    {
        return Rectangle(0,0,0,0,"No OverLap");
    }
        
    switch(test)
    {
        case 1:
            xLeft = rect1.x1;
            xRight = rect2.x2;
            yBot = rect1.y1;
            yTop = rect2.y2;
            return Rectangle(xLeft,yBot,xRight,yTop,"Subtratced rectangle");
            
        case 2:
            xLeft = rect2.x1;
            xRight = rect1.x2;
            yBot = rect2.y1;
            yTop = rect1.y2;
            return Rectangle(xLeft,yBot,xRight,yTop,"Subtratced rectangle");
        case 3:
            xRight = rect2.x2;
            xLeft = rect1.x1;
            yBot = rect2.y1;
            yTop = rect1.y2;
             return Rectangle(xLeft,yBot,xRight,yTop,"Subtratced rectangle");
        case 4:
            xRight = rect2.x2;
            xLeft = rect1.x1;
            yBot = rect1.y1;
            yTop = rect2.y2;
             return Rectangle(xLeft,yBot,xRight,yTop,"Subtratced rectangle");
            
    }
   
    return Rectangle();
  
}


std::ostream & operator << (std::ostream &out, const Rectangle &a)
{
    
    out <<a.name<<"'s four corners are at ("<<a.x1<<","<<a.y1<<") ,("<<a.x1<<','<<a.y2<<
    "), ("<<a.x2<<','<<a.y2<<"), ("<<a.x2<<','<<a.y1<<")."<<'\n'<<a.name<<
    "'s area is "<<a.area<<" and perimeter is "<<a.perimeter<<std::endl;
    
    return out;
}

std::istream & operator >> (std::istream &in, Rectangle &b)
{

    std::cout<<"Please enter the name of your rectangle: ";
    in >> b.name;
    std::cout<<"\nPlease enter the first x point: ";
    in >>b.x1;
    std::cout<<"\nPlease enter the first y point: ";
    in >> b.y1;
    std::cout<<"\nPlease enter the second x point: ";
    in >> b.x2;
    
    //Input Validation, cannot allow user to enter same value.
    if(b.x1 == b.x2)
    {
        while(b.x1 == b.x2)
        {
            std::cout<<"You already enter that value please try another one."<<std::endl;
            in>>b.x2;
        }
    }
    
    std::cout<<"\nPlease enter the second y point: ";
    in >> b.y2;
    
    if(b.y1 == b.y2)
    {
        while(b.y1 ==b.y2)
        {
            std::cout<<"You already enter that value please try another one."<<std::endl;
            in>>b.y2;
        }
    }
    
    return in;
}


