#ifndef data_generation_h
#define data_generation_h

#include <stdio.h>
#include <vector>
#include <iostream>

class Data_generation {
private:
public:
    Data_generation();
    ~Data_generation();

    std::vector<int> random_values(int max_size);
    std::vector<int> ascending_values(int max_size);
    std::vector<int> descending_values(int max_size);
    std::vector<int> constant_values(int max_size);
};


#endif
