// Namn: Khaled Hamza
// Datum: 2025-05-15
// Betyg: E

#ifndef MAZE_H
#define MAZE_H

#include <vector>

struct Cell {
    bool besokt = false;
    bool norr = true;
    bool syd = true;
    bool ost = true;
    bool vast = true;
};

class Maze {
private:
    std::vector<std::vector<Cell>> cellmatris;
    int rader = 7;
    int kolumner = 7;

    void genereraLabyrintDFS(int rad, int kolumn);

public:
    Maze();
    void genereraLabyrint();
    void visaLabyrint() const;
};

#endif