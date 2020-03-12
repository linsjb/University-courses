#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include<iostream>

//Hash function that return a modulus of indata!
size_t hash(size_t index, const std::vector<int>& primary_no_container) {
	size_t container_size = primary_no_container.size();
	size_t hash_value = 0;
	hash_value = primary_no_container[index] % container_size;
	return hash_value;
}

std::vector<std::vector<int>> insert_hash(std::vector<std::vector<int>>hash_table, std::vector<int> primary_no_container) {
	std::vector<int>v = primary_no_container;
	//
	//Clear table!
	for (size_t i = 0; i < hash_table.size(); i++){
		hash_table[i].clear();
	}
	for (int i = 0; i < v.size(); i++) {
		int hash_value = hash(i, v); // Modolus
		int real_value = v[i];

		hash_table[hash_value].push_back(real_value);
	}
	//
	//Print table!
	// for (unsigned int i = 0; i < hash_table.size(); i++){ // NOTE print control
	// 	for (unsigned int j = 0; j < hash_table[i].size(); j++){
	// 		// std::cout << "hash table\t[" << i << "]-" << "[" << j << "]:\t" << hash_table[i][j] << '\n';
	// 	}
	// }
	// std::cout << "\nDone inserting!\n" << std::endl;  // NOTE print control
	return hash_table;
}

bool search_hash(std::vector<int> primary_no_container, std::vector<std::vector<int>>hash_table, int element_to_find) {
	int max_value = primary_no_container.back();

	//While element exists in the number container.
	// std::cout << element_to_find << " & " << max_value << std::endl; // NOTE print control
	if (element_to_find <= max_value) {
		int index = element_to_find % hash_table.size();

		// std::cout <<"element_to_find:" <<element_to_find << std::endl; // NOTE print control

		// std::cout <<"hash_table.size():"<< hash_table.size() << std::endl; // NOTE print control

		// std::cout << "Index: "<< index << "\n"; // NOTE print control

		std::vector<int>::iterator iterator = std::find((hash_table[index].begin()), (hash_table[index].end()), element_to_find);
		//std::cout << "star iterator "<< *iterator << std::endl;
		if (iterator != (hash_table[index].end())) {
			// std::cout << "Element exists in the array!" << "\n"; // NOTE print control
			return true;
		}
		// std::cout << "Element does not exists in the array!" << "\n"; // NOTE print control
		return false;
	}
	else {
		// std::cout << "Element does not exists in the array!" << "\n"; // NOTE print control
		return false;
	}

}
