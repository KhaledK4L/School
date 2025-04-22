#include "sortCheck.h"
#include <iostream>
#include <fstream>
#include <string>

bool sortCheck(std::string fileName)
{
    std::ifstream input(fileName);

    if (!input.is_open())
    {
        std::cout << "Fel: Kunde inte öppna filen! " << fileName << std::endl;
        return false;
    }

    int a, b;

    
    if (!(input >> a))
    {
        std::cout << "Fel: Fil! " << fileName << " är tom eller innehåller ogiltiga data" << std::endl;
        input.close();
        return false;
    }

    
    while (input >> b)
    {
        if (a > b)
        {
            std::cout << fileName << " är INTE sorterad!" << std::endl;
            input.close();
            return false;
        }
        a = b;
    }

    std::cout << fileName << " är sorterad" << std::endl;
    input.close();
    return true;
}