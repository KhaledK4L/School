/*
#! c/c++
#Filnamn: projekt_kontakt, main.cpp
#Skrivet av: Khaled Hamza
#Skapat datum: 2024-12-27
#Ändrad senaste: 2025-01-12
#Kurs: datateknik
#Handledare: Jan-Erik och Nayeb Maleki
#Beskrivning: KONTAKTLEDNINGSSYSTEM
*/



#include "ContactBook.h"
#include <iostream>
#include <limits>
#include <cctype>




bool askToContinue() {
    char continueChoice;
    std::cout << "Vill du förstätta eller avslutar? (J/N): ";
    std::cin >> continueChoice;
    return std::tolower(continueChoice) == 'j';
}

int main() {


	std::cout<<"\n\n\n\n\n\n\n\n\t\t\t * VÄLKOMMEN TILL KONTAKTLEDNINGSSYSTEM *\n\n\n\n\n\n\n\n\t\t\t";
	
		ContactBook book;
        int choice;


    do {
        std::cout << "\nKONTAKTHANTERINGSSYSTEM\n";
        std::cout << "==========================\n";
        std::cout << "[1]. Lägg till kontakt\n";
        std::cout << "[2]. List på alla kontakter\n";
        std::cout << "[3]. Sök efter en kontakt\n";
        std::cout << "[4]. Ta bort en kontakt\n";
        std::cout << "[0]. Avslutar\n";
        std::cout << "==========================\n";
        std::cout << "Ange ditt val av dem fyra val genom att skriva nummret som tillhör:";
        

        while (!(std::cin >> choice) || choice < 0 || choice > 4) {
            std::cout << "Felaktig inmatning! Ange en siffra mellan 0 och 4.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Försök igen: ";
        }



        switch (choice) {
            case 1:
                
                book.addContact();
                if (!askToContinue()) {
                    choice = 0;
                }
                break;
            case 2:
                
                book.listContacts();
                if (!askToContinue()) {
                    choice = 0;
                }
                break;
            case 3: 
                
            {
                std::string query;
                std::cout << "Ange sökfråga: ";
                std::cin.ignore();
                std::getline(std::cin, query);
                book.searchContact(query);
                if (!askToContinue()) {
                    choice = 0;
                }
                break;
            }
            case 4: 
                
            {
                std::string telefon;
                std::cout << "Ange telefonnummer att ta bort: ";
                std::cin.ignore();
                std::getline(std::cin, telefon); 
                book.deleteContact(telefon);

                if (!askToContinue()) {
                    choice = 0;
                }
                break;
            }
            case 0:
                
                std::cout << "Avslutar..." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}