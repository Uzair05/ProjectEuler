#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <future>

template <typename T>
void build_primes(std::vector<T>& primes, T n) {
    if (primes.size() < 2) {
        if (primes.empty()) {
            primes.push_back(2);
        }
        primes.push_back(3);
    }

    bool flg;
    for (auto i{primes.back() + 2}; i < n; i += 2) {
        flg = false;
        for (const auto& p : primes) {
            if (i % p == 0) {
                flg = true;
                break;
            }
        }

        if (!flg) {
            primes.push_back(i);
        }
    }
}

template <typename T>
size_t num_of_prime_divisors(std::vector<T>& primes, T n) {
    std::vector<T> factors{};

    for (const auto& p : primes) {
        if (n == 0) break;
        if (n % p == 0) {
            while (n > 0 && n % p == 0) {
                n /= p;
            }
            factors.push_back(p);
        }
    }

    return factors.size();
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> primes{};
    build_primes(primes, 12'000ull);



    for (auto i{647ull}; i < 1'000'000ull; i++) {
        if (num_of_prime_divisors(primes, i) == 4ul){
            if ((num_of_prime_divisors(primes, i+1ull) == 4ul) && 
                (num_of_prime_divisors(primes, i+2ull) == 4ul) && 
                (num_of_prime_divisors(primes, i+3ull) == 4ul)){
                    std::cout << "Answer is:\t" << i << "\n";
                    break;
                }
            
        }
    }

    return 0;
}