#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

bool is_prime_judgment(const unsigned long long n, const std::vector<unsigned long long>& primes) {
    return std::none_of(primes.begin(), primes.end(),
                        [&n](const auto& p) { return n % p == 0ull; });
}

std::vector<unsigned long long>& generate_primes(std::vector<unsigned long long>& primes,
                                                 size_t range) {
    if (primes.empty()) {
        primes.push_back(2ull);
        primes.push_back(3ull);
    }

    for (size_t idx{primes.back()}; idx < range; idx += 2) {
        if (std::none_of(primes.begin(), primes.end(),
                         [&idx](const auto& a) { return idx % a == 0; })) {
            primes.push_back(idx);
        }
    }

    return primes;
}

inline bool is_pandigital(unsigned long long n) {
    std::map<unsigned long long, unsigned long long> nums{};
    auto i{1ull};
    auto n_{n};
    while (n_ > 0) {
        n_ /= 10ull;
        nums.insert(std::pair<unsigned long long, unsigned long long>(i++, 0ull));
    }

    while (n > 0) {
        if (nums.contains(n % 10ull)) {
            nums.at(n % 10ull) += 1ull;
        }
        n /= 10ull;
    }

    return std::all_of(nums.begin(), nums.end(), [](const auto& kv) { return kv.second == 1; });
}

int main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[]) {
    std::vector<unsigned long long> primes{};
    generate_primes(primes, 32'000ul);

    for (auto idx{8'000'000ull}; idx > 0ull; idx--) {
        if (is_pandigital(idx)) {
            if (is_prime_judgment(idx, primes)) {
                std::cout << "Collection Pandigital Prime Found:\t" << idx << "\n";
                break;
            }
        }
    }

    return 0;
}