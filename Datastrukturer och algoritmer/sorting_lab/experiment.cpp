#include "experiment.h"

#include "data_gen.h"
#include "sorting.h"

#include <algorithm>
#include <chrono>
#include <iostream>

MeasurementPoint run_measurement(const AlgoCase& algo_case, int n, int samples) {
    std::vector<double> times_ms;
    times_ms.reserve(samples);

    std::vector<int> original = algo_case.generator_function(n);

    for (int i = 0; i < samples; ++i) {
        std::vector<int> data = original;

        auto start = std::chrono::steady_clock::now();
        algo_case.sort_function(data);
        auto end = std::chrono::steady_clock::now();

        if (!std::is_sorted(data.begin(), data.end())) {
            std::cerr << "Fel: sorteringen misslyckades för "
                      << algo_case.id << " vid N=" << n << "\n";
        }

        std::chrono::duration<double, std::milli> elapsed = end - start;
        times_ms.push_back(elapsed.count());
    }

    return MeasurementPoint{
        n,
        compute_mean(times_ms),
        compute_stddev(times_ms),
        samples
    };
}

std::vector<MeasurementPoint> run_series(const AlgoCase& algo_case,
                                         const std::vector<int>& sizes,
                                         int samples) {
    std::vector<MeasurementPoint> results;

    for (int n : sizes) {
        std::cout << "Kör " << algo_case.id << " med N=" << n << "...\n";
        results.push_back(run_measurement(algo_case, n, samples));
    }

    return results;
}

std::vector<AlgoCase> build_algo_cases() {
    return {
        {"Insertion random", "insertion.random", insertion_sort, generate_random_data, true},
        {"Insertion rising", "insertion.rising", insertion_sort, generate_rising_data, true},
        {"Insertion falling", "insertion.falling", insertion_sort, generate_falling_data, true},
        {"Insertion constant", "insertion.constant", insertion_sort, generate_constant_data, true},

        {"Selection random", "selection.random", selection_sort, generate_random_data, true},
        {"Selection rising", "selection.rising", selection_sort, generate_rising_data, true},
        {"Selection falling", "selection.falling", selection_sort, generate_falling_data, true},
        {"Selection constant", "selection.constant", selection_sort, generate_constant_data, true},

        {"Quicksort right random", "quicksort_right.random", quicksort_right_pivot, generate_random_data, false},
        {"Quicksort right rising", "quicksort_right.rising", quicksort_right_pivot, generate_rising_data, false},
        {"Quicksort right falling", "quicksort_right.falling", quicksort_right_pivot, generate_falling_data, false},
        {"Quicksort right constant", "quicksort_right.constant", quicksort_right_pivot, generate_constant_data, false},

        {"Quicksort median3 random", "quicksort_median3.random", quicksort_median3, generate_random_data, false},
        {"Quicksort median3 rising", "quicksort_median3.rising", quicksort_median3, generate_rising_data, false},
        {"Quicksort median3 falling", "quicksort_median3.falling", quicksort_median3, generate_falling_data, false},
        {"Quicksort median3 constant", "quicksort_median3.constant", quicksort_median3, generate_constant_data, false},

        {"std::sort random", "stdsort.random", std_sort_wrapper, generate_random_data, false},
        {"std::sort rising", "stdsort.rising", std_sort_wrapper, generate_rising_data, false},
        {"std::sort falling", "stdsort.falling", std_sort_wrapper, generate_falling_data, false},
        {"std::sort constant", "stdsort.constant", std_sort_wrapper, generate_constant_data, false}
    };
}

std::vector<int> default_sizes_for(const AlgoCase& algo_case) {
    if (algo_case.quadratic) {
        return {1000, 2000, 3000, 4000, 5000};
    }

    return {10000, 20000, 50000, 100000, 200000};
}


/*std::vector<int> default_sizes_for(const AlgoCase& algo_case) {
    if (algo_case.quadratic) {
        return {2000, 4000, 6000, 8000, 10000};
    }

    return {20000, 50000, 100000, 200000, 400000};
}*/