/*
#! c/c++
#Filnamn: labbtexthantering, labb2.cpp
#Skrivet av: Khaled Hamza
#Skapat datum: 2022-11-29
#Ändrad senaste: 2022-11-03
#Kurs: datateknik
#Handledare: Jan-Erik
#Beskrivning: Filhantering
*/

#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream myFile;
    std::ofstream Result;

    myFile.open("names.txt", std::ios::in);
    Result.open("result.txt", std::ios::out);


    std::string förnamn, efternamn, address, personnummer;

    while (std::getline(myFile, förnamn, ' ')) {
        std::getline(myFile, efternamn);
        std::getline(myFile, personnummer);
        std::getline(myFile, address);
        
        if (personnummer.size() > 8) {

            if ((personnummer[8]) % 2 == 0) {
                Result << efternamn << ", " << förnamn << "\t[K]" <<std::endl;
            } else {
                Result << efternamn << ", " << förnamn << "\t[M]" << std::endl;
            }
            Result << address << std::endl;
        }
    }

    myFile.close();
    Result.close();
  
    std::cout << "Programmet avslutar! Den resultat finns i (result.txt)" <<std::endl;
    

    return 0;
}