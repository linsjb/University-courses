#pragma once
#include <algorithm>
#include <iostream>


template<typename IT>
void linear_search(IT begin ,IT end, int searched_element) {
	while(begin != end) {
		if (*begin == searched_element) {
			// std::cout << searched_element << " exist" << "\n"; // NOTE Print control
			return;
		}
		begin++;
	}
	// std::cout << searched_element << " does not exist" << "\n"; // NOTE print control
}

template<typename IT>
void binary_search(IT begin, IT end, int searched_element) {
	auto mid = ((end - begin) / 2) + begin;
	end = end - 1;
	std::sort(begin, end);
	if (*mid == searched_element) {
		// std::cout << "\n" << searched_element << " exist" << "\n"; // NOTE print control
		return;
	}
	if (*begin == *mid || *end == *mid) {
		// std::cout << searched_element << " does not exist" << "\n"; // NOTE print control
		return;
	}

	if (*mid > searched_element) {
		binary_search(begin, mid, searched_element);
	}
	if (*mid < searched_element) {
		binary_search(mid, end, searched_element);
	}
	return;
}
