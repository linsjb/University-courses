#pragma once
#include <vector>

std::vector<int> prime_number_generator(int size) {
	std::vector<int> prime_container;
		for (int i = 2;; i++) {
			bool prime = true;
			for (int j = 2; j*j <= i; j++) {
				if (i % j == 0) {
					prime = false;
					break;
				}
			}
			if (prime) {
				prime_container.push_back(i);
			}
			if (size == prime_container.size())
				break;
		}
	return prime_container;
}
