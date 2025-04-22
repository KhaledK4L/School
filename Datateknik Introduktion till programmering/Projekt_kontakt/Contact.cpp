#include "Contact.h"


void Contact::display() const {
    std::cout << "===========================" << std::endl;
    std::cout << "Namn: " << förNamn << " " << efterNamn << std::endl;
    std::cout << "Telefonesnummer: " << telefon << std::endl;
    std::cout << "Address: " << address << std::endl;
    std::cout << "E-post: " << post << std::endl;
    std::cout << "Födelsdag: " << födelsdag << std::endl;
    std::cout << "Antackningar: " << antackning << std::endl;
    std::cout << "===========================" << std::endl;
}