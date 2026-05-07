#ifndef STATS_H
#define STATS_H

#include <vector>

struct MeasurementPoint {
    int N;
    double mean_ms;
    double stddev_ms;
    int samples;
};

double compute_mean(const std::vector<double>& values);
double compute_stddev(const std::vector<double>& values);

#endif
