#include "stats.h"

#include <cmath>
#include <numeric>

double compute_mean(const std::vector<double>& values) {
    if (values.empty()) {
        return 0.0;
    }

    double sum = std::accumulate(values.begin(), values.end(), 0.0);
    return sum / static_cast<double>(values.size());
}

double compute_stddev(const std::vector<double>& values) {
    if (values.size() < 2) {
        return 0.0;
    }

    double mean = compute_mean(values);
    double sum = 0.0;

    for (double value : values) {
        double diff = value - mean;
        sum += diff * diff;
    }

    return std::sqrt(sum / static_cast<double>(values.size() - 1));
}
