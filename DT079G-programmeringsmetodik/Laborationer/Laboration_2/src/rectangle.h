/*
Filename: rectangle.h
Created by Linus Sjöbro on 2017-12-11.
*/

#include <string>
#include "shape.h"

#ifndef rectangle_h
#define rectangle_h

class Rectangle:public Shape {
public:
    Rectangle(double setWidth, double setHeight);
    Rectangle(double setWidth, double setHeight, std::string setColour);
    double getArea();
    double getWidth();
    double getHeight();

    ~Rectangle();

private:
  double width;
  double height;
};

#endif
