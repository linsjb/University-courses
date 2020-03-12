/*
Filename: rectangle.cpp
Created by Linus Sjöbro on 2017-12-11.
*/

#include <iostream>
#include <string>

#include "rectangle.h"

Rectangle::Rectangle(double setWidth, double setHeight):
width(setWidth), height(setHeight){}

Rectangle::Rectangle(double setWidth, double setHeight, std::string setColour):
  Shape(setColour), width(setWidth), height(setHeight){}

double Rectangle::getArea() {
  return width * height;
}

double Rectangle::getWidth() {
  return width;
}

double Rectangle::getHeight() {
  return height;
}

Rectangle::~Rectangle() {}
