/*
Filename: house.h
Created by Linus Sjöbro on 2017-12-28.
*/

#ifndef house_h
#define house_h

#include <stdio.h>

class house {
public:
  int getRoof() {return roofSize;}
  int getFloor() {return floorSize;}

private:
  int roofSize;
  int floorSize;

friend void door(house &h);
};

#endif
