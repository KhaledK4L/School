// Namn: Khaled Hamza
// Datum: 20-04-2025
// Betyg: C

#ifndef MAZE_H
#define MAZE_H

#include <vector>

struct Cell {
    bool besokt = false;
    bool norr = true;
    bool syd = true;
    bool ost = true;
    bool vast = true;
    bool losning = false; // True om cellen ingår i lösningen
};


class Maze {
private:
    std::vector<std::vector<Cell>> cellmatris; // 2D-array av celler
    int rader;
    int kolumner;
    int startRad, startKolumn;
    int slutRad, slutKolumn;

    void genereraLabyrintDFS(int rad, int kolumn);
    bool losLabyrintDFS(int rad, int kolumn);

public:
    Maze(int r = 7, int c = 7);
    void genereraLabyrint();
    void visaLabyrint() const;
    void losLabyrint();
};

#endif
