#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <numeric>


// Check if value is a match to ([A-Z, a-z]| |\n |,|\.)
bool is_valid_char(const unsigned long long& cu) {
    return (((cu >= static_cast<unsigned long long>('A')) &&
             (cu <= static_cast<unsigned long long>('Z'))) ||
            ((cu >= static_cast<unsigned long long>('a')) &&
             (cu <= static_cast<unsigned long long>('z')))) ||
           ((cu == static_cast<unsigned long long>(' ')) ||
            (cu == static_cast<unsigned long long>('\n')) ||
            (cu == static_cast<unsigned long long>(',')) ||
            (cu == static_cast<unsigned long long>('.')));
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::ifstream file;
    std::vector<unsigned long long> readings{};
    file.open("./0059_cipher.txt");


    // read all the values in the file
    if (!file.is_open()) {
        std::cout << "Cannot Open File\n";
        return 1;
    }
    for (std::string buffer{}; std::getline(file, buffer, ',');)
        readings.emplace_back(std::stoull(buffer));
    file.close();



    // we want to sort characters by frequency, but have it subdivided across its placement.
    // i.e. frequency of every third character etc.
    std::vector<std::pair<unsigned long long, unsigned>> counters_v[3]{{}, {}, {}};
    // Closed scope to ensure variable deletion and efficient garbage collection
    {
        std::map<unsigned long long, unsigned> counters[3]{{}, {}, {}};
        for (size_t i{0}; i < 3; i++) {
            auto& counter = counters[i];
            for (size_t idx{i}; idx < readings.size(); idx += 3) {
                if (counter.contains(readings[idx])) {
                    counter.at(readings[idx]) += 1u;
                } else {
                    counter.insert(std::pair<unsigned long long, unsigned>(readings[idx], 1u));
                }
            }
        }
        // free memory as soon as possible
        readings.clear();

        for (size_t i{0}; i < 3; i++) {
            auto& counter = counters[i];
            auto& counter_v = counters_v[i];
            for (const auto& [k, v] : counter) {
                counter_v.push_back(std::pair<unsigned long long, unsigned>(k, v));
            }
            counter.clear();
            std::sort(counter_v.begin(), counter_v.end(),
                      [](const std::pair<unsigned long long, unsigned>& a,
                         const std::pair<unsigned long long, unsigned>& b) {
                          return a.second > b.second;
                      });
        }
        
    }


    std::set<char> possible_solutions[3]{{}, {}, {}};
    auto total_sum{0ull};
    for(size_t i{0}; i<3; i++){
        const auto& counter_v = counters_v[i];
        auto& possible_solution = possible_solutions[i];

        for (char idx{'a'}; idx <= 'z'; idx++) {
            if (is_valid_char(counter_v[0].first ^ static_cast<unsigned long long>(idx)))
                possible_solution.insert(idx);
        }


        for(const char& idx_c: possible_solution){

            // Since we know we will fail if we try for testing all characters (all known acceptable casses doesn't exist)
            // we will only try on the 10 most frequest characters
            // Increase range incase we have more than 1 possible solution
            if(std::all_of(counter_v.begin(), counter_v.begin()+10, [&idx_c](const auto& v){
                return is_valid_char(
                    v.first ^ static_cast<unsigned long long>(idx_c)
                );
            })){
                total_sum += std::accumulate(counter_v.begin(), counter_v.end(), 0ull, [&idx_c](auto acc, const auto& pv){
                    return acc + ((pv.first^static_cast<unsigned long long>(idx_c)) * pv.second);
                });
            }
        }
    }
    

    std::cout << total_sum << "\n";


    return 0;
}