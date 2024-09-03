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

    for(size_t i{0}; i < res.size(); i++){
        for(size_t j{i+1}; j < res.size(); j++){
            if (std::binary_search(res.begin(), res.end(), (res[i]+res[j]))){
                if (std::binary_search(res.begin(), res.end(), (res[j]-res[i]))){
                    D = (D < (res[j]-res[i])) ? D : (res[j]-res[i]);
                }
            }
        }
    }

    std::cout << D << "\n";

    return 0;
}