/*
Filename: shape.cpp
Created by Linus Sjöbro on 2017-12-11.
*/

#include <iostream>
#include <string>

#include "shape.h"

Shape::Shape(){}
Shape::Shape(std::string setColour):
colour(setColour){}

std::string Shape::getColour() {
  return colour;
}
