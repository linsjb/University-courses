#include "Alg_search.h"
#include "BST_node.h"
#include "hash_table.h"
#include "search_algorithms.h"

Alg_search::Alg_search(std::vector<int>elems)  {
  number_of_elements = elems;
}

void Alg_search::set_samples(int setSamples) {
  samples = setSamples;
}

void Alg_search::set_data(std::vector<int> setData) {
  data = setData;
}

int Alg_search::numbers_to_find() {
  int max_data_value = *std::max_element(data_to_search.begin(), data_to_search.end());
  return rand()%max_data_value;
}

std::vector<double> Alg_search::alg_linear_search() {
  for (int index = 0; index < number_of_elements.size(); index++) {
    data_to_search.clear();
    data_to_search.resize(number_of_elements[index]);

    std::copy(data.begin(), (data.begin() + number_of_elements[index]), data_to_search.begin());

    for (int i = 0; i != samples; i++) {
      std::vector<int> elements = data;
      int number_to_find = numbers_to_find();

      auto start_lin = std::chrono::high_resolution_clock::now();
      linear_search(data_to_search.begin(), data_to_search.end(), number_to_find);
      auto end_lin = std::chrono::high_resolution_clock::now();

      auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_lin - start_lin).count();

      result.push_back(elapsed_microseconds);
    }
  }
  return result;
}

std::vector<double> Alg_search::alg_binary_search() {
  for (int index = 0; index < number_of_elements.size(); index++) {
    data_to_search.clear();
    data_to_search.resize(number_of_elements[index]);

    std::copy(data.begin(), (data.begin() + number_of_elements[index]), data_to_search.begin());
    std::sort(data_to_search.begin(), data_to_search.end());

    for (int i = 0; i != samples; i++) {
      int number_to_find = numbers_to_find();

      auto start_bin = std::chrono::high_resolution_clock::now();
      binary_search(data_to_search.begin(), data_to_search.end(), number_to_find);
      auto end_bin = std::chrono::high_resolution_clock::now();

      auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_bin - start_bin).count();
      result.push_back(elapsed_microseconds);
    }
  }

  return result;
}

std::vector<double> Alg_search::alg_bst() {
  for (int index = 0; index < number_of_elements.size(); index++) {
    data_to_search.clear();
    data_to_search.resize(number_of_elements[index]);
    std::copy(data.begin(), (data.begin() + number_of_elements[index]), data_to_search.begin());
    
    // Creating an empty BST.
    BST_node* root = NULL;

    //Insert data into the BST.
    for (int index = 0; index < data_to_search.size(); index++) {
      root = insert_BSTnode(root, data_to_search[index]);
    }

    for (int i = 0; i != samples; i++) {
      int number_to_find = numbers_to_find();

      auto start_BST = std::chrono::high_resolution_clock::now();
      search_BSTnode(root, number_to_find);
      auto end_BST = std::chrono::high_resolution_clock::now();

      auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end_BST - start_BST).count();
      result.push_back(elapsed_microseconds);
    }
  }

  return result;
}

std::vector<double> Alg_search::alg_hash_table() {
  for (int index = 0; index < number_of_elements.size(); index++) {
    data_to_search.clear();
    data_to_search.resize(number_of_elements[index]);

    std::copy(data.begin(), (data.begin() + number_of_elements[index]), data_to_search.begin());

    std::vector<std::vector<int>> hash_table;
    hash_table.resize(data_to_search.size());

    std::vector<std::vector<int>> HT = insert_hash(hash_table, data_to_search);

    for (int i = 0; i != samples; i++) {
      int number_to_find = numbers_to_find();

      auto start_HT = std::chrono::high_resolution_clock::now();
      search_hash(data_to_search, HT, number_to_find);
      auto end_HT = std::chrono::high_resolution_clock::now();

      std::chrono::microseconds elapsed_seconds_qm = std::chrono::duration_cast<std::chrono::microseconds>(end_HT - start_HT);
      int elapsed_microseconds = (int)elapsed_seconds_qm.count();

      result.push_back(elapsed_microseconds);
    }
  }

  return result;
}
