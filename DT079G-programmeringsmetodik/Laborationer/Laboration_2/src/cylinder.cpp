/*
Filename: cylinder.cpp
Created by Linus Sjöbro on 2017-12-14.
*/

#include "cylinder.h"

Cylinder::Cylinder(double setRadius, double setHeight):
Circle(setRadius), height(setHeight) {}

Cylinder::Cylinder(double setRadius, double setHeight, std::string setColour):
Circle(setRadius, setColour), height(setHeight){}

double Cylinder::getArea() {
  return (2*M_PI*Circle::getRadius()*height) + 2*Circle::getArea();
}

Cylinder::~Cylinder(){}
