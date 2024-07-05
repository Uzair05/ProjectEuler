#include <iostream>
#include <vector>
#include <numeric>

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[]) {

    unsigned long long res{0};
    std::vector<unsigned> s(100);
    std::iota(s.begin(), s.end(),1);

    for(auto it{s.begin()}; (it+1)!=s.end(); it++){
        res += ((*it) * std::accumulate(it+1u, s.end(), 0ull));
    }

    res *= 2;
    std::cout << res << "\r\n";
    

    return 0;
}