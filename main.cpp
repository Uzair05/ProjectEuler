#include <iostream>
#include <limits>
#include <map>

using ull = unsigned long long;

ull inc_denom(std::map<unsigned, std::map<unsigned, ull>>& m, unsigned depth, unsigned digit=1u, [[maybe_unused]] bool init=true) {
    
    if (depth == 1) return 1;
    if (digit == 9u) return 1;
    if (m.contains(depth) && m.at(depth).contains(digit)) return m.at(depth).at(digit);

    auto res{0ull};

    if (init){
        for(auto j{1u}; j<=9u; j++){
            for(auto i{j}; i <= 9u; i++){
                res += inc_denom(m, depth-1, i, false);
            }
        }
    }


    for(auto i{digit}; i <= 9u; i++){
        res += inc_denom(m, depth-1, i, false);
    }
    m.insert(std::pair(depth, std::map<unsigned, ull>{{digit, res}}));
    return res;
    
}



int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::map<unsigned, std::map<unsigned, ull>> m{};

    std::cout << inc_denom(m, 2) << "\n";
   
    
    return 0;
}