/*
Filename: parallelepiped.cpp
Created by Linus Sjöbro on 2017-12-14.
*/

#include <string>
#include "parallelepiped.h"

Parallelepiped::Parallelepiped(double setHeight, double setWidth, double setLength):
Rectangle(setWidth, setHeight), length(setLength){}

Parallelepiped::Parallelepiped(double setHeight, double setWidth, double setLength, std::string setColour):
Rectangle(setWidth, setHeight, setColour), length(setLength){}

double Parallelepiped::getArea() {
  return 2* (Rectangle::getArea() + (length * Rectangle::getWidth()) + (length * Rectangle::getHeight()));
}

Parallelepiped::~Parallelepiped() {}
