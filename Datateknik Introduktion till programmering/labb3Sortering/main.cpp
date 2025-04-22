/*
#! c/c++
#Filnamn: labbSortering, main.cpp
#Skrivet av: Khaled Hamza
#Skapat datum: 2024-12-1
#Ändrad senaste: 2024-12-12
#Kurs: datateknik introduktion till programmering
#Handledare: Nayeb Maleki and Jan-Erik Jonsson.
*/

#include <iostream>
#include "merge.h"
#include "sortCheck.h"
#include <string>

int main()
{
    
    if (sortCheck("A.txt") && sortCheck("B.txt"))
    {
        
        std::string result = merge("A.txt", "B.txt", "sorted.txt");
        std::cout << result << std::endl;

        
        sortCheck("sorted.txt");
    }
    else
    {
        std::cout << "Fel: Filerna är inte sorterade korrekt! " << std::endl;
    }

    return 0;
}
