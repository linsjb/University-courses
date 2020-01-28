#include "number_manager.h"
#include "Alg_search.h"

// #include <chrono>
// #include <ctime>
// #include <cmath>
// #include <time.h>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iomanip>
#include<iostream>
#include <fstream>

double standard_deviation(std::vector<double>time_elapsed) {
	double sum = 0.0, mean, standard_deviation = 0.0;
	for (int i = 0; i < time_elapsed.size(); i++) {
		sum += time_elapsed[i];
	}
	mean = sum / time_elapsed.size();
	for (int i = 0; i < time_elapsed.size(); ++i) {
		standard_deviation += pow(time_elapsed[i] - mean, 2);
	}
	double stdev = sqrt(standard_deviation / (time_elapsed.size() - 1));
	return stdev;
}

void write_to_file(std::vector<std::vector<double>> file_vector, std::string filename, int n_size, int samples) {
	std::fstream output;
	output.open("data_files/" + filename, std::fstream::out);

	if(output.is_open()) {
		for (size_t i = 0; i < file_vector[0].size(); i++) {
			for (size_t j = 0; j < file_vector.size(); j++) {
				output << file_vector[j][i] << ", ";
			}
			output << '\n';
		}
	}

	output.close();
}

void print_results(std::vector<double>search_result, int samples, std::vector<int> N, std::string type, std::string filename ="untitled.txt") {
	std::cout << "---------------------------------" << '\n';

	std::vector<std::vector<double>> file_vector(N.size());
	std::cout << type << "\n\n ";

	for (size_t i = 0; i < N.size(); i++) {
		double n_mean = 0;
		std::vector<double> devia_vec(samples);
		for (size_t j = 0; j < samples; j++) {
			devia_vec[j] = search_result[j + samples*i];

			n_mean += search_result[j + samples*i];
			// std::cout << "Dev: " << devia_vec[j] << '\n'; // NOTE Dev printout
		}

		file_vector[i].push_back(N[i]);
		file_vector[i].push_back(n_mean/samples);
		file_vector[i].push_back(standard_deviation(devia_vec));
		file_vector[i].push_back(samples);


		std::cout << "N\t\t" 				<<  N[i] << '\n';
		std::cout << "T[µs]\t\t" 		<< n_mean/samples << '\n';
		std::cout << "Stdev[µs]\t" 	<< standard_deviation(devia_vec) << '\n';
		std::cout << "Samples\t\t" 	<< samples << '\n';
		std::cout << '\n';
	}

	std::cout << "\n---------------------------------" << '\n';

	write_to_file(file_vector, filename, N.size(), samples);
}

int main() {
	srand(time(NULL));
	std::vector<int> N = {2000, 4000, 6000, 8000, 10000, 12000, 14000, 16000, 18000, 20000};
	int samples = 10;
	int data_size = 224737;

	Alg_search alg_search(N);
	alg_search.set_samples(samples);

	alg_search.set_data(prime_number_generator(data_size));
	alg_search.set_info_print(false);


	int searching_choice;
	std::cout << "Choose any of the following algorithms to search for a number in a container:\n";
	std::cout << "1.Linear search\n2.Binary search\n3.Binary search tree\n4.Hash table\n";
	std::cin >> searching_choice;

	switch (searching_choice) {
		//Linear search
	case 1:
		print_results(alg_search.alg_linear_search(), samples, N, "Linear search", "linear_search.txt");
		break;

	//Binary search
	case 2:
		print_results(alg_search.alg_binary_search(), samples, N, "Binary search", "binary_search.txt");
		break;

	// BST
	case 3:
		print_results(alg_search.alg_bst(), samples, N, "BST", "binary_search_tree.txt");
		break;

	// Hash table
	case 4:
		print_results(alg_search.alg_hash_table(), samples, N, "Hash table", "hash_table.txt");
		break;

	default:
		std::cout << "Wrong choice" << "\n";
		break;
	}

	return 0;
}
