// Namn: Khaled Hamza
// Datum: 2025-05-15
// Betyg: E

#include <iostream>
#include "Maze.h"

void rensaInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

int main() {
    Maze maze;
    bool kor = true;

    while (kor) {
        std::cout << "\n===***** Labyrintprogram ******===\n";
        std::cout << "1. Skapa labyrint\n";
        std::cout << "2. Visa labyrint\n";
        std::cout << "0. Avsluta\n";
        std::cout << "\n===****==****===\n";

        int val;
        std::cout << "Välj ett alternativ: ";
        std::cin >> val;
        


        if (std::cin.fail()) {
            std::cout << "Felaktig inmatning försök igen.\n";
            std::cout << "Ange en siffra mellan 0-2.\n";
            rensaInput();
            continue;
        }

        if (val==1) {
            maze = Maze(); // återställ till 7x7
            maze.genereraLabyrint();
            std::cout << "Labyrint skapad!. Du kan välj 2 för att visa den labyrint\n";

            } else if (val==2) {
            std::cout << "Labyrint:\n";
            maze.visaLabyrint();

             } else if (val==0) {
            std::cout << "Avslutar programmet. Tack!\n";
            kor = false;
        } else {
            std::cout << "Felaktig inmatning. Försök igen.\n";
            std::cout << "Välj mellan 0-2.\n";
        }
    }
    return 0;
}