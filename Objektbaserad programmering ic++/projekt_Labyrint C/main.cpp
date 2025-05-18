// Namn: Khaled Hamza
// Datum: 20-04-2025
// Betyg: C


#include <iostream>
#include <limits>
#include "Maze.h" 

// Funktion för att rensa inmatningsbufferten
// Används för att hantera ogiltig inmatning
void rensaInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}



int main() {
    Maze maze; // Ny Maze med standard 7x7
    bool kor = true;
    
    while (kor) {
        std::cout << "\n===***** Labyrintprogram ******===\n";
        std::cout << "1. Skapa ny labyrint\n";
        std::cout << "2. Lös labyrinten\n";
        std::cout << "3. Avsluta\n";
        std::cout << "\n===****==****===\n";
        
        int val;
        std::cout << "Ange den val: ";
        std::cin >> val;

        if (std::cin.fail()) {
            std::cout << "Felaktig inmatning. Försök igen.\n";
            std::cout << "Ange en siffra mellan 1 och 3.\n";
            rensaInput();
            continue;
        }
        

       /* if (val < 1 || val > 3) {
            std::cout << "Ange en siffra mellan 1 och 3.\n";
            rensaInput();
            continue;
        }*/

        if (val == 1) {
            int rader, kolumner;
            std::cout << "Ange antal rader, OBS [Bara siffror] (minst 2): ";
            std::cin >> rader;

            if (std::cin.fail() || rader < 2) {
                std::cout << "Ogiltigt antal rader. ! Ange en siffra som är minst 2.\n";
                rensaInput();
                continue;
            }
            std::cout << "Ange antal kolumner, OBS [Bara siffror](minst 2): ";
            std::cin >> kolumner;
            if (std::cin.fail() || kolumner < 2) {
                std::cout << "Ogiltigt antal kolumner. ! Ange en siffra som är minst 2.\n";
                rensaInput();
                continue;
            }

            maze = Maze(rader, kolumner); // Skapa ny maze
            maze.genereraLabyrint();
            maze.visaLabyrint();
        }
        else if (val == 2) {
            maze.losLabyrint();
            maze.visaLabyrint();
        }
        else if (val == 3) {
            kor = false;
        }
    }

    std::cout << "Programmet avslutades. :)!\n";
    return 0;
}