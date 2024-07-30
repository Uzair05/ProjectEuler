#include <iostream>
#include <map>

using pair = std::pair<size_t, size_t>;
using map = std::map<pair, unsigned long long>;

unsigned long long walkDown(map& m, pair coor) {
    if (m.contains(coor)) return m[coor];
    auto& [x, y] = coor;  // decompose

    unsigned long long steps{0};
    if (x > 0 && y > 0) {
        steps = walkDown(m, pair(x - 1, y)) + walkDown(m, pair(x, y - 1));
    } else {
        if (x > 0) {
            steps = walkDown(m, pair(x - 1, y));
        } else {
            steps = walkDown(m, pair(x, y - 1));
        }
    }

    m.insert(std::pair<pair, unsigned long long>(coor, steps));
    return steps;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    map m{
            {pair(0, 0), 0ull},
            {pair(1, 0), 1ull},
            {pair(0, 1), 1ull},
        };
    std::cout << walkDown(m, pair(20,20));

    return 0;
}