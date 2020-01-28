#include "data_generation.h"

Data_generation::Data_generation()  {}
Data_generation::~Data_generation() {}

std::vector<int> Data_generation::random_values(int max_size){
	std::vector<int> dataContainer(max_size);

	for (int i = 0; i < dataContainer.size(); i++){
		dataContainer[i] = (rand() % max_size);
	}
	
	return dataContainer;
}

//Generate ascending numbers.
std::vector<int> Data_generation::ascending_values(int max_size){
	std::vector<int> dataContainer(max_size);

	for (int i = 0; i < dataContainer.size(); i++){
		dataContainer[i] = (rand() % max_size);
	}

	std::sort(dataContainer.begin(), dataContainer.end());
	return dataContainer;
}

//
//Generate descending numbers.
std::vector<int> Data_generation::descending_values(int max_size){
	std::vector<int> dataContainer(max_size);

	for (int i = 0; i < dataContainer.size(); i++){
		dataContainer[i] = (rand() % max_size);
	}

	std::sort(dataContainer.rbegin(), dataContainer.rend());
	return dataContainer;
}

//Generate a constant value.
std::vector<int> Data_generation::constant_values(int max_size){
	std::vector<int> dataContainer(max_size, 5);

	// for (int i = 0; i < dataContainer.size(); i++){
	// 	dataContainer[i] = 5;
	// }
	return dataContainer;
}
