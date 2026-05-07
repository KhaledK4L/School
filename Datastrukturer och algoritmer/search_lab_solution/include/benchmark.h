#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <cstddef>
#include <functional>
#include <string>
#include <vector>

struct BenchmarkResult {
    std::size_t data_size{};
    double mean_nanoseconds{};
    double stddev_nanoseconds{};
    std::size_t sample_count{};
    double hit_rate{};
    std::size_t extra_value{}; // Används för t.ex. djupaste hashkedjan.
};

// Skapar slumpade sökvärden. Ungefär hälften är träffar och hälften är missar.
// Samma queries används för alla sökalgoritmer vid samma storlek.
std::vector<int> make_search_queries(const std::vector<int>& sorted_values,
                                     std::size_t query_count,
                                     unsigned int random_seed);

BenchmarkResult benchmark_search_method(
    std::size_t data_size,
    const std::vector<int>& search_queries,
    const std::function<bool(int)>& contains_function,
    std::size_t sample_count,
    std::size_t milliseconds_per_sample,
    std::size_t extra_value = 0);

void write_result_file(const std::string& file_path,
                       const std::vector<BenchmarkResult>& results);

#endif
