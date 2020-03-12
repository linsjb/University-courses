/*
Filename: circle.cpp
Created by Linus Sjöbro on 2017-12-14.
*/

#include <string>
#include "circle.h"

Circle::Circle(double setRadius):
radius(setRadius){}

Circle::Circle(double setRadius, std::string setColour):
Shape(setColour), radius(setRadius){}

 double Circle::getArea() {
  return radius * radius * M_PI;
}

double Circle::getRadius() {
  return radius;
}

Circle::~Circle() {}
