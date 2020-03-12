/*
Filename: int_buffer.cpp
Created by Linus Sjöbro on 2017-11-25.
*/

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "int_buffer.h"

int_buffer::int_buffer (const size_t size):
bufferSize(size), buffer(new int[size]) {}

int_buffer::int_buffer (const int* source , size_t size):
bufferSize(size), buffer(new int[size]) {
  std::copy(source, source+size, buffer);
}

// Move ctor
int_buffer::int_buffer (int_buffer&& rhs):
bufferSize(0), buffer(nullptr){
  std::swap(rhs.buffer, buffer);
  std::swap(rhs.bufferSize, bufferSize);
}

// move assign
int_buffer& int_buffer::operator = (int_buffer&& rhs) {
  std::swap(rhs.buffer, buffer);
  std::swap(rhs.bufferSize, bufferSize);
  return *this;
}

// copy ctor
int_buffer::int_buffer (const int_buffer& rhs):
bufferSize(rhs.size()), buffer(new int[rhs.bufferSize]) {
  std::copy(rhs.begin(), rhs.end(), begin());
}

// copy assign
int_buffer& int_buffer::operator = (const int_buffer& rhs) {
  int_buffer temp(rhs);
  std::swap(temp.buffer, buffer);
  std::swap(temp.bufferSize, bufferSize);
  return *this;
}

int& int_buffer::operator [] (size_t index) {
  return buffer[index];
}

int int_buffer::operator [] (size_t index) const {
  return buffer[index];
}

size_t int_buffer::size() const {
  return bufferSize;
}

int* int_buffer::begin () {
  return buffer;
}

int* int_buffer::end () {
  return buffer + bufferSize;
}

const int* int_buffer::begin () const {
  return buffer;
}

const int* int_buffer::end () const {
  return buffer + bufferSize;
}

int_buffer::~int_buffer() {
  delete [] buffer;
}
