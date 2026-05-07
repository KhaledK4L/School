#ifndef EXPERIMENT_H
#define EXPERIMENT_H

#include "stats.h"

#include <functional>
#include <string>
#include <vector>

using SortFunction = std::function<void(std::vector<int>&)>;
using GeneratorFunction = std::function<std::vector<int>(int)>;

struct AlgoCase {
    std::string title;
    std::string id;
    SortFunction sort_function;
    GeneratorFunction generator_function;
    bool quadratic;
};

MeasurementPoint run_measurement(const AlgoCase& algo_case, int n, int samples);
std::vector<MeasurementPoint> run_series(const AlgoCase& algo_case,
                                         const std::vector<int>& sizes,
                                         int samples);

std::vector<AlgoCase> build_algo_cases();
std::vector<int> default_sizes_for(const AlgoCase& algo_case);

#endif
