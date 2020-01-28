/*
Filename: shape.h
Created by Linus Sjöbro on 2017-12-11.
*/

#ifndef shape_h
#define shape_h

#include <cmath>
#include <string>
#include <iostream>
#define _USE_MATH_DEFINES

class Shape {
public:
    Shape();
    Shape(std::string setColour);

    virtual double getArea() = 0;
    std::string getColour();

    virtual ~Shape(){};

private:
  std::string colour;
};

#endif
