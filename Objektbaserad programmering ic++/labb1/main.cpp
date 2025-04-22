/*
 Skrivet av: Khaled Hamza
    Datum: 2025-03-25
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


struct Address {
    std::string street;
    int zip;
    std::string city;
};


struct Person {
    std::string name;
    std::string id;
    Address location;
};

// hälp från chatt 
std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    return (first == std::string::npos || last == std::string::npos) ? "" : str.substr(first, last - first + 1);
}//slutar hjälp från chatt




std::string to_lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) { return std::tolower(c); });
    return result;
}




std::istream& operator>>(std::istream& in, Person& p) {
    std::getline(in, p.name);
    std::getline(in, p.id);
    std::string addressLine; 
    std::getline(in, addressLine);
    
    // hälp från chatt 
    size_t commaPos = addressLine.find(",");
    size_t spacePos = addressLine.find("  ", commaPos);

    
    if (commaPos == std::string::npos || spacePos == std::string::npos) {
        std::cerr << "Ogiltigt adressformat för: " << p.name << std::endl;
        in.setstate(std::ios::failbit);
        return in;
    }
    
    p.location.street = addressLine.substr(0, commaPos);
    p.location.zip = std::stoi(addressLine.substr(commaPos + 2, spacePos - commaPos - 2));
    p.location.city = trim(addressLine.substr(spacePos + 2));
    //slutar hjälp från chatt
    return in;
}



std::vector<Person> read_file(std::string filename) {
    std::ifstream file(filename);
    std::vector<Person> Pesoner;

    if (!file) {
        std::cerr << "Fel vid öppning av fil: " << filename << std::endl;
        return Pesoner;
    }

    Person p;
    while (file >> p) {
        Pesoner.push_back(p);
    }

    /*for(int i=0; i<Pesoner.size(); i++){
        std::cout << Pesoner[i].name << std::endl;
        std::cout << Pesoner[i].location.city << std::endl;
    }*/

    file.close();
    return Pesoner;
}



size_t find_in_names(const std::vector<Person>& haystack, std::string name_part) {
    size_t count = 0;
    std::string lower_name_part = to_lower(name_part);

    for (const auto& p : haystack) {
        if (to_lower(p.name).find(lower_name_part) != std::string::npos) {
            count++;
        }
    }

    return count;
}


std::vector<Person>  find_person_from_city (const std::vector<Person>& haystack, std::string city) {
    std::vector<Person> matches;
    std::string lower_city = to_lower(city);

    for (const auto& p : haystack) {
        if (to_lower(p.location.city) == lower_city) {
            matches.push_back(p);
        }
    }

    if (matches.empty()) {
        std::cout << "===========================\n";
        std::cout << "Inga resultat för staden " << city << std::endl;
        std::cout << "===========================\n";
    }

    return matches;
}


int main() {
    std::string filename = "persons.txt";
    std::vector<Person> Pesoner = read_file(filename);

    if (Pesoner.empty()) {
        std::cout << "Ingen data i filen." << std::endl;
        return 1;
    }
    
    int choice;
    do {
        std::cout<<"\n\n\n\n\n\n\n\n\t\t\t * VÄLKOMMEN TILL KONTAKTSSÖKNING *\n\n\n\n\n\n\n\n\t\t\t";
        std::cout << "\nMeny:\n";
        std::cout << "===========================\n";
        std:: cout << "[1]. Sök del av personnamn\n";
        std:: cout << "[2]. Sök efter personer i stad\n";
        std:: cout << "[3]. Avsluta\n";
        std::cout << "===========================\n";
        std:: cout << "Ange det Val (1-3)!: ";
        std::  cin >> choice;
        std:: cin.ignore();
        
        if (choice == 1) {
            std::string name_part;
            std::cout << "Ange en del av personnamn: ";
            std::getline(std::cin, name_part);
            std::cout << "===========================\n";
            std::cout << "Antal matchningar: " << find_in_names(Pesoner, name_part) << "\n";
            std::cout << "===========================\n";
        } else if (choice == 2) {
            std::string city;
            std::cout << "Ange en personer i stad: ";
            std::getline(std::cin, city);
            std::vector<Person> matches =  find_person_from_city(Pesoner, city);
            for (const auto& p : matches) {
                std::cout << p.id << ", " << p.name << ", " << p.location.zip << ", " << p.location.city << "\n";
            }
        }
    } while (choice != 3);
    std::cout << "* * ===========================* * \n";
    std::cout << "Den program avslutar!!\n ";
    std::cout << "* * ===========================* * \n";
    return 0;
}