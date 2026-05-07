#ifndef INT_BUFFER_H
#define INT_BUFFER_H
#include <cstddef>

class int_buffer {
public:
    explicit int_buffer(std::size_t size);            // allokera size int
    int_buffer(const int* source, std::size_t size);  // kopiera från array
    int_buffer(const int_buffer& rhs);                // copy construct
    int_buffer(int_buffer&& rhs);                     // move construct

    int_buffer& operator=(const int_buffer& rhs);     // copy assign
    int_buffer& operator=(int_buffer&& rhs);          // move assign

    int& operator[](std::size_t index);
    const int& operator[](std::size_t index) const;

    std::size_t size() const;

    int* begin();
    int* end();
    const int* begin() const;
    const int* end() const;

    ~int_buffer();

    // fri swap-funktion (copy-and-swap idiom)
    friend void swap(int_buffer& first, int_buffer& second) noexcept;

private:
    int* _buffer;
    std::size_t _size;
};

#endif // INT_BUFFER_H