#include <cmath>
#include <fstream>

#include "Sorting.h"
#include "data_generation.h"

double standard_deviation(std::vector<double> time_elapsed) {
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

void write_to_file(std::vector<std::vector<double>> file_vector,
                   std::string filename, int n_size, int samples) {
    std::fstream output;
    output.open("data_files/" + filename, std::fstream::out);

    if (output.is_open()) {
        for (size_t i = 0; i < file_vector[0].size(); i++) {
            for (size_t j = 0; j < file_vector.size(); j++) {
                output << file_vector[j][i];
                if(j != file_vector.size() -1) {
                output << ", ";
                }
            }
            output << '\n';
        }
    }

    output.close();
}

void print_results(std::vector<double> sorting_result, int samples,
                   std::vector<int> N, std::string type,
                   std::string filename = "untitled.csv") {
    std::cout << "---------------------------------" << '\n';

    std::vector<std::vector<double>> file_vector(N.size());
    std::cout << type << "\n\n";

    for (size_t i = 0; i < N.size(); i++) {
        double n_mean = 0;
        std::vector<double> devia_vec(samples);
        for (size_t j = 0; j < samples; j++) {
            devia_vec[j] = sorting_result[j + samples * i];

            n_mean += sorting_result[j + samples * i];
            // std::cout << "Dev: " << devia_vec[j] << '\n'; // NOTE Dev
            // printout
        }

        file_vector[i].push_back(N[i]);
        file_vector[i].push_back(n_mean / samples);
        file_vector[i].push_back(standard_deviation(devia_vec));
        file_vector[i].push_back(samples);

        std::cout << "N\t\t" << N[i] << '\n';
        std::cout << "T[ms]\t\t" << n_mean / samples << '\n';
        std::cout << "Stdev[ms]\t" << standard_deviation(devia_vec) << '\n';
        std::cout << "Samples\t\t" << samples << '\n';
        std::cout << '\n';
    }

    std::cout << "\n---------------------------------" << '\n';

    write_to_file(file_vector, filename, N.size(), samples);
}

int main() {
    srand(time(NULL));

    std::vector<int> N = {2000,  4000,  8000,  10000, 11000};
    int data_size = 30000;
    int samples = 3;

    Sorting sorting(N);
    sorting.set_samples(samples);

    Data_generation data;

    std::vector<int> data_to_sort;
    int choose_data_type;

    std::string data_filename = "";

    std::cout << "Choose any of the following number container:\n";
    std::cout << "1.Ascending numbers.\n2.Descending numbers.\n3.Constant "
                 "numbers.\n4.Random numbers.\n";
    std::cin >> choose_data_type;

    switch (choose_data_type) {
        case 1:
            data_to_sort = data.ascending_values(data_size);
            data_filename = "ascending_";
            break;

        case 2:
            data_to_sort = data.descending_values(data_size);
            data_filename = "descending_";
            break;

        case 3:
            data_to_sort = data.constant_values(data_size);
            data_filename = "constant_";
            break;

        default:
            data_to_sort = data.random_values(data_size);
            data_filename = "random_";
            break;
    }

    sorting.set_data(data_to_sort);

    int sorting_choice;
    std::cout << "Choose any of the following algorithms to sort the number "
                 "container:\n";
    std::cout << "1.Selection sort.\n2.Insertion sort.\n3.Quick sort.\n4.Quick "
                 "sort(median of three).\n5.Standard sort(std::sort)\n6.All\n";
    std::cin >> sorting_choice;

    switch (sorting_choice) {
        // Selection sort
        case 1:
            print_results(sorting.alg_selection_sort(), samples, N,
                          "Selection sort",
                          data_filename + "selection_sort.csv");
            break;

        // Insertion sort
        case 2:
            print_results(sorting.alg_insertion_sort(), samples, N,
                          "Insertion sort",
                          data_filename + "insertion_sort.csv");
            break;

        // Quick sort with partition
        case 3:
            print_results(sorting.alg_quick_partition_sort(), samples, N,
                          "Quick sort with partition",
                          data_filename + "quick_partition_sort.csv");
            break;

        // Quick sort with MEDIAN OF THREE.
        case 4:
            print_results(sorting.alg_quick_median_sort(), samples, N,
                          "Quick sort with median of three",
                          data_filename + "quick_par3.csv");
            break;

        case 5:
            print_results(sorting.alg_std_sort(), samples, N, "Std sort",
                          data_filename + "std_sort.csv");
            break;

        case 6:
            print_results(sorting.alg_selection_sort(), samples, N,
                          "Selection sort",
                          data_filename + "selection_sort.csv");
            print_results(sorting.alg_insertion_sort(), samples, N,
                          "Insertion sort",
                          data_filename + "insertion_sort.csv");
            print_results(sorting.alg_quick_partition_sort(), samples, N,
                          "Quick sort with partition",
                          data_filename + "quick_partition.csv");
            print_results(sorting.alg_quick_median_sort(), samples, N,
                          "Quick sort with median of three",
                          data_filename + "quick_par3.csv");
            print_results(sorting.alg_std_sort(), samples, N, "Std sort",
                          data_filename + "std_sort.csv");

            break;

        default:
            std::cout << "Wrong choice" << '\n';
            break;
    }
    return 0;
}
