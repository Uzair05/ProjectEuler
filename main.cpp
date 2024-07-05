#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

void get_primes(std::vector<unsigned long long>& primes, const unsigned long long n) {
    if (!primes.empty()) primes.push_back(2u);

    for (unsigned long long i{*primes.rbegin() + 1}; i < (n + 1); i++) {
        if (!std::any_of(primes.cbegin(), primes.cend(),
                         [&i](const unsigned long long p) { return i % p == 0; })) {
            primes.push_back(i);
        }
    }
}

unsigned long long largest_prime_factor(unsigned long long n) {
    std::vector<unsigned long long> primes{2};
    const unsigned long long assumed_prime_threshold = 7000;
    get_primes(primes, assumed_prime_threshold);

    const auto is_prime = std::find(primes.cbegin(), primes.cend(), n);
    if (is_prime != primes.cend()) return *is_prime;

    unsigned long long greatest_prime{0};

    for (const auto& p : primes) {
        if (n % p == 0) {
            greatest_prime = p;

            while (n % p == 0) {
                n /= p;
            }
        }
        if (n == 0) break;
    }
    return greatest_prime;
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::cout << largest_prime_factor(600851475143ull) << std::endl;

    return 0;
}
