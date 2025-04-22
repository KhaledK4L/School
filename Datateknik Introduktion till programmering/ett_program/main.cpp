#include <iostream>
#include <vector>

int main() {

    std::vector<int> minVector = {1, 2, 3, 4};

    std::cout << "Talen som finns i vektorn är: ";
    for (int tal : minVector) {
        std::cout << tal << " ";
    }
    std::cout << std::endl;

    return 0;
}
