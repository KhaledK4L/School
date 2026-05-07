#include "sorting.h"

#include <algorithm>
#include <utility>

void insertion_sort(std::vector<int>& data) {
    for (std::size_t i = 1; i < data.size(); ++i) {
        int key = data[i];
        std::size_t j = i;

        while (j > 0 && data[j - 1] > key) {
            data[j] = data[j - 1];
            --j;
        }
        data[j] = key;
    }
}

void selection_sort(std::vector<int>& data) {
    for (std::size_t i = 0; i < data.size(); ++i) {
        std::size_t min_index = i;
        for (std::size_t j = i + 1; j < data.size(); ++j) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        std::swap(data[i], data[min_index]);
    }
}

static int partition_right(std::vector<int>& data, int low, int high) {
    int pivot = data[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (data[j] <= pivot) {
            ++i;
            std::swap(data[i], data[j]);
        }
    }

    std::swap(data[i + 1], data[high]);
    return i + 1;
}

static void quicksort_right_recursive(std::vector<int>& data, int low, int high) {
    while (low < high) {
        int pivot_index = partition_right(data, low, high);

        if (pivot_index - low < high - pivot_index) {
            quicksort_right_recursive(data, low, pivot_index - 1);
            low = pivot_index + 1;
        } else {
            quicksort_right_recursive(data, pivot_index + 1, high);
            high = pivot_index - 1;
        }
    }
}

void quicksort_right_pivot(std::vector<int>& data) {
    if (!data.empty()) {
        quicksort_right_recursive(data, 0, static_cast<int>(data.size()) - 1);
    }
}

static int median_of_three_index(std::vector<int>& data, int low, int high) {
    int mid = low + (high - low) / 2;

    if (data[low] > data[mid]) {
        std::swap(data[low], data[mid]);
    }
    if (data[low] > data[high]) {
        std::swap(data[low], data[high]);
    }
    if (data[mid] > data[high]) {
        std::swap(data[mid], data[high]);
    }

    return mid;
}

static int partition_median3(std::vector<int>& data, int low, int high) {
    int pivot_index = median_of_three_index(data, low, high);
    std::swap(data[pivot_index], data[high]);
    return partition_right(data, low, high);
}

static void quicksort_median3_recursive(std::vector<int>& data, int low, int high) {
    while (low < high) {
        int pivot_index = partition_median3(data, low, high);

        if (pivot_index - low < high - pivot_index) {
            quicksort_median3_recursive(data, low, pivot_index - 1);
            low = pivot_index + 1;
        } else {
            quicksort_median3_recursive(data, pivot_index + 1, high);
            high = pivot_index - 1;
        }
    }
}

void quicksort_median3(std::vector<int>& data) {
    if (!data.empty()) {
        quicksort_median3_recursive(data, 0, static_cast<int>(data.size()) - 1);
    }
}

void std_sort_wrapper(std::vector<int>& data) {
    std::sort(data.begin(), data.end());
}
