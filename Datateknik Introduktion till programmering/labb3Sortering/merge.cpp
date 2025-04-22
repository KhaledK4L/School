#include <iostream>
#include <string>
#include <fstream>

std::string merge(std::string fileName, std::string fileName2, std::string sortedFile)
{
    std::ifstream input1(fileName);
    std::ifstream input2(fileName2);
    std::ofstream output(sortedFile);

    
    if (!input1.is_open() || !input2.is_open() || !output.is_open())
    {
        return "Fel: Kunde inte öppna en eller flera filer.";
    }

    int a, b;

    
    input1 >> a;
    input2 >> b;

    while (!input1.eof() && !input2.eof())
    {
        if (a < b)
        {
            output << a << " ";
            input1 >> a;
        }
        else
        {
            output << b << " ";
            input2 >> b;
        }
    }

    
    while (!input1.eof())
    {
        output << a << " ";
        input1 >> a;
    }

    
    while (!input2.eof())
    {
        output << b << " ";
        input2 >> b;
    }

    std::string finished = "Filer är nu sammanslagna och sorterade.";
    input1.close();
    input2.close();
    output.close();
    return finished;
}
