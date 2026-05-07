#include "int_buffer.h"
#include <algorithm>

int_buffer::int_buffer(std::size_t size)
    : _buffer(new int[size]{}), _size(size) {
}

int_buffer::int_buffer(const int* source, std::size_t size)
    : int_buffer(size) {
    std::copy(source, source + size, _buffer);
}

int_buffer::int_buffer(const int_buffer& rhs)
    : int_buffer(rhs.begin(), rhs.size()) {
}

int_buffer::int_buffer(int_buffer&& rhs)
    : _buffer(rhs._buffer), _size(rhs._size) {
    rhs._buffer = nullptr;
    rhs._size = 0;
}

int_buffer& int_buffer::operator=(const int_buffer& rhs) {
    if (this != &rhs) {
        int_buffer tmp(rhs);   // kopiera
        swap(*this, tmp);      // byt innehåll
    }
    return *this;
}

int_buffer& int_buffer::operator=(int_buffer&& rhs) {
    if (this != &rhs) {
        swap(*this, rhs);      // byt innehåll
    }
    return *this;
}

int& int_buffer::operator[](std::size_t index) {
    return _buffer[index];
}

const int& int_buffer::operator[](std::size_t index) const {
    return _buffer[index];
}

std::size_t int_buffer::size() const {
    return _size;
}

int* int_buffer::begin() {
    return _buffer;
}

int* int_buffer::end() {
    return _buffer + _size;
}

const int* int_buffer::begin() const {
    return _buffer;
}

const int* int_buffer::end() const {
    return _buffer + _size;
}

int_buffer::~int_buffer() {
    delete[] _buffer;
}

void swap(int_buffer& first, int_buffer& second) noexcept {
    std::swap(first._buffer, second._buffer);
    std::swap(first._size, second._size);
}