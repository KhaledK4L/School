#ifndef REPORT_H
#define REPORT_H

#include "stats.h"

#include <string>
#include <vector>

void save_results(const std::string& filename,
                  const std::vector<MeasurementPoint>& points);

#endif
