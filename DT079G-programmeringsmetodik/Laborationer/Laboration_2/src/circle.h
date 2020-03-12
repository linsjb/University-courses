/*
Filename: circle.h
Created by Linus Sjöbro on 2017-12-14.
*/

#include <string>
#include "shape.h"

#ifndef circle_h
#define circle_h

class Circle:public Shape {
public:
    Circle(double setRadius, std::string setColour);
    Circle(double setRadius);

    double getArea();
    double getRadius();

    ~Circle();

private:
  double radius;
};

#endif
