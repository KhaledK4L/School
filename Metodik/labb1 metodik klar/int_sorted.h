#ifndef INT_SORTED_H
#define INT_SORTED_H

#include <cstdlib>
#include "int_buffer.h"

class int_sorted
{
private:
    int_buffer buffer;

public:

    explicit int_sorted(const int_buffer& buffer);

    // Constructors
    int_sorted();

    int_sorted(const int* source, size_t length); // resize constructor

    // Methods
    size_t size() const;

    void insert(int value); // returns the insertion point.

    const int* begin() const;

    const int* end() const;

    int_sorted merge(const int_sorted& merge_with) const;

    bool isSorted() const;
};

#endif