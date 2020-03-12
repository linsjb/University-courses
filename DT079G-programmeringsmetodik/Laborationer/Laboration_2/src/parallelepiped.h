/*
Filename: parallelepiped.h
Created by Linus Sjöbro on 2017-12-14.
*/
#include <string>

#include "rectangle.h"

#ifndef parallelepiped_h
#define parallelepiped_h

class Parallelepiped:public Rectangle {
public:
    Parallelepiped(double setHeight, double setWidth, double setLength);
    Parallelepiped(double setHeight, double setWidth, double setLength, std::string setColour);

    double getArea();
    ~Parallelepiped();

private:
  double length;
};

#endif
