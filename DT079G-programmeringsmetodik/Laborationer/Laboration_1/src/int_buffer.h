/*
Filename: int_buffer.h
Created by Linus Sjöbro on 2017-11-25.
*/

#ifndef int_buffer_h
#define int_buffer_h

#include <cstdlib>

class int_buffer {
public:
  explicit int_buffer(const size_t size); // Constructor

  int_buffer(const int* source , size_t size);

  int_buffer(int_buffer&& rhs); // move constructor
  int_buffer& operator = (int_buffer && rhs); // move assign

  int_buffer(const int_buffer& rhs); // copy construct
  int_buffer& operator = (const int_buffer & rhs); // copy assign

  // Need these to be able to access the index of the buffer, because it's private.
  // Otherwise we will not be able to access it with the subscript operator.
  int& operator [] (size_t index);
  int operator [] (size_t index) const;

  size_t size() const;

  int* begin();
  const int* begin() const;

  int* end();
  const int* end() const;

  ~int_buffer();

private:
  size_t bufferSize;
  int* buffer;
};

#endif
