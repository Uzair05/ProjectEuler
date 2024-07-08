#include <algorithm>
#include <iostream>
#include <numeric>
#include <set>

template <typename T>
void get_primes(std::set<T>& primes, T n) {
    if (primes.empty()) primes.insert(static_cast<T>(2));

    for (auto i{(*primes.rbegin()) + 1}; i < n; i++) {
        if (!std::any_of(primes.cbegin(), primes.cend(),
                         [&i](const auto& p) { return i % p == 0; })) {
            primes.insert(i);
        }
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::set<unsigned long long> primes{};
    get_primes<unsigned long long>(primes, 2'000'000ull);

    std::cout << std::accumulate(primes.begin(), primes.end(), 0ull) << "\r\n";

    return 0;
}