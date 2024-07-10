#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void multiply_vectorized_number(std::vector<unsigned>& v, unsigned n) {
    unsigned carry{0};

    std::for_each(v.begin(), v.end(), [&carry, &n](auto& it) {
        carry = (it * n) + carry;
        it = carry % 10u;
        carry /= 10u;
    });

    while (carry > 0) {
        v.push_back(carry % 10u);
        carry /= 10u;
    }
}

void print_number(std::vector<unsigned>& number) {
    std::for_each(number.rbegin(), number.rend(), [](const auto& n) { std::cout << n; });
    std::cout << "\r\n";
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned> number{1};

    for (size_t i{0}; i < 1000; i++) {
        multiply_vectorized_number(number, 2u);
    }

    std::cout << std::accumulate(number.begin(), number.end(), 0u, [](auto acc, auto& n) {
        return acc + n;
    }) << "\r\n";

    return 0;
}