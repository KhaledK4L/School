#pragma once
#include <vector>
#include <string>
#include "reader.h"

// Stort tal som betyder "ingen kant finns"
const double INF = 1e18;

// Grafen som en matris.
// matris[från][till] = avstånd i meter, INF = ingen kant.
struct Graf {
    int antal_noder;
    std::vector<std::vector<double>> matris;
    meta_t nodnamn;

    Graf(int antal_noder, meta_t nodnamn)
        : antal_noder(antal_noder),
          matris(antal_noder, std::vector<double>(antal_noder, INF)),
          nodnamn(nodnamn) {
        for (int i = 0; i < antal_noder; i++)
            matris[i][i] = 0.0;
    }

    void lägg_till_kant(int fran, int till, double vikt) {
        matris[fran][till] = vikt;
    }

    std::string namn(int id) const {
        auto it = nodnamn.find(id);
        if (it != nodnamn.end())
            return it->second;
        return std::to_string(id);
    }
};

// Skapar en ny graf där alla kanter är vända (A->B blir B->A).
// Används för att kolla om alla noder kan nå nod 0.
Graf vänd_graf(const Graf& g) {
    Graf omvänd(g.antal_noder, g.nodnamn);
    for (int fran = 0; fran < g.antal_noder; fran++)
        for (int till = 0; till < g.antal_noder; till++)
            if (fran != till && g.matris[fran][till] != INF)
                omvänd.matris[till][fran] = g.matris[fran][till];
    return omvänd;
}
