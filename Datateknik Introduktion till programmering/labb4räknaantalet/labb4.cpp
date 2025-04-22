#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


std::string cleanWord(const std::string &word) {
    std::string cleaned;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    std::ifstream inputFile("hitchhikersguide.txt"); 
    if (!inputFile) {
        std::cerr << "Kunde inte öppna filen!" << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string word;

    
    while (inputFile >> word) {
        std::string cleaned = cleanWord(word);
        if (!cleaned.empty()) {
            wordCount[cleaned]++;
        }
    }

    inputFile.close(); 

    
    std::vector<std::pair<std::string, int>> wordVector(wordCount.begin(), wordCount.end());
    std::sort(wordVector.begin(), wordVector.end(),
              [](const auto &a, const auto &b) {
                  return b.second < a.second;
              });

    
    int n = 30; 
    std::cout << "De " << n << " mest förekommande orden är:\n";
    for (int i = 0; i < n && i < wordVector.size(); ++i) {
        std::cout << wordVector[i].first << ": " << wordVector[i].second << std::endl;
    }

    return 0;
}
