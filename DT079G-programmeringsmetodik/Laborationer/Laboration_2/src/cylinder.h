/*
Filename: cylinder.h
Created by Linus Sjöbro on 2017-12-14.
*/

#include "circle.h"

#ifndef cylinder_h
#define cylinder_h

class Cylinder:public Circle {
public:
    Cylinder(double setRadius, double setHeight);
    Cylinder(double setRadius, double setHeight, std::string setColour);

    double getArea();
    
    ~Cylinder();

private:
  double height;
};

#endif
