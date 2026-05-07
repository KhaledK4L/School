#include "experiment.h"
#include "report.h"

#include <iostream>
#include <string>
#include <vector>

static void print_usage(const std::vector<AlgoCase>& all_cases) {
    std::cout << "Användning:\n";
    std::cout << "  ./sorting_lab all\n";
    std::cout << "  ./sorting_lab <id> [<id> ...]\n\n";
    std::cout << "Tillgängliga id:\n";

    for (const auto& algo_case : all_cases) {
        std::cout << "  " << algo_case.id << '\n';
    }
}

int main(int argc, char* argv[]) {
    std::vector<AlgoCase> all_cases = build_algo_cases();
    std::vector<AlgoCase> selected_cases;
    const int samples = 20;

    if (argc < 2) {
        print_usage(all_cases);
        return 0;
    }

    std::string first_arg = argv[1];

    if (first_arg == "all") {
        selected_cases = all_cases;
    } else {
        for (int i = 1; i < argc; ++i) {
            std::string wanted = argv[i];
            bool found = false;

            for (const auto& algo_case : all_cases) {
                if (algo_case.id == wanted) {
                    selected_cases.push_back(algo_case);
                    found = true;
                    break;
                }
            }

            if (!found) {
                std::cerr << "Okänt id: " << wanted << "\n";
            }
        }
    }

    if (selected_cases.empty()) {
        std::cerr << "Inga giltiga algoritmfall valdes.\n";
        return 1;
    }

    for (const auto& algo_case : selected_cases) {
        std::vector<int> sizes = default_sizes_for(algo_case);
        std::vector<MeasurementPoint> results = run_series(algo_case, sizes, samples);
        save_results(algo_case.id + ".dat", results);
    }

    std::cout << "Klart. Resultat sparade i mappen results/.\n";
    return 0;
}
