#include "Sorting.h"

#include "created_sorts.h"

Sorting::Sorting(std::vector<int> elems) { number_of_elements = elems; }

void Sorting::set_samples(int samp) { samples = samp; }

void Sorting::set_data(std::vector<int> setData) { data = setData; }

void Sorting::check_sorted(
    std::vector<double> sorted) {  // NOTE Kanske inte behövs
    for (int i = 0; i < sorted.size() - 1; i++) {
        if (sorted[i] > sorted[i + 1]) {
            std::cout << "Not sorted" << i << '\n';
        }
    }
}

std::vector<double> Sorting::alg_selection_sort() {
    for (int index = 0; index < number_of_elements.size(); index++) {
        data_to_sort.clear();
        data_to_sort.resize(number_of_elements[index]);

        std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                  data_to_sort.begin());
        for (int i = 0; i != samples; i++) {
            auto start_sel = std::chrono::high_resolution_clock::now();
            selection_sort(data_to_sort.begin(), data_to_sort.end());
            auto end_sel = std::chrono::high_resolution_clock::now();

            check_sorted(data_to_sort);

            auto elapsed_microseconds_sel =
                std::chrono::duration_cast<std::chrono::microseconds>(end_sel -
                                                                      start_sel)
                    .count();
            result.push_back(elapsed_microseconds_sel / 1000);

            std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                      data_to_sort.begin());
        }
    }
    return result;
}

std::vector<double> Sorting::alg_insertion_sort() {
    for (int index = 0; index < number_of_elements.size(); index++) {
        data_to_sort.clear();
        data_to_sort.resize(number_of_elements[index]);

        std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                  data_to_sort.begin());

        for (int i = 0; i != samples; i++) {
            auto start_ins = std::chrono::high_resolution_clock::now();
            insertion_sort(data_to_sort.begin(), data_to_sort.end());
            auto end_ins = std::chrono::high_resolution_clock::now();

            check_sorted(data_to_sort);

            auto elapsed_microseconds_ins =
                std::chrono::duration_cast<std::chrono::microseconds>(end_ins -
                                                                      start_ins)
                    .count();
            result.push_back(elapsed_microseconds_ins / 1000);

            std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                      data_to_sort.begin());
        }
    }
    return result;
}

std::vector<double> Sorting::alg_quick_partition_sort() {
    for (int index = 0; index < number_of_elements.size(); index++) {
        data_to_sort.clear();
        data_to_sort.resize(number_of_elements[index]);

        std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                  data_to_sort.begin());

        for (int i = 0; i != samples; i++) {
            auto start_q = std::chrono::high_resolution_clock::now();
            quick_sort(data_to_sort.begin(), data_to_sort.end());
            auto end_q = std::chrono::high_resolution_clock::now();

            check_sorted(data_to_sort);

            auto elapsed_microseconds_quick =
                std::chrono::duration_cast<std::chrono::microseconds>(end_q -
                                                                      start_q)
                    .count();
            result.push_back(elapsed_microseconds_quick / 1000);

            std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                      data_to_sort.begin());
        }
    }

    return result;
}

std::vector<double> Sorting::alg_quick_median_sort() {
    for (int index = 0; index < number_of_elements.size(); index++) {
        data_to_sort.clear();
        data_to_sort.resize(number_of_elements[index]);

        std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                  data_to_sort.begin());

        for (int i = 0; i != samples; i++) {
            auto start_qm = std::chrono::high_resolution_clock::now();
            quick_sort_median(data_to_sort.begin(), data_to_sort.end());
            auto end_qm = std::chrono::high_resolution_clock::now();

            check_sorted(data_to_sort);

            std::chrono::microseconds elapsed_seconds_qm =
                std::chrono::duration_cast<std::chrono::microseconds>(end_qm -
                                                                      start_qm);
            int elapsed_microseconds = (int)elapsed_seconds_qm.count();
            result.push_back(elapsed_microseconds / 1000);

            std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                      data_to_sort.begin());
        }
    }

    return result;
}

std::vector<double> Sorting::alg_std_sort() {
    for (int index = 0; index < number_of_elements.size(); index++) {
        data_to_sort.clear();
        data_to_sort.resize(number_of_elements[index]);

        std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                  data_to_sort.begin());

        for (int i = 0; i != samples; i++) {
            auto start = std::chrono::high_resolution_clock::now();
            std::sort(data_to_sort.begin(), data_to_sort.end());
            auto end = std::chrono::high_resolution_clock::now();
            check_sorted(data_to_sort);

            std::chrono::microseconds elapsed_seconds =
                std::chrono::duration_cast<std::chrono::microseconds>(end -
                                                                      start);
            int elapsed_microseconds = (int)elapsed_seconds.count();
            result.push_back(elapsed_microseconds / 1000);

            std::copy(data.begin(), (data.begin() + number_of_elements[index]),
                      data_to_sort.begin());
        }
    }

    return result;
}
