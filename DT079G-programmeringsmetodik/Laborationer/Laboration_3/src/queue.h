/*
Filename: queue.h
Created by Linus Sjöbro on 2017-12-18.
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

#ifndef queue_h
#define queue_h

template<typename T>
class Queue {
public:
    Queue();

    void push(T e);
    int size();
    void pop();
    bool empty();
    T first();

private:
  std::vector<T> queue;

  struct less {
    bool operator()(T a, T b) {
      return a.priority < b.priority;
    }
  };
};


template<typename T>
Queue<T>::Queue(){}


template<typename T>
void Queue<T>::push(T e) {
  if(queue.size() < 1 ) {
    queue.push_back(e);
  } else {
    queue.push_back(e);
    std::sort(queue.begin(), queue.end(), less());
  }
}


template<typename T>
int Queue<T>::size() {
  return queue.size();
}


template<typename T>
void Queue<T>::pop() {
  if(queue.empty()) {

  } else {
    queue.erase(queue.begin());
  }
}


template<typename T>
bool Queue<T>::empty() {
  return queue.empty();
}

template<typename T>
T Queue<T>::first() {
  return queue.front();
}

#endif
