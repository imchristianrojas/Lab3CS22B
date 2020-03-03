//
//  rectangle.h
//  CS22BLab3Mac
//
//  Created by Christian on 2/25/20.
//  Copyright © 2020 Christian Rojas. All rights reserved.
//
#include <iostream>
#include <string>
#include <cmath>

#ifndef rectangle_h
#define rectangle_h

class Rectangle{
    
private:
    int x1,x2,y1,y2;
    
    int area;
    int perimeter;
    std::string name;
public:
    Rectangle();
    Rectangle(int,int,int,int,std::string);
    ~Rectangle();
    
    
    void Area();
    void Perimeter();
    
    int getX1();
    int getX2();
    int getY1();
    int getY2();
    std::string getName();
    
    
    void setX1(int);
    void setX2(int);
    void setY1(int);
    void setY2(int);
    void setName(std::string);
    
    
    //Overloading Operators
    Rectangle operator+(const Rectangle &aNum);
    friend Rectangle operator-(const Rectangle &rect1, const Rectangle &rect2);
    friend std::ostream & operator << (std::ostream &out, const Rectangle &a);
    friend std::istream & operator >> (std::istream &in, Rectangle &b);
    
};




#endif /* rectangle_h */
