#pragma once
#include <queue>
#include "search.h"

std::vector<bool> bfs(const Graf& g, int startnod) {
    return sökning<std::queue<int>>(g, startnod);
}
