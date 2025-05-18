// Namn: Khaled Hamza
// Datum: 2025-05-15
// Betyg: E

#include "Maze.h"
#include <iostream>
#include <random>
#include <algorithm>

// Konstruktor: skapar 7x7 cellmatris
Maze::Maze() {
    cellmatris.resize(rader, std::vector<Cell>(kolumner));
}

// Startar labyrintgenerering med DFS
void Maze::genereraLabyrint() {
    genereraLabyrintDFS(0, 0); // Startpunkt fast: 0,0
}

// DFS-algoritm för att bygga labyrint
void Maze::genereraLabyrintDFS(int rad, int kolumn) {
    cellmatris[rad][kolumn].besokt = true;

    // Slumpar riktningar för att skapa en labyrint
    std::vector<std::pair<int, int>> riktningar = {
        {-1, 0}, // Norr ↑
        {1, 0},  // Syd ↓
        {0, -1}, // Väst ←
        {0, 1}   // Öst →
    };

    // Slumpar riktningarna
    // Använder std::random_device och std::mt19937 för att blanda riktningarna
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(riktningar.begin(), riktningar.end(), generator);



    // Iterera över riktningarna
    for (const auto& riktning : riktningar) {
        // Beräkna nya koordinater
        int nyRad = rad + riktning.first;

        int nyKol = kolumn + riktning.second;

        // Kontrollera om den nya cellen är inom gränserna och inte besökt
        if (nyRad >= 0 && nyRad < rader && nyKol >= 0 && nyKol < kolumner &&
            !cellmatris[nyRad][nyKol].besokt) {


            // Ta bort väggen mellan den aktuella cellen och den nya cellen
            // Om riktning är norr eller syd
            if (riktning.first == -1) { //uppåt
                cellmatris[rad][kolumn].norr = false;
                cellmatris[nyRad][nyKol].syd = false;


            } else if (riktning.first == 1) { //nedåt
                cellmatris[rad][kolumn].syd = false;
                cellmatris[nyRad][nyKol].norr = false;


                // Om riktning är väst eller öst
            } else if (riktning.second == -1) { //vänster
                cellmatris[rad][kolumn].vast = false;
                cellmatris[nyRad][nyKol].ost = false;


            } else if (riktning.second == 1) {  //höger
                cellmatris[rad][kolumn].ost = false;
                cellmatris[nyRad][nyKol].vast = false;

            }


            // Rekursivt anropa DFS för den nya cellen
            genereraLabyrintDFS(nyRad, nyKol);
        }
    }
}



// Skriv ut labyrinten i konsolen
void Maze::visaLabyrint() const {
    for (int kol = 0; kol < kolumner; ++kol) {
        std::cout << "+---";
    }
    std::cout << "+\n";

    // Skriv ut cellerna i labyrinten
    for (int rad = 0; rad < rader; ++rad) {
        std::cout << "|";
        for (int kol = 0; kol < kolumner; ++kol) {
            if (rad == 0 && kol == 0)
                std::cout << " S ";
            else if (rad == rader - 1 && kol == kolumner - 1)
                std::cout << " E ";
            else
                std::cout << "   ";

            std::cout << (cellmatris[rad][kol].ost ? "|" : " ");
        }
        std::cout << "\n";

        // Skriv ut väggen mellan cellerna
        for (int kol = 0; kol < kolumner; ++kol) {
            std::cout << "+";
            std::cout << (cellmatris[rad][kol].syd ? "---" : "   ");
        }
        std::cout << "+\n";
    }
}