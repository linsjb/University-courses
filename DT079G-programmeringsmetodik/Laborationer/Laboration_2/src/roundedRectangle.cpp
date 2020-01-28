/*
Filename: roundedRectangle.cpp
Created by Linus Sjöbro on 2017-12-14.
*/

#include "roundedRectangle.h"

RoundedRectangle::RoundedRectangle(double setWidth, double setHeight, double setCorner):
Rectangle(setWidth, setHeight), corner(setCorner){}

RoundedRectangle::RoundedRectangle(double setWidth, double setHeight, double setCorner, std::string setColour):
Rectangle(setWidth, setHeight, setColour), corner(setCorner){}

double RoundedRectangle::getArea() {
  return Rectangle::getArea() - (2*corner*corner - M_PI*corner*corner);
}

RoundedRectangle::~RoundedRectangle() {}
