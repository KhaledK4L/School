#pragma once
#include <vector>
#include <queue>
#include <stack>
#include "graf.h"

// Hämtar nästa nod ur kön (BFS — bredden-först)
int hämta(std::queue<int>& q) { return q.front(); }

// Hämtar nästa nod ur stacken (DFS — djupet-först)
int hämta(std::stack<int>& s) { return s.top(); }

// Generell sökning — exakt samma logik, enda skillnaden är Container:
//   BFS: sökning<std::queue<int>>(g, startnod)
//   DFS: sökning<std::stack<int>>(g, startnod)
template<typename Container>
std::vector<bool> sökning(const Graf& g, int startnod) {
    std::vector<bool> besökt(g.antal_noder, false);
    Container frontier;

    frontier.push(startnod);
    besökt[startnod] = true;

    while (!frontier.empty()) {
        int nuvarande = hämta(frontier);
        frontier.pop();

        for (int granne = 0; granne < g.antal_noder; granne++)
            if (!besökt[granne] && g.matris[nuvarande][granne] != INF) {
                besökt[granne] = true;
                frontier.push(granne);
            }
    }

    return besökt;
}
