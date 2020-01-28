#ifndef Sorting_h
#define Sorting_h

#include <stdio.h>
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <time.h>

class Sorting {
private:
  std::vector<int> number_of_elements;
  std::vector <int> data;

  std::vector<double> result;
  std::vector<double> data_to_sort;

  int samples;

public:
    Sorting(std::vector<int> elems);

    void set_samples(int samp);

    void set_data(std::vector <int> setData);
    bool check_sorted(std::vector<double> sorted);

    std::vector<double> alg_selection_sort();
    std::vector<double> alg_insertion_sort();
    std::vector<double> alg_quick_partition_sort();
    std::vector<double> alg_quick_median_sort();
    std::vector<double> alg_std_sort();
};

#endif
