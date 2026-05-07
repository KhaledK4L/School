#include "int_buffer.h"
#include "int_sorted.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>   
#include <algorithm> 


void insert_random(int_buffer& a) {
    int* ptr = a.begin();
    for (std::size_t i = 0; i < a.size(); ++i, ++ptr) {
        *ptr = std::rand() % 10;
    }
}

void print(const int_buffer& a) {
    const int* ptr = a.begin();
    const int* end = a.end();
    for (; ptr != end; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;
}

void print_sorted(const int_sorted& a) {
    const int* ptr = a.begin();
    const int* end = a.end();
    for (; ptr != end; ++ptr) {
        std::cout << *ptr << " ";
    }
    std::cout << std::endl;

}



// Selection sort på ett intervall [begin, end)
void selection_sort(int* begin, int* end) {
    for (int* i = begin; i != end; ++i) {
        int* min_it = i;
        for (int* j = i + 1; j != end; ++j) {
            if (*j < *min_it) {
                min_it = j;
            }
        }
        // byt plats på *i och *min_it
        std::swap(*i, *min_it);
    }
}


int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // 1) Testa insert(): bygga upp en sorterad följd via insert
    int_sorted s_empty(nullptr, 0);
    for (int i = 0; i < 20; ++i) {
        s_empty.insert(std::rand() % 100);
    }
    std::cout << "Efter insert() (ska vara sorterad):" << std::endl;
    print_sorted(s_empty);
    std::cout << std::endl;

    // 2) Testa sort() och merge()
    int_buffer b1(10);
    int_buffer b2(10);

    insert_random(b1);
    insert_random(b2);

    std::cout << "Lista 1 (osorterad):" << std::endl;
    print(b1);
    std::cout << "Lista 2 (osorterad):" << std::endl;
    print(b2);
    std::cout << std::endl;

    int_sorted s1 = sort(b1.begin(), b1.end());
    int_sorted s2 = sort(b2.begin(), b2.end());

    std::cout << "Lista 1 (sorterad med sort()):" << std::endl;
    print_sorted(s1);
    std::cout << "Lista 2 (sorterad med sort()):" << std::endl;
    print_sorted(s2);
    std::cout << std::endl;

    int_sorted merged = s1.merge(s2);
    std::cout << "Sammanfogad lista (merge):" << std::endl;
    print_sorted(merged);


    



        // 3) Tidsmätning: mergesort (sort) vs selection sort
    const std::size_t N = 400000;

    // Skapa stor buffer med slumpdata
    int_buffer big(N);
    insert_random(big);

    // Kopia för selection sort, så båda får samma startdata
    int_buffer big_for_selection(big.begin(), big.size());

    std::cout << "\nTidsmätning på " << N << " element:\n";

    // --- Mät tid för mergesort-baserade sort() ---
    auto start_merge = std::chrono::high_resolution_clock::now();
    int_sorted big_sorted = sort(big.begin(), big.end());
    auto end_merge = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> dur_merge = end_merge - start_merge;

    // --- Mät tid för selection sort ---
    auto start_sel = std::chrono::high_resolution_clock::now();
    selection_sort(big_for_selection.begin(), big_for_selection.end());
    auto end_sel = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> dur_sel = end_sel - start_sel;

    std::cout << "Mergesort (sort-funktionen): " << dur_merge.count() << " ms\n";
    std::cout << "Selection sort:            " << dur_sel.count()   << " ms\n";

    return 0;
}