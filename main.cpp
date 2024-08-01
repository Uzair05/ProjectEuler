#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::fstream file;
    file.open("names.txt", std::ios::in);

    if (!file.is_open()) {
        std::cout << "File Open Error"
                  << "\n";
        return 1;
    }

    std::vector<std::string> names_list{};
    std::string buffer{};
    while (std::getline(file, buffer, ',')) {
        names_list.push_back(buffer);
    }

    file.close();
    std::sort(names_list.begin(), names_list.end());
    
    auto idx{0ul};
    std::vector<unsigned long> score{};
    std::transform(names_list.begin(), names_list.end(), std::back_inserter(score),
                   [&idx](const std::string& name) {
                       unsigned long res{0};
                       for (const char& c : name) {
                           if ((c >= 'A') && (c <= 'Z')) {
                               res += (static_cast<unsigned long>(c - 'A') + 1);
                           }
                       }
                       return (res * ++idx);
                   });
    // names_list.clear(); // slows down, buts saves on memory


    std::cout << std::accumulate(score.begin(), score.end(), 0ul) << "\n";
    std::cout << "correct answer:\t" << 871198282 << "\n";
    return 0;
}