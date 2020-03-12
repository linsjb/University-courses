/*
Filename: int_sorted.cpp
Created by Linus Sjöbro on 2017-12-01.
*/

#include <iostream>
#include "int_sorted.h"
#include "int_buffer.h"

int_sorted::int_sorted (const int* source , size_t size):
 buffer(int_buffer(source, size)) {
   if(size > 1) {
     auto sortedBuffer = sort(buffer.begin(), buffer.end());
     std::copy(sortedBuffer.begin(), sortedBuffer.end(), buffer.begin());
   }
 }


 int_sorted::int_sorted(size_t size):
 buffer(size) {}


size_t int_sorted::size() const {return buffer.size();}


int* int_sorted::insert (int value) {
  int_buffer temp(buffer.size()+1);
  std::fill(temp.begin(), temp.end(), 0); // Fill the temp with zeroes

  int insertIndex = 0; // Which index in temp are we going to insert our value in?

  auto copyPredicate = [value](int elementData){if(elementData < value) return true; return false;};
  std::copy_if(buffer.begin(), buffer.end(), temp.begin(), copyPredicate);

  if(value > buffer[0]) {
    for(int i = 0; i < buffer.size(); i++) {
      if(buffer[i] == temp[i]) {
        insertIndex++;
      }
    }
  }

  temp[insertIndex] = value;

  // Copy the rest of the element's from buffer to temp
  std::copy(buffer.begin()+insertIndex, buffer.end(), temp.begin()+insertIndex+1);

  buffer = temp;

  return buffer.begin();
}


int_sorted int_sorted::merge(const int_sorted& mergeWith) const {
  int_buffer temp(buffer.size() + mergeWith.size());

  int tempStep = 0;
  int bufferStep = 0;
  int mergeStep = 0;
  int a = 0;
  int b = 0;

  while (!(bufferStep == buffer.size()) && !(mergeStep == mergeWith.size())) {
    a = buffer[bufferStep];
    b = mergeWith[mergeStep];

    if(a < b) {
      bufferStep++;
      temp[tempStep] = a;
    } else {
      mergeStep++;
      temp[tempStep] = b;
    }
    tempStep++;
  }

  while (!(bufferStep == buffer.size())) {
    a = buffer[bufferStep];
    temp[tempStep] = a;
    bufferStep++;
    tempStep++;
  }

  while (!(mergeStep == mergeWith.size())) {
    b = mergeWith[mergeStep];
    temp[tempStep] = b;
    mergeStep++;
    tempStep++;
  }

  int_sorted merged(0);
  merged.buffer = temp;

  return merged;
}


int_sorted int_sorted::sort(const int* begin , const int* end) {
  if (begin == end) return int_sorted(0);
  if (begin == end -1) return int_sorted (begin , 1);
  ptrdiff_t half = (end - begin)/2; //pointer diff type
  const int* mid = begin + half ;
  return sort (begin , mid). merge(sort(mid , end));
}


const int* int_sorted::begin() const {return buffer.begin();}
const int* int_sorted::end() const {return buffer.end();}


int& int_sorted::operator[] (size_t index) {return buffer[index];}
int int_sorted::operator[] (size_t index) const {return buffer[index];}
