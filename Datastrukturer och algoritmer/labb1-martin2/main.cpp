#include <iostream>
//#include <windows.h>
#include "reader.h"
#include "graf.h"
#include "dfs.h"
#include "bfs.h"
#include "dijkstra.h"

// Läser in edges.txt och bygger grafen
Graf bygg_graf() {
    adjacency_list_t data = parse_file("edges.txt");
    meta_t nodnamn = data.first;
    edge_list_t kantar = data.second;
    Graf g((int)nodnamn.size(), nodnamn);
    for (int i = 0; i < (int)kantar.size(); i++)
        g.lägg_till_kant(kantar[i].n1, kantar[i].n2, kantar[i].weight);
    return g;
}

// Kollar om grafen är sammanhängande med DFS eller BFS.
// Kör sökningen FRAMÅT (nod 0 -> alla) och BAKÅT (alla -> nod 0).
// Om båda fungerar kan man ta sig mellan vilka noder som helst.
void kolla_sammanhang(const Graf& g, const std::string& metod) {
    std::cout << "\n=== Sammanhangskoll (" << metod << ") ===\n";

    std::vector<bool> framåt(g.antal_noder, false);
    std::vector<bool> bakåt(g.antal_noder, false);

    Graf omvänd = vänd_graf(g);

    if (metod == "DFS") {
        framåt = dfs(g,      0);
        bakåt  = dfs(omvänd, 0);
    } else {
        framåt = bfs(g,      0);
        bakåt  = bfs(omvänd, 0);
    }

    bool ok = true;
    for (int i = 0; i < g.antal_noder; i++) {
        if (!framåt[i]) {
            std::cout << "  Ej nåbar från nod 0: " << i << " (" << g.namn(i) << ")\n";
            ok = false;
        }
        if (!bakåt[i]) {
            std::cout << "  Kan ej nå nod 0: " << i << " (" << g.namn(i) << ")\n";
            ok = false;
        }
    }
    std::cout << (ok ? "  Grafen är sammanhängande!\n" : "  Grafen är INTE sammanhängande!\n");
}

int main() {
    //SetConsoleOutputCP(CP_UTF8);

    Graf g = bygg_graf();

    // Skriv ut alla noder
    std::cout << "=== Noder (" << g.antal_noder << ") ===\n";
    for (auto& [id, namn] : g.nodnamn)
        std::cout << "  " << id << ": " << namn << "\n";

    // Sammanhangskoll
    kolla_sammanhang(g, "DFS");
    kolla_sammanhang(g, "BFS");

    // Kortaste vägarna (nod-ID:n från edges.txt)
    kortaste_vägen(g, 23, 37);  // Nackstavägen -> Förrådet
    kortaste_vägen(g, 46, 47);  // L319 -> D025
    kortaste_vägen(g, 20, 19);  // Universitetet -> Bite Line Västra

    return 0;
}
