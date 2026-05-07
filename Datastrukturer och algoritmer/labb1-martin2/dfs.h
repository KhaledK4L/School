#pragma once
#include <stack>
#include "search.h"

std::vector<bool> dfs(const Graf& g, int startnod) {
    return sökning<std::stack<int>>(g, startnod);
}
