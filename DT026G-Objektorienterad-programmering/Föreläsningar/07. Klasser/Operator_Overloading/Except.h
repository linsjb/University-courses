//File: Except.h

#ifndef OutOfRange_H
#define OutOfRange_H

#include <iostream>
using namespace std;

class OutOfRange {
  int minIndex,maxIndex,wrongIndex;
 public:
  OutOfRange(int mini, int maxi, int i)
   : minIndex(mini), maxIndex(maxi), wrongIndex(i) {}
  void report() {
    cout <<"The index "<<wrongIndex<<" is out of range ["
         <<minIndex<<".."<<maxIndex<<"]."<<endl; }
};

#endif