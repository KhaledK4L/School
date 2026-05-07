#include "data_gen.h"

#include <random>

std::vector<int> generate_random_data(int n) {
    std::vector<int> data(n);

    for (int& value : data) {
        value = rand() % (n * 10 + 101);
    }

    return data;
}

std::vector<int> generate_rising_data(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        data[i] = i;
    }
    return data;
}

std::vector<int> generate_falling_data(int n) {
    std::vector<int> data(n);
    for (int i = 0; i < n; ++i) {
        data[i] = n - i;
    }
    return data;
}

std::vector<int> generate_constant_data(int n) {
    return std::vector<int>(n, 42);
}
