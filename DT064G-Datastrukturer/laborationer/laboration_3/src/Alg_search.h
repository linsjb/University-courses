#ifndef Alg_search_h
#define Alg_search_h

#include <stdio.h>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include<iostream>
#include <iostream>
#include <vector>
#include <chrono>
#include <ctime>
#include <cmath>
#include <time.h>

class Alg_search {
private:
  std::vector<int> data;
  std::vector<int> data_to_search;
  std::vector<int> number_of_elements;
  std::vector<double> result;
  int samples;

public:
    Alg_search(std::vector<int>elems);

    void set_samples(int setSamples);
    void set_data(std::vector<int> setData);
    int numbers_to_find();

    std::vector<double> alg_linear_search();
    std::vector<double> alg_binary_search();
    std::vector<double> alg_bst();
    std::vector<double> alg_hash_table();
protected:

};


#endif
