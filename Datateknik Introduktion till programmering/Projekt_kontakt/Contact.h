#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <iostream>


struct Contact {
    std::string förNamn; 
    std::string efterNamn; 
    std::string address; 
    std::string post; 
    std::string telefon; 
    std::string födelsdag;  
    std::string antackning;  

    void display() const; 
};

#endif
