#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>

unsigned long long sum_of_fibbonaci(const unsigned long long n, auto fn) {
    unsigned long long a{}, b{1}, c{2};
    unsigned long long res{0};

    if (fn(b)) res += b;
    if (fn(c)) res += c;

    while ((b + c) < n) {
        a = b;
        b = c;
        c = (a + b);

        if (fn(c)) {
            res += c;
        }
    }
    return res;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::cout << sum_of_fibbonaci(4'000'000ull, [](const unsigned long long& a) {
        return a % 2ull == 0ull;
    }) << std::endl;

    return 0;
}
