// Namn: Khaled Hamza
// Datum: 20-04-2025
// Betyg: C

#include "Maze.h"
#include <iostream>
#include <random>
#include <algorithm>

// Konstruktor för Maze
// Initiera cellmatrisen med angivna rader och kolumner 
Maze::Maze(int r, int c) : rader(r), kolumner(c) {
    if (rader < 2) rader = 2;
    if (kolumner < 2) kolumner = 2;
    cellmatris.resize(rader, std::vector<Cell>(kolumner)); // Skapa cellmatris med rader x kolumner 2d-array ell vektor av vektorer
}

// Slumpa start och slut på olika väggar
void Maze::genereraLabyrint() {
    genereraLabyrintDFS(0, 0); // Starta från 0,0

    std::random_device rd; //hämtat https://en.cppreference.com/w/cpp/numeric/random/random_device
    std::mt19937 generator(rd()); // hämtat https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine

    int sida = generator() % 4; //	För att få ett tal mellan 0–3 → som motsvarar en sida

    if (sida == 0) {
        // Start längs översta raden
        startRad = 0;
        startKolumn = generator() % kolumner;
    }
    else if (sida == 1) {
        // Start längs nedersta raden
        startRad = rader - 1;
        startKolumn = generator() % kolumner; //Slumpa position längs raden
    }
    else if (sida == 2) {
        // Start längs vänstra kolumnen
        startRad = generator() % rader; //Slumpa position längs kolumnen
        startKolumn = 0;
    }
    else { // sida == 3
        // Start längs högra kolumnen
        startRad = generator() % rader;
        startKolumn = kolumner - 1;
    }

    do {
        sida = generator() % 4;

     if (sida == 0) {
        // Slut längs översta raden
        slutRad = 0;
        slutKolumn = generator() % kolumner;
        }
     else if (sida == 1) {
        // Slut längs nedersta raden
        slutRad = rader - 1;
        slutKolumn = generator() % kolumner;
        }
     else if (sida == 2) {
        // Slut längs vänstra kolumnen
        slutRad = generator() % rader;
        slutKolumn = 0;
     }
     else { // sida == 3
        // Slut längs högra kolumnen
        slutRad = generator() % rader;
        slutKolumn = kolumner - 1;
        }
    } while (startRad == slutRad && startKolumn == slutKolumn);//För att garantera att start och slut inte blir samma plats
}

// DFS-funktion för generering 
void Maze::genereraLabyrintDFS(int rad, int kolumn) {
    cellmatris[rad][kolumn].besokt = true;

    
    std::vector<std::pair<int, int>> riktningar = {
        {-1, 0}, // norr, upp
        {1, 0},  // syd , ner
        {0, -1}, // väst, vänster
        {0, 1}   // öst , höger
    };
    
    std::random_device rd;
    std::mt19937 generator(rd());
    std::shuffle(riktningar.begin(), riktningar.end(), generator);
    
    for (auto& riktning : riktningar) {
        int nyRad = rad + riktning.first;
        int nyKolumn = kolumn + riktning.second;
        
        if (nyRad >= 0 && nyRad < rader && nyKolumn >= 0 && nyKolumn < kolumner
            && !cellmatris[nyRad][nyKolumn].besokt) {
            
            if (riktning.first == -1) { // uppåt
                cellmatris[rad][kolumn].norr = false;
                cellmatris[nyRad][nyKolumn].syd = false;

            } else if (riktning.first == 1) { // neråt
                cellmatris[rad][kolumn].syd = false;
                cellmatris[nyRad][nyKolumn].norr = false;

            } else if (riktning.second == -1) { // vänster
                cellmatris[rad][kolumn].vast = false;
                cellmatris[nyRad][nyKolumn].ost = false;

            } else if (riktning.second == 1) { // höger
                cellmatris[rad][kolumn].ost = false;
                cellmatris[nyRad][nyKolumn].vast = false;
            }

            genereraLabyrintDFS(nyRad, nyKolumn);
        }
    }
}

// Visa labyrinten
void Maze::visaLabyrint() const {
    //toppen av labyrinten
    for (int kol = 0; kol < kolumner; ++kol) {
        std::cout << "+---";
    }
    std::cout << "+\n";

    //För varje rad i labyrinten
    for (int rad = 0; rad < rader; ++rad) {
        //Börja raden med en vänstervägg
        std::cout << "|";
        //För varje kolumn i labyrinten
        for (int kol = 0; kol < kolumner; ++kol) {
            //skriv innehållet i varje cell 
            if (rad == startRad && kol == startKolumn)
                std::cout << " S ";
            else if (rad == slutRad && kol == slutKolumn)
                std::cout << " E ";
            else if (cellmatris[rad][kol].losning)
                std::cout << " * ";
            else
                std::cout << "   ";
            //Efter varje cell: skriv höger vägg (eller tomt om vägg saknas)
            if (cellmatris[rad][kol].ost)
                std::cout << "|";
            else
                std::cout << " ";
        }
        //GÅ till nästa rad
        std::cout << "\n";
        //Skriv väggarna i labyrinten
        //Om cellens syd-vägg är kvar skriv +---, ÖPPEN = +, ETT + MELLAN VARJE VÄGG
        for (int kol = 0; kol < kolumner; ++kol) {
            if (cellmatris[rad][kol].syd)
                std::cout << "+---";
            else
                std::cout << "+   ";
        }
        std::cout << "+\n";
    }
}

// Starta lösning
void Maze::losLabyrint() {
    // Kontrollera att start 
    for (int rad = 0; rad < rader; ++rad) { 

        for (int kol = 0; kol < kolumner; ++kol) { // Kontrollera att cellerna inte är besökta
            cellmatris[rad][kol].besokt = false; // Återställ besökta celler
            cellmatris[rad][kol].losning = false; // Återställ lösning
        }
    }

    losLabyrintDFS(startRad, startKolumn); // Starta DFS från startpositionen
}

// DFS för lösning
// Om cellen är målet, markera den som en del av lösningen
bool Maze::losLabyrintDFS(int rad, int kolumn) {
    if (rad == slutRad && kolumn == slutKolumn) {
        cellmatris[rad][kolumn].losning = true;
        return true;
    }

    cellmatris[rad][kolumn].besokt = true;
    // Kolla alla riktningar (norr, syd, väst, öst)
    // Om det inte finns en vägg och cellen inte är besökt, fortsätt söka 
    if (!cellmatris[rad][kolumn].norr && rad > 0 && !cellmatris[rad - 1][kolumn].besokt) {
        if (losLabyrintDFS(rad - 1, kolumn)) {
            cellmatris[rad][kolumn].losning = true;
            return true;
        }
    }
    
    if (!cellmatris[rad][kolumn].syd && rad < rader - 1 && !cellmatris[rad + 1][kolumn].besokt) {
        if (losLabyrintDFS(rad + 1, kolumn)) {
            cellmatris[rad][kolumn].losning = true;
            return true;
        }
    }

    if (!cellmatris[rad][kolumn].vast && kolumn > 0 && !cellmatris[rad][kolumn - 1].besokt) {
        if (losLabyrintDFS(rad, kolumn - 1)) {
            cellmatris[rad][kolumn].losning = true;
            return true;
        }
    }

    if (!cellmatris[rad][kolumn].ost && kolumn < kolumner - 1 && !cellmatris[rad][kolumn + 1].besokt) {
        if (losLabyrintDFS(rad, kolumn + 1)) {
            cellmatris[rad][kolumn].losning = true;
            return true;
        }
    }
    // Om ingen väg hittas, markera cellen som inte ingår i lösningen
    return false;
}