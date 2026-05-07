#include "report.h"

#include <filesystem>
#include <fstream>
#include <iomanip>
#include <iostream>

void save_results(const std::string& filename,
                  const std::vector<MeasurementPoint>& points) {
    std::filesystem::create_directories("results");

    std::ofstream file("results/" + filename);
    if (!file) {
        std::cerr << "Kunde inte skriva till fil: " << filename << "\n";
        return;
    }

    file << "N mean_ms stddev_ms samples\n";
    file << std::fixed << std::setprecision(6);

    for (const auto& point : points) {
        file << point.N << ' '
             << point.mean_ms << ' '
             << point.stddev_ms << ' '
             << point.samples << '\n';
    }
}
