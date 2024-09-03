#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

void generate_pentagonals(std::vector<unsigned long>& dst, size_t range) {
    for (size_t i{dst.size() + 1}; i <= range; i++) {
        dst.push_back((i * ((3ul * i) - 1ul)) / 2ul);
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {

    std::vector<unsigned long> res{};
    unsigned long D{std::numeric_limits<unsigned long>::max()};

    generate_pentagonals(res, 10'000ul);

    for(auto i{res.begin()}; i!=res.end(); i++){
        for(auto j{std::next(i)}; j!=res.end(); j++){
            if (std::binary_search(std::next(j), res.end(), (*i + *j))){
                if (std::binary_search(res.begin(), std::next(j), (*j - *i))){
                    D = (D < (*j-*i)) ? D : (*j-*i);
                }
            }
        }
    }

    std::cout << D << "\n";

    return 0;
}