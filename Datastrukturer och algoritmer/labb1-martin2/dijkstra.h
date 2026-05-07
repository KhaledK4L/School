#pragma once
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include "graf.h"

// DIJKSTRA — hittar kortaste vägen från start till mål.
//
// Fungerar som en GPS: håller reda på kortaste kända avstånd till varje nod,
// och utforskar alltid den närmaste noden härnäst.
//
// Använder en prioritetskö med pair<avstånd, nod> — minsta avstånd plockas alltid
// först automatiskt tack vare std::greater.
void kortaste_vägen(const Graf& g, int start, int mål) {
    std::cout << "\n=== " << g.namn(start) << " -> " << g.namn(mål) << " ===\n";

    // Setup: alla noder är oändligt långt bort, ingen känd väg än
    std::vector<double> avstånd(g.antal_noder, INF);
    std::vector<int> föregångare(g.antal_noder, -1);
    std::priority_queue<std::pair<double,int>,
                        std::vector<std::pair<double,int>>,
                        std::greater<>> kö;

    // Startnoden är 0 m bort — lägg in den i kön
    avstånd[start] = 0;
    kö.push({0, start});

    while (!kö.empty()) {

        /*  double d = kö.top().first;
        int u    = kö.top().second;
        kö.pop();*/

        auto [d, u] = kö.top(); kö.pop();


        // Samma nod kan ligga i kön flera gånger med olika avstånd.
        // Om vi redan hittat en kortare väg — hoppa över den här.
        if (d > avstånd[u]) continue;

        // Kolla alla grannar till u
        for (int v = 0; v < g.antal_noder; v++)
            if (g.matris[u][v] != INF &&                        // finns kant u→v?
                avstånd[u] + g.matris[u][v] < avstånd[v]) {    // kortare väg hittad?
                avstånd[v] = avstånd[u] + g.matris[u][v];      // uppdatera avståndet
                föregångare[v] = u;                             // kom ihåg att vi kom via u
                kö.push({avstånd[v], v});                       // lägg in i kön
            }
    }

    if (avstånd[mål] == INF) { std::cout << "  Ingen väg finns!\n"; return; }
    std::cout << "  Avstånd: " << avstånd[mål] << " m\n  Väg:\n    ";

    // Rekonstruera vägen: följ föregångare bakåt från målet till starten,
    // sen vänd listan så den går från start → mål
    std::vector<int> väg;
    for (int nod = mål; nod != -1; nod = föregångare[nod])
        väg.push_back(nod);
    std::reverse(väg.begin(), väg.end());

    for (int i = 0; i < (int)väg.size(); i++) {
        if (i > 0) std::cout << " ->\n    ";
        std::cout << väg[i] << " (" << g.namn(väg[i]) << ")";
    }
    std::cout << "\n";
}
