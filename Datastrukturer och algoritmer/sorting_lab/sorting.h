#ifndef SORTING_H
#define SORTING_H

#include <vector>

void insertion_sort(std::vector<int>& data);
void selection_sort(std::vector<int>& data);
void quicksort_right_pivot(std::vector<int>& data);
void quicksort_median3(std::vector<int>& data);
void std_sort_wrapper(std::vector<int>& data);

#endif
