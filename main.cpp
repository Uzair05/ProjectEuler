#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>

size_t sum_of_multiples(const size_t n, const std::set<size_t>& base) {
    std::set<size_t> res{};
    for (size_t i{1}; i < n; i++) {
        if (std::any_of(base.cbegin(), base.cend(), [i](const size_t& b) { return i % b == 0; })) {
            res.insert(i);
        }
    }

    return std::accumulate(res.cbegin(), res.cend(), 0ul);
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::cout << sum_of_multiples(1000, std::set<size_t>{3, 5}) << std::endl;

    return 0;
}
