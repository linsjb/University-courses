/*
Filename: int_sorted.h
Created by Linus Sjöbro on 2017-12-01.
*/

#ifndef int_sorted_h
#define int_sorted_h

#include <cstdlib>
#include "int_buffer.h"

class int_sorted {
public:
  int_sorted(size_t size);

  int_sorted(const int* source , size_t size);
  size_t size() const;
  int* insert(int value); // returns the insertion point.
  int_sorted merge(const int_sorted& mergeWith) const;
  int_sorted sort(const int* begin, const int* end);

  const int* begin() const;
  const int* end() const;

  int& operator [] (size_t index);
  int operator [] (size_t index) const;

private:
  int_buffer buffer;
};

#endif
