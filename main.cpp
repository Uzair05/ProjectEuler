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

template <typename T>
unsigned comparable(T n) {
    std::vector<unsigned> res{};
    while (n > 0) {
        res.push_back(static_cast<unsigned>(n % 10));
        n /= 10;
    }

    std::sort(res.begin(), res.end());
    unsigned comb{0};
    for (const unsigned& r : res) {
        comb = (comb * 10) + r;
    }

    return comb;
}

void print_prime_permutation() {
    //! create vector or prime numbers 4 digits long
    std::vector<unsigned long long> primes{2};
    const unsigned long long assumed_prime_threshold = 9999;  // looking for 4 digits
    get_primes(primes, assumed_prime_threshold);

    std::sort(primes.begin(), primes.end());  // sort it just in case

    std::vector<unsigned long long> long_primes{};
    std::move(std::find_if(primes.cbegin(), primes.cend(), [](const auto& a) { return a > 999; }),
              primes.cend(), std::back_inserter(long_primes));
    primes.clear();

    //! find arithmetic progression
    for (auto i{long_primes.begin()}; i != long_primes.end(); i++) {
        for (auto j{i + 1}; j != long_primes.end(); j++) {
            unsigned long long difference{*j - *i};
            if (std::binary_search(j + 1, long_primes.end(), (*j + difference))) {
                //! find permutations
                auto a{comparable(*i)};
                if ((a == comparable(*j)) && (a == comparable(*j + difference))) {
                    std::cout << *i << ", " << *j << ", " << *j + difference << "\r\n";
                }
            }
        }
    }
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    print_prime_permutation();

    return 0;
}
