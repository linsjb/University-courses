#ifndef CREATED_SORTS_H
#define CREATED_SORTS_H
#include <time.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

template <typename IT>
void selection_sort(IT begin, IT end) {
    auto N = end - begin;
    while (begin != end) {
        // find min
        auto min = begin;
        for (auto iterator = begin; iterator != end; iterator++) {
            if (*iterator < *min) {
                min = iterator;
            }
        }
        std::swap(*min, *begin);
        ++begin;
    }
}

// Rotate elements.
template <typename IT>
void rotate(IT begin, IT end) {
    if (begin == end) {
        return;
    }
    if (begin == end - 1) {
        return;
    }
    auto first = *(end - 1);
    auto iterator = end - 1;
    for (; iterator != begin; iterator--) {
        if (first >= *(iterator - 1)) {
            break;
        }
        *iterator = *(iterator - 1);
    }
    *iterator = first;
}

template <typename IT>
IT partition(IT begin, IT end) {
    auto pivot = end - 1;
    auto partition_index = begin;
    for (auto iterator = begin; iterator < end; ++iterator) {
        if (iterator < pivot) {
            if (*iterator < *pivot) {
                std::swap(*iterator, *partition_index);
                partition_index++;
            }
        }
    }
    std::swap(*partition_index, *pivot);

    return partition_index;
}

// Insertion sort using rotate.
template <typename IT>
void insertion_sort(IT begin, IT end) {
    for (auto iterator = begin; iterator + 1 != end; iterator++) {
        if (*iterator > *(iterator + 1)) {
            rotate(begin, iterator + 2);
        }
    }
}

template <typename IT>
void quick_sort(IT begin, IT end) {
    if (begin < end) {
        IT partition_index = partition(begin, end);
        quick_sort(begin, partition_index);
        quick_sort(partition_index + 1, end);
    }
}

template <typename IT>
IT median_of_three_partition(IT begin, IT end) {
    auto left_element = begin;
    auto right_element = end - 1;
    auto middle_element = ((end - begin) / 2) + begin;
    auto median = std::max(
        std::min(*left_element, *middle_element),
        std::min(std::max(*left_element, *right_element), *middle_element));

    if (median == *left_element) {
        std::swap(*left_element, *right_element);
    }
    if (median == *middle_element) {
        std::swap(*middle_element, *right_element);
    }

    auto pivot = end - 1;
    auto partition_index = begin;
    for (auto iterator = begin; iterator < end; ++iterator) {
        if (iterator < pivot) {
            if (*iterator < *pivot) {
                std::swap(*iterator, *partition_index);
                partition_index++;
            }
        }
    }
    std::swap(*partition_index, *pivot);
    return partition_index;
}

template <typename IT>
void quick_sort_median(IT begin, IT end) {
    if (begin < end) {
        IT partition_index = median_of_three_partition(begin, end);
        quick_sort(begin, partition_index);
        quick_sort(partition_index + 1, end);
    }
}

#endif
