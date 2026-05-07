#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "MyObject.h"
#include "MyPrint.h"
#include "GreaterThanPredicate.h"
#include "MyBinOp.h"
#include "MyUnOp.h"

int main() {

    // 1) Skapa en array av MyObject (som "grunddata")
    MyObject arr[] = {
        {"Object1", 10.5},
        {"Object2", 20.3},
        {"Object3", 15.7}
    };

    // 2) Gör en vector av arrayen (kopierar in alla objekt i en vector)
    std::vector<MyObject> vec = createVectorFromArray(arr, 3);

    // 3) Skriv ut allt i vec (for_each kör MyPrint på varje objekt)
    //Används när du vill göra något med varje element i en container
    std::for_each(vec.begin(), vec.end(), MyPrint());

    // 4) Hitta första objektet där parameter > threshold
    double threshold = 18.0;
    //Används när du vill hitta första elementet som uppfyller ett villkor.
    auto it = std::find_if(vec.begin(), vec.end(), GreaterThanPredicate(threshold));
    if (it != vec.end()) {
        std::cout << "First object with parameter greater than " << threshold << ": ";
        MyPrint()(*it); // *it är objektet som hittades
    }

    // 5) adjacent_find hittar första paret av grannar som är lika
    //    (i ditt fall: operator== jämför bara name)
    //Används när du vill hitta två grannar bredvid varandra som är lika (eller uppfyller ett villkor).
    auto adjIt = std::adjacent_find(vec.begin(), vec.end());
    if (adjIt != vec.end()) {
        std::cout << "First object with the same name as the next one: ";
        MyPrint()(*adjIt);
    }

    // 6) equal: jämför array och vector element för element
    //    lambda säger hur vi jämför (här: a == b => jämför namn)
    //Används när du vill kolla om två sekvenser är lika element för element.
    bool areEqual = std::equal(
        std::begin(arr), std::end(arr),
        vec.begin(),
        [](const MyObject& a, const MyObject& b) { return a == b; }
    );

    std::cout << "Equality of array and vector: "
              << (areEqual ? "true" : "false") << std::endl;

    // 7) Beräkna medelvärdet (mean) av parameter i vec
    //    accumulate summerar alla parameter via MyBinOp
    //Används för att sammanfatta en lista till ett värde, oftast en summa.
    double mean = std::accumulate(vec.begin(), vec.end(), 0.0, MyBinOp()) / vec.size();

    // 8) Skapa en subsekvens (mönster) vi vill hitta i vec
    //    Vi sätter parameter = 0 här, men vi kommer matcha bara på name
    MyObject subArr[] = { {"Object2", 0}, {"Object3", 0} };
    auto subBegin = std::begin(subArr);
    auto subEnd   = std::end(subArr);

    // 9) search: leta efter subsekvensen i vec
    //  Vi använder comparator så vi matchar endast name,
    //    annars kommer den även jämföra parameter och då hittas den inte.
    //Används när du vill hitta en hel liten sekvens inuti en större sekvens.
    auto pos = std::search(vec.begin(), vec.end(), subBegin, subEnd,
        [](const MyObject& a, const MyObject& b) {
            return a.name == b.name; // matcha endast på namn
        }
    );

    if (pos != vec.end()) {
        std::cout << "Subsequence found: " << std::endl;

        // Skriv ut exakt så många element som subsekvensen har
        //Används när du vill göra något med varje element i en container.
        std::for_each(pos, pos + (subEnd - subBegin), MyPrint());
    } else {
        std::cout << "Subsequence not found." << std::endl;
    }

    // 10) Skapa v2: en vector<double> med bara parameter-värdena
    std::vector<double> v2(vec.size());
    //Används när du vill skapa nya värden från gamla värden.
    std::transform(vec.begin(), vec.end(), v2.begin(),
                   [](const MyObject& obj) { return obj.parameter; });

    // 11) Ändra varje värde i v2: (värde - mean)
    //     Detta "centrerar" datan runt 0
    std::transform(v2.begin(), v2.end(), v2.begin(), MyUnOp(mean));

    // 12) Sortera v2 i stigande ordning
    std::sort(v2.begin(), v2.end());

    // 13) Skriv ut resultatet
    std::cout << "Sorted v2 contents: ";
    for (const auto& value : v2) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return 0;
}
