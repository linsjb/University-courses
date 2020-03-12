/*
Filename: roundedRectangle.h
Created by Linus Sjöbro on 2017-12-14.
*/

#include "rectangle.h"

#ifndef roundedRectangle_h
#define roundedRectangle_h

class RoundedRectangle:public Rectangle {
public:
    RoundedRectangle(double setWidth, double setHeight, double setCorner);
    RoundedRectangle(double setWidth, double setHeight, double setCorner, std::string setColour);

    double getArea();

    ~RoundedRectangle();

private:
  double corner;
};

#endif
