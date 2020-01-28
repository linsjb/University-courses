/*
Filename: main.cpp
Created by Linus Sjöbro on 2017-11-25.
*/

#include <iostream>
#include <array>
#include <algorithm>

#include "int_buffer.h"
#include "int_sorted.h"

void f(int_buffer buf) {
  static int j = 0;
  for (int* i = buf.begin(); i != buf.end(); i++) {
    j++;
    buf[j-1] = j;
  }

  j = 0;
  for (const int* i = buf.begin(); i != buf.end(); i++) {
    std::cout << buf[j] << ", ";
    j++;
  }
}

int_buffer generateRandom (size_t size) {
  int_buffer buffer(size);
  for (int& e : buffer) {
    e = std::rand();
  }

  return buffer;
}


void selectionSort(int_buffer& buffer) {
  for(int i = 0; i < buffer.size()-1; i++) {
    for(int j = i + 1; j < buffer.size(); j++) {
      if(buffer[j] < buffer[i]) {
        std::swap(buffer[j], buffer[i]);
      }
    }
  }
}

int main() {
  srand (time(NULL));
  int_buffer buffer = generateRandom(400000);
  // int_sorted sorted (buffer.begin(), buffer.size());
  std::sort(buffer.begin(), buffer.end());
  // selectionSort(buffer);

  return 0;
}
