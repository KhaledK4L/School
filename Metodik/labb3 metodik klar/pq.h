#ifndef PQ_HEADER
#define PQ_HEADER
#include <functional>
#include <stdexcept>
#include <algorithm>
#include <vector>

template <typename T, typename COMP = std::less<>> // Default comparator is std::less ,returnera true om a < b
class pq {
public:
    pq(){};

    pq(COMP comp) : comparator(comp) {}

    template <typename IT>
    pq(IT first, IT last, COMP comp = COMP()) : data(first, last), comparator(comp) {
        std::make_heap(data.begin(), data.end(), comparator);
    }

    void push(T element) {
        data.push_back(element);
        std::push_heap(data.begin(), data.end(), comparator);
    }

    T top() const {
        if (!empty()) {
            return data.front();
        } else {
            throw std::out_of_range("Priority queue is empty");
        }
    }

    T pop() {
        if (!empty()) {
            std::pop_heap(data.begin(), data.end(), comparator);
            T top_element = data.back();
            data.pop_back();
            return top_element;
        } else {
            throw std::out_of_range("Priority queue is empty");
        }
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

private:
    std::vector<T> data;
    COMP comparator;
};
#endif